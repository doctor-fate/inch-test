/*
 ============================================================================
 Name        : main_c.c
 Author      : ZOOOO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>

int *array;

int compare(unsigned long i, unsigned long j) {
	if (i <= j) {
		printf("COMPARE %d %d\n", i, j);
	} else {
		printf("COMPARE %d %d\n", j, i);
	}

	if (array[i] == array[j])
		return 0;
	return array[i] < array[j] ? -1 : 1;
}

void swap(unsigned long i, unsigned long j) {
	if (i <= j) {
		printf("SWAP %d %d\n", i, j);
	} else {
		printf("SWAP %d %d\n", j, i);
	}

	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}

void shellsort(unsigned long nel,
		int (*compare)(unsigned long i, unsigned long j),
		void (*swap)(unsigned long i, unsigned long j)) {
	unsigned long f1 = 0, f2 = 1, tmp;
	long i, k;
	while(f1 <= nel) {
		tmp = f2;
		f2 += f1;
		f1 = tmp;
	}
	i = f1;
	while(i >= 1) {
		for(; i < nel; i++)
			for(k = i; (k >= f1) && (compare(k - f1, k) == 1); k -= f1)
				swap(k, k - f1);
		tmp = f1;
		f1 = f2 - f1;
		f2 = tmp;
		i = f1;
		if(f1 == f2) break;
	}
}

int main(int argc, char **argv) {
	int i, n;
	scanf("%d", &n);

	array = (int*) malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", array + i);

	shellsort(n, compare, swap);
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");

	free(array);
	return 0;
}