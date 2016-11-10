#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define next_int(a) scanf("%d", a)
#define print_int(a) printf("%d ", a)
#define next_word(a) scanf("%s", a)

typedef struct bor_el {
    char value;
    struct bor_el** next;
    size_t count_next;
    int count_uses; // Количество слов,
                    // в которые входит этот префикс,
                    // включая текущую букву
} bor_el;

bor_el* bor_el_add_after(bor_el* after, bor_el* el) {
    if(after->count_next == 0) {
        after->next = malloc(++after->count_next * sizeof(bor_el*));
    } else {
        after->next = realloc(after->next, ++after->count_next * sizeof(bor_el*));
    }
    after->next[after->count_next - 1] = el;
    return el;
}

bor_el* bor_el_add_char_after(bor_el* after, char a) {
    bor_el* new_bor = calloc(1, sizeof(bor_el));
    new_bor->value = a;
    new_bor->count_next = 0;
    new_bor->count_uses = 0;
    new_bor->next = NULL;
    return bor_el_add_after(after, new_bor);
}

void bor_el_free(bor_el* after) {
    for(int i = 0; i < after->count_next; i++) {
        bor_el_free(after->next[i]);
        //free(after->next[i]);
    }

    if(after->next != NULL) {
        free(after->next);
    }
    free(after);
}

typedef struct bor {
    bor_el* root_el;
} bor;

void bor_init(bor* b) {
    bor_el* new_root = calloc(1, sizeof(bor_el));
    new_root->count_next = 0;
    new_root->count_uses = 0;
    new_root->next = NULL;
    b->root_el = new_root;
}

void bor_free(bor* b) {
    bor_el_free(b->root_el);
}

char bor_empty(bor* b) {
    return b->root_el->count_uses == 0 && b->root_el->count_next == 0;
}

void bor_insert(bor* b, char* str, size_t str_len) {
    assert(str_len > 0);
    assert(str != NULL);

    // Дойдем до нужной существующей вершины.
    bor_el* cur = b->root_el;
    for(int str_i = 0; str_i < str_len; str_i++) {
        // Ищим следующую вершину
        bor_el* next = NULL;
        for(int i = 0; i < cur->count_next; i++) {
            if(cur->next[i]->value == str[str_i]) {
                // Нашли
                next = cur->next[i];
            }
        }

        if(next == NULL) {
            next = bor_el_add_char_after(cur, str[str_i]);
        }

        next->count_uses++;
        cur = next;
    }
}

int bor_prefix(bor* b, char* str, size_t str_len) {
    assert(str_len > 0);
    assert(str != NULL);

    // Дойдем до нужной существующей вершины.
    bor_el* cur = b->root_el;
    for(int str_i = 0; str_i < str_len; str_i++) {
        // Ищим следующую вершину
        bor_el* next = NULL;
        for(int i = 0; i < cur->count_next; i++) {
            if(cur->next[i]->value == str[str_i]) {
                // Нашли
                next = cur->next[i];
            }
        }

        if(next == NULL) {
            return 0;
        }

        cur = next;
    }

    return cur->count_uses;
}

void bor_delete(bor* b, char* str, size_t str_len) {
    assert(str_len > 0);
    assert(str != NULL);

    // Дойдем до нужной существующей вершины.
    bor_el* cur = b->root_el;
    for(int str_i = 0; str_i < str_len; str_i++) {
        // Ищим следующую вершину
        bor_el* next = NULL;
        for(int i = 0; i < cur->count_next; i++) {
            if(cur->next[i]->value == str[str_i]) {
                // Нашли
                next = cur->next[i];
            }
        }

        assert(next != NULL);

        next->count_uses--;
        cur = next;
    }
}

//////////////////////////////////////////////////////////////////

#define COMMAND_BUF_SIZE 20
#define ARG_BUF_SIZE 100

void operation_process(bor* b) {
    char command[COMMAND_BUF_SIZE];
    next_word(command);
    if(!strcmp(command, "INSERT")) {
        char tmp_str[ARG_BUF_SIZE];
        next_word(tmp_str);
        bor_insert(b, tmp_str, strnlen(tmp_str, ARG_BUF_SIZE));
    } else if(!strcmp(command, "DELETE")) {
        char tmp_str[ARG_BUF_SIZE];
        next_word(tmp_str);
        bor_delete(b, tmp_str, strnlen(tmp_str, ARG_BUF_SIZE));
    } else if(!strcmp(command, "PREFIX")) {
        char tmp_str[ARG_BUF_SIZE];
        next_word(tmp_str);
        print_int(bor_prefix(b, tmp_str, strnlen(tmp_str, ARG_BUF_SIZE)));
    } else {
        assert(0);
    }
}

int main() {
    int len;
    next_int(&len);

    bor b;
    bor_init(&b);

    for(int i = 0; i < len; i++) {
        operation_process(&b);
    };

    bor_free(&b);
    return 0;
}
