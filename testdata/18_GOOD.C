/*
 * bridge_count.c
 *
 *  Created on: 15 марта 2015 г.
 *      Author: root
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VECTOR_OF(TYPE, NAME) \
		struct Vector##NAME {\
			int size;\
			int capacity;\
			TYPE *arr;\
		};\
		typedef struct Vector##NAME Vector##NAME;\
		Vector##NAME* makeVector##NAME(int size) {\
			Vector##NAME *p = calloc(1, sizeof(Vector##NAME));\
			if(!p) exit(1);\
			p->arr = malloc(size * sizeof(TYPE));\
			if(!p->arr) exit(1);\
			p->capacity = size;\
			return p;\
		}\
		void freeVector##NAME(Vector##NAME *p) {\
			free(p->arr);\
			free(p);\
		}\

VECTOR_OF(int, I)
VECTOR_OF(VectorI*, Ip)
VECTOR_OF(char, C)

struct Queue {
	int head;
	int tail;
	int *arr;
};
typedef struct Queue Queue;

Queue *queueInit(int size) {
	Queue *p = calloc(1, sizeof(Queue));
	p->arr = malloc(size * sizeof(int));
	return p;
}
void queueFree(Queue *p) {
	free(p->arr);
	free(p);
}
int queueEmpty(Queue *p) {
	return p->head == p->tail;
}
int dequeue(Queue *p) {
	int ret = p->arr[p->tail++];
	if (p->tail == p->head)
		p->tail = p->head = 0;
	return ret;
}
void enqueue(Queue *p, int v) {
	p->arr[p->head++] = v;
}

void dfs(VectorIp *g, VectorC *used, int v, VectorI *par, Queue *q) {
	int i;
	used->arr[v] = 1;
	enqueue(q, v);
	for (i = 0; i < g->arr[v]->size; i++)
		if (!used->arr[g->arr[v]->arr[i]]) {
			par->arr[g->arr[v]->arr[i]] = v;
			dfs(g, used, g->arr[v]->arr[i], par, q);
		}
}

void visitVertex(VectorIp *g, int v, VectorI *par, VectorI* comp, int component) {
	int i;
	comp->arr[v] = component;
	for (i = 0; i < g->arr[v]->size; i++)
		if (comp->arr[g->arr[v]->arr[i]] == -1
				&& par->arr[g->arr[v]->arr[i]] != v)
			visitVertex(g, g->arr[v]->arr[i], par, comp, component);
}

int dfs2(VectorIp *g, VectorI *comp, VectorI *par, Queue *q, int component) {
	while (!queueEmpty(q)) {
		int v = dequeue(q);
		if (comp->arr[v] == -1)
			visitVertex(g, v, par, comp, component++);
	}
	return component;
}


int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	VectorIp *g = makeVectorIp(n);
	int i;
	for (i = 0; i < n; g->arr[i++] = makeVectorI(50))
		;
	for (i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g->arr[x]->arr[g->arr[x]->size++] = y;
		g->arr[y]->arr[g->arr[y]->size++] = x;
	}
	int component = 1;
	VectorI *parents = makeVectorI(n);
	VectorI *comp = makeVectorI(n);
	VectorC *used = makeVectorC(n);
	for (i = 0; i < n; i++) {
		used->arr[i] = 0;
		comp->arr[i] = -1;
		parents->arr[i] = -1;
	}
	Queue *q = queueInit(100000);
	for (i = 0; i < n; i++) {
		if (!used->arr[i]) {
			component--;
			dfs(g, used, i, parents, q);
		}
		component = dfs2(g, comp, parents, q, component);
	}
	printf("%d", component - 1);
	freeVectorI(comp);
	freeVectorI(parents);
	freeVectorC(used);
	for (i = 0; i < n; freeVectorI(g->arr[i++]))
		;
	freeVectorIp(g);
	queueFree(q);
	return 0;
}

