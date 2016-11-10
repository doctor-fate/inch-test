#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bor {
	int v;
	struct bor *parent;
	struct bor *arcs[26];
};
struct pair {
	struct bor *x;
	int i;
};
int count;
int e = 0;
struct bor *init(struct bor *t) {
	t = (struct bor*)malloc(1 * sizeof(struct bor));
	t->v = -1;
	int i;
	for (i = 0; i < 26; ++i)
		t->arcs[i] = NULL;
	return t;
}
struct pair descend(struct bor *t, char *k) {
	struct pair z;
	z.x = t, z.i = 0;
	while (z.i < strlen(k)) {
		struct bor *y = z.x->arcs[k[z.i] - 97];
		if (y == NULL) break;
		z.x = y;
		++z.i;
	}
	return z;
}
int mapsearch(struct bor *t, char *k) {
	struct pair z = descend(t, k);
	if (z.i == strlen(k) && z.x->v != -1) return 1;
	else return 0;
}
/*int lookup(struct bor *t, char *k)
{
	struct pair z=descend(t,k);
	return z.x->v;
}*/
void insert(struct bor *t, char *k, int v) {
	struct pair z = descend(t, k);
	while (z.i < strlen(k)) {
		struct bor *y = init(y);
		z.x->arcs[k[z.i] - 97] = y;
		y->parent = z.x;
		z.x = y;
		++z.i;
	}
	z.x->v = v;
	++e;
}
void delete(struct bor *t, char *k) {
	struct pair z = descend(t, k);
	z.x->v = -1;
	int j, i;
	while (e > 1 && z.x->parent != NULL && z.x->v == -1) {
		j = 0;
		while (j < 26 && z.x->arcs[j] == NULL)
			++j;
		if (j < 26) break;
		struct bor *y = z.x->parent;
		--z.i;
		y->arcs[k[z.i] - 97] = NULL;
		for (i = 0; i < 26; ++i)
			z.x->arcs[i] = NULL;
		free(z.x);
		z.x = y;
	}
	if (e == 1) {
		for (i = 0; i < 26; ++i)
			z.x->arcs[i] = NULL;
		//free(z.x);
		//z.x=init(z.x);
	}
	--e;

}

void prefix(struct bor *x, struct pair z) {

	int i;
	for (i = 0; i < 26; ++i) {

		if (x->arcs[i] != NULL) {
			if (x->arcs[i]->v != -1) {
				++count;
			}
			prefix(x->arcs[i], z);
		}
	}

}
void free_bor(struct bor *x) {
	int i;
	for (i = 0; i < 26; ++i) {
		if (x->arcs[i] != NULL)
			free_bor(x->arcs[i]);
	}
	free(x);
}
int main() {
	int n, i, j;
	char com[10], k[100000];
	struct bor *t = init(t);
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s %s", com, k);
		if (com[0] == 'I') {
			if (mapsearch(t, k) == 0) {
				insert(t, k, strlen(k));
			}
		} else if (com[0] == 'D')
			delete(t, k);
		else {
			count = 0;
			struct pair z = descend(t, k);
			if (z.i == strlen(k)) {
				prefix(z.x, z);
				if (z.x->v != -1)// && count==0)
					++count;
			}
			printf("%d\n", count);
		}

	}
	free_bor(t);

}

