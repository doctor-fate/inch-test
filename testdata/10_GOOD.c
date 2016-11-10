#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ABS(X) ((X) < 0 ? -(X) : (X))

int n, *components;

typedef struct {
	int data[30], size;
} array;

typedef struct {
	struct {
		array first, second;
	} data[30];
	int size;
} teams;

void find(array *dst, int x) {
	int i;
	for (i = dst->size = 0; i < n; i++) {
		if (components[i] == x) {
			dst->data[dst->size++] = i;
		}
	}
}

void dfs(char(*G)[n], char *used, int v, int comp) {
	int i;
	components[v] = comp, used[v] = 1;
	for (i = 0; i < n; i++) {
		if (G[v][i] == '+' && !used[i]) {
			dfs(G, used, i, -comp);
		} else if (G[v][i] == '+' && components[i] == components[v]) {
			printf("No solution\n");
			free(G), free(used), free(components);
			exit(0);
		}
	}
}

void makeTeams(array *result, array *buffer, teams t, char *used, int *top) {
	int i, w = 0;
	for (i = 0; i < t.size; i++) {
		if (!used[i]) {
			used[i] = w = 1;
			array f, s; 
			char usedClone[n];
			memcpy(usedClone, used, n * sizeof(char));
			memcpy(f.data, buffer->data, buffer->size * sizeof(int)), memcpy(s.data, buffer->data, buffer->size * sizeof(int));
			memcpy(f.data + buffer->size, t.data[i].first.data, t.data[i].first.size * sizeof(int));
			memcpy(s.data + buffer->size, t.data[i].second.data, t.data[i].second.size * sizeof(int));
			f.size = t.data[i].first.size + buffer->size, s.size = t.data[i].second.size + buffer->size;
			makeTeams(result, &f, t, usedClone, top);
			makeTeams(result, &s, t, used, top);
		}
	}
	if (!w && buffer->size > 0) {
		result[*top].size = buffer->size;
		memcpy(result[(*top)++].data, buffer->data, buffer->size * sizeof(int));
	}
}

int compare(const void *a, const void *b) {
	array *x = (array*) a, *y = (array*) b;
	if (x->size == y->size) {
		int i;
		for (i = 0; i < x->size && x->data[i] == y->data[i]; i++) { }
		return x->data[i] - y->data[i];
	} else {
		return ABS((n >> 1) - x->size) - ABS((n >> 1) - y->size);
	}
}

int comp(const void *a, const void *b) {
	return *((int*) a) - *((int*) b);
}

int main() {
	int f = 1, i, j, x = 0;
	scanf("%d\n", &n);
	char(*G)[n] = malloc(n * sizeof(char[n])), *used = calloc(n, sizeof(char));
	components = malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			G[i][j] = getchar(), getchar();
		}
	}
	for (i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(G, used, i, f++);
		}
	}
	teams t;
	for (i = 1, t.size = 0; i < f; t.size++, i++) {
		find(&t.data[t.size].first, i);
		find(&t.data[t.size].second, -i);
	}
	array buffer, *result = malloc(20000 * sizeof(array));
	memset(used, 0, n), buffer.size = 0;
	makeTeams(result, &buffer, t, used, &x);
	qsort(result, x, sizeof(array), compare);
	qsort(result[0].data, result[0].size, sizeof(int), comp);
	for (i = 0; i < result[0].size; i++) {
		printf("%d ", result[0].data[i] + 1);
	}
	free(G), free(used), free(components), free(result);
	return 0;
}