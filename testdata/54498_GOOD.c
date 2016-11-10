#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26
#define INSERT 6952341587418
#define PREFIX 6952619776531
#define DELETE 6952134985656
#define MILLL  100099
#define constA 97

typedef struct Trie trie;
typedef struct Pair pair;


void freeTrie(trie *base) {
    int i = N;
    while (i--) {
        if (base->arcs[i] != 0) {
            freeTrie(base->arcs[i]);
        }
    }
    free(base->arcs);
    free(base);
}

//created by Benji

struct Trie {
    trie *parent, **arcs;
    int prefix, V;
};

struct Pair {
    trie *x;
    int i;
};

trie *InitTrie() {
    trie *base = calloc(1, sizeof(trie));
    base->arcs = calloc(N, sizeof(trie *));
    base->V = base->prefix = 0;
    base->parent = NULL;
    return base;
}

int mover(int a) {
    return a - constA;
}

pair Descend(trie *t, char *str) {
    trie *x, *y;
    int i, len_k;
    for (x = t, i = 0, len_str = strlen(str); i < len_str; x = y) {
        y = x->arcs[mover(str[i])];
        if (y == NULL) {
            break;
        }
        i++;
        y->prefix++;
    }
    return (pair) { x, i };
}

int hash(char *str) {
    unsigned long tmp = 5381;
    int c;
    while (c = *str++) {
        tmp = ((tmp << 5) + tmp) + c;
    }

    return tmp;
}

trie *Insert(trie *base, char *k) {
    pair A = Descend(base, k);
    trie *x = A.x, *y, *tmp;

    for (int i = A.i, len_k = strlen(k); i < len_k; i++) {
        y = InitTrie();
        tmp = y;
        x->arcs[mover(k[i])] = y;
        y->parent = x;
        x = y;
        x->prefix++;
    }
    if (x->V > 1) {
        x->V++;
        for (x->V = 0; x->parent != NULL; x = x->parent) {
            x->prefix--;
        }
    }
    return tmp;
}

int Prefix(trie *base, char *k) {
    trie *x = base;
    for (int i = 0, len_k = strlen(k); i < len_k; x = x->arcs[mover(k[i]), i++]) {
        if (x->arcs[mover(k[i])] == NULL) {
            return 0;
        }
    }
    return x->prefix;
}

void Delete(trie *t, char *k) {
    trie *y;
    for (int i = 0, len_k = strlen(k); i < len_k; t = y, i++) {
        y = t->arcs[mover(k[i])];
        if (y == NULL) {
            break;
        }
        y->prefix--;
    }
}


int main(void) {
    int i, r = 0;
    char *str = calloc(N, sizeof(char));
    char *w = calloc(MILLL, sizeof(char));
    trie *p = InitTrie();
    scanf("%d", &i);
    for (int k = 0; k < i; k++) {
        scanf("%s%s", str, Q);
        switch (hash(str)) {
        case PREFIX:
            printf("%d\n", Prefix(p, str));
            break;
        default:
            return 1;
        }
    }
    freeTrie(p);
    free(str);
    free(w);
    return 0;
}
//time start 07:00
