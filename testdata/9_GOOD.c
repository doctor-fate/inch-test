#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 10000

struct List {
	int k, v;
	struct List *next;
};

struct List* InitList(int key, int val) {
	struct List *x = calloc(1, sizeof(struct List));
	x->k = key;
	x->v = key ? val - 1 : val;
	x->next = NULL;
	return x;
}

struct List* Search(struct List *list, int key) {
	struct List *x = list;
	while (x != NULL && x->k != key)
		x = x->next;
	return x;
}

void InsertBeforeHead(struct List *list, int key) {
	struct List *x = InitList(key, 1);
	x->next = list->next;
	list->next = x;
}

void free_list(struct List *list) {
	struct List *x;
	for (; list != NULL; list = x) {
		x = list->next;
		free(list);
	}
}

int main() {
	int n, i, a, x, res;
	scanf("%d", &n);
	struct List **arr = calloc(SIZE, sizeof(struct List*)), *y;
	for (i = 0; i < SIZE; ++i)
		arr[i] = InitList(INT_MIN, 1);
	for (i = x = 0; i < n; ++i) {
		scanf("%d", &a);
		x ^= a;
		y = Search(arr[abs(x) % SIZE], x);
		y != NULL ? y->v++ : InsertBeforeHead(arr[abs(x) % SIZE], x);
	}
	for (i = res = 0; i < SIZE; ++i)
		for (y = arr[i]->next; y != NULL; y = y->next)
			res += (y->v * (y->v + 1)) / 2;
	printf("%d\n", res);
	for (i = 0; i < SIZE; ++i)
		free_list(arr[i]);
	free(arr);
	return 0;
}