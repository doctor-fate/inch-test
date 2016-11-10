#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100000

typedef struct TrieNode {
	char *v;
	int pref;
	struct TrieNode *parent;
	struct TrieNode **arcs;
}TrieNode;

typedef struct Trie {
	TrieNode *root;
}Trie;

typedef struct Info {
	TrieNode *x;
	int i;
}Info;

TrieNode *new_tnode() {

	TrieNode *nnode = (TrieNode*) malloc(sizeof(TrieNode));
	nnode->v = NULL;
	nnode->pref = 0;
	nnode->parent = NULL;
	nnode->arcs = (TrieNode**) malloc(26 * sizeof(TrieNode*));
	int i;
	for (i = 0; i < 26; i++) nnode->arcs[i] = NULL;

	return nnode;
}

Trie *init_trie() {
	Trie *t1 = (Trie*) malloc(sizeof(Trie));
	t1->root = new_tnode();
	return t1;
}

void delete_trie_rec(TrieNode *tn) {
	int i;
	for (i = 0; i < 26; i++) {
		if (tn->arcs[i] != NULL) delete_trie_rec(tn->arcs[i]);
	}
	free(tn->arcs);
	free(tn);
}

void delete_trie(Trie *t1) {
	delete_trie_rec(t1->root);
	free(t1);
}

Info descend(Trie *t1, char *key, int len, int op) {
	Info desc;
	desc.x = t1->root;
	desc.i = 0;
	TrieNode *y;
	while (desc.i < len) {
		y = desc.x->arcs[key[desc.i] - 97];
		if (y == NULL) return desc;
		y->pref += op;
		desc.x = y;
		desc.i++;
	}
	return desc;
}

void insert(Trie *t1, char *key, int len) {
	TrieNode *y;
	Info desc = descend(t1, key, len, 1);
	if (desc.i != len || desc.x->v == NULL) {
		while (desc.i < len) {
			y = new_tnode();
			y->pref++;
			desc.x->arcs[key[desc.i] - 97] = y;
			y->parent = desc.x;
			desc.x = y;
			desc.i++;
		}
		desc.x->v = key;
	} else descend(t1, key, len, -1);
}

void delete(Trie *t1, char *key, int len) {
	Info desc = descend(t1, key, len, -1);
	desc.x->v = NULL;
	TrieNode *y;
	int j;
	while (desc.x->parent != NULL && desc.x->v == NULL) {
		j = 0;
		while (j < 26 && desc.x->arcs[j] == NULL) j++;
		if (j < 26) break;
		y = desc.x->parent;
		desc.i--;
		y->arcs[key[desc.i] - 97] = NULL;
		free(desc.x->arcs);
		free(desc.x);
		desc.x = y;
	}
}

int prefix(Trie *t1, char *key, int len) {
	Info desc = descend(t1, key, len, 0);
	if (desc.i < len) return 0;
	else return desc.x->pref;
}

int main() {

	char cmd[10];
	char *s = (char*) malloc(MAXLEN * sizeof(char));
	int n, l;
	scanf("%d", &n);

	Trie *t1 = init_trie();

	int i;
	for (i = 0; i < n; i++) {
		scanf("%s ", cmd);
		scanf("%s", s);
		l = strnlen(s, MAXLEN);
		switch (cmd[0]) {
		case 'I':
			insert(t1, s, l);
			break;
		case 'P':
			printf("%d\n", prefix(t1, s, l));
			break;
		case 'D':
			delete(t1, s, l);
			break;
		}
	}

	free(s);
	delete_trie(t1);

	return 0;
}