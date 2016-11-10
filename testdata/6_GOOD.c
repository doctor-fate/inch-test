#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 100

int count(void *base) {
	int j, k;
	char *am = base;
	k = 0;
	j = 0;
	do
		if (am[j] == 'a')
			++k;
	while (am[j++]);
	return k;
}

void swap(char *A, int i, int j, int width) {
	char S[L];
	strcpy(S, A + i * width);
	strcpy(A + i * width, A + j * width);
	strcpy(A + j * width, S);
}

int compare(const void *a, const void *b) {
	return count((char*) a) > count((char*) b) ? 1 : -1;
}

void heapify(char *A, int i, int nel, int width) {
	int child;
	int max;
	char cur[L];
	strcpy(cur, A + i * width);
	max = i;
	for (;;) {
		child = 2 * i + 1;
		if (child < nel && compare(A + child * width, cur) == 1)
			max = child;
		++child;
		if (child < nel && compare(A + child * width, A + max * width) == 1)
			max = child;
		if (max == i)
			break;
		swap(A, i, max, width);
		i = max;
	}
}

void hsort(void *base, size_t nel, size_t width,
		   int(*compare)(const void *a, const void *b)) {
	int i;
	char *am = base;
	for (i = nel / 2 - 1; i >= 0; --i)
		heapify(am, i, nel, width);
	while (nel-- > 1) {
		swap(am, 0, nel, width);
		heapify(am, 0, nel, width);
	}
}

int main(int argc, char **argv) {
	int i, n;
	n = 0;
	scanf("%d ", &n);
	char A[n][L];
	for (i = 0; i < n; ++i)
		gets(A[i]);
	hsort(A, n, L, compare);
	for (i = 0; i < n; ++i)
		printf("\n%s", A[i]);
	return 0;
}