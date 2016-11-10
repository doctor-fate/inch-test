#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int v, u;
    double length;
} road;

struct Node {
    int x, y, depth;
    struct Node *parent;
};

int compare(const void *a, const void *b) {
    road *x = (road*) a, *y = (road*) b;
    return x->length > y->length ? 1 : -1;
}

struct Node* find(struct Node *x) {
    if (x->parent != x) {
        x->parent = find(x->parent);
    }
    return x->parent;
}

void join(struct Node *a, struct Node *b) {
    struct Node *x = find(a), *y = find(b);
    if (x->depth < y->depth) {
        x->parent = y;
    } else {
        y->parent = x;
        if (x->depth == y->depth && x != y) {
            x->depth++;
        }
    }
}

int main() {
    int n, i, j, size = 0;
    double result = 0;
    scanf("%d", &n);
    struct Node **vertexes = malloc(n * sizeof(struct Node*));
    for (i = 0; i < n; vertexes[i]->depth = 0, i++) {
        vertexes[i] = malloc(sizeof(struct Node));
        vertexes[i]->parent = vertexes[i];
        scanf("%d %d", &vertexes[i]->x, &vertexes[i]->y);
    }
    road *g = malloc(n * (n - 1) / 2 * sizeof(road));
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            double l = sqrt(pow(vertexes[i]->x - vertexes[j]->x, 2) + pow(vertexes[i]->y - vertexes[j]->y, 2));
            g[size++] = (road) {i, j, l};
        }
    }
    qsort(g, size, sizeof(road), compare);
    for (i = 0; i < size; i++) {
        int x = g[i].v, y = g[i].u;
        if (find(vertexes[x]) != find(vertexes[y])) {
            result += g[i].length;
            join(vertexes[x], vertexes[y]);
        }
    }
    printf("%.2lf", result);
    for (i = 0; i < n; i++) {
        free(vertexes[i]);
    }
    free(vertexes), free(g);
}