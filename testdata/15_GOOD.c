/*
 * comp_set.c
 *
 *  Created on: 14 ????? 2015 ?.
 *      Author: root
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EDGES 100

struct Vector {
    int size;
	int capacity;
	int *arr;
};

typedef struct Vector Vector;

Vector* makeVector(int size) {
	Vector *p = calloc(size, sizeof(Vector));
	p->arr = malloc(size * sizeof(int));
	p->capacity = size;
	return p;
}
void freeVector(Vector *p) {
	free(p->arr);
	free(p);
}

struct Edge {
	int x;
	int y;
};

typedef struct Edge Edge;

void dfs(Vector **v, char *used, int n) {
	int i;
	used[n] = 1;
	for(i = 0; i < v[n]->size; i++)
		if(!used[v[n]->arr[i]])
			dfs(v, used, v[n]->arr[i]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Vector **v = malloc(sizeof(Vector*) * n);
	char *used = calloc(n, sizeof(char));
	int i;
	for(i = 0; i < n; i++)
		v[i] = makeVector(MAX_EDGES);
	for(i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x]->arr[v[x]->size++] = y;
		v[y]->arr[v[y]->size++] = x;
	}
	int cmps = 0;
	for(i = 0; i < n; i++)
		if(!used[i]) {
			dfs(v, used, i);
			cmps++;
		}
	printf("%d", cmps);
	for(i = 0; i < n; i++)
		freeVector(v[i]);
	free(v);
	free(used);
	return 0;
}