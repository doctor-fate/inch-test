#include <stdio.h>
#include <stdlib.h>

int *array;

int compare(unsigned long i, unsigned long j) {
	if (array[i] == array[j]) return 0;
	return (array[i] < array[j]) ? -1 : 1;
}

void swap(unsigned long i, unsigned long j) {
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}


void selsort(int compare(unsigned long i, unsigned long j),
			 void swap(unsigned long i, unsigned long j),
			 int n) {
	int i, k;
	int j = n - 1;
	while (j > 0) {
		k = j;
		i = j - 1;
		while (i >= 0) {
			if (compare(i, k) == 1) {
				k = i;
			}
			i--;
		}
		swap(j, k);
		j--;
	}
}


int part(int compare(unsigned long i, unsigned long j),
		 void swap(unsigned long i, unsigned long j),
		 int low,
		 int high) {
	int i = low;
	int j = low;
	while (j < high) {
		if (compare(high, j) == 1) {
			swap(i, j);
			i++;
		}
		j++;
	}
	swap(high, i);
	return i;
}


void qsortrec(int compare(unsigned long i, unsigned long j),
			  int low,
			  int high,
			  int m) {
	int q;
	while ((high - low) > m) {
		q = part(compare, swap, low, high);
		if ((q - low) > (high - q)) {
			qsortrec(compare, q + 1, high, m);
			high = q - 1;
		} else {
			qsortrec(compare, low, q - 1, m);
			low = q + 1;
		}
	}
	selsort(compare, swap, high - low);
}

void mqsort(int compare(unsigned long i, unsigned long j),
			int n,
			int m) {
	int j = 0;
	while (j < n) {
		qsortrec(compare, 0, j, m);
		++j;
	}
}

int main() {
	int n, m, i;
	scanf("%d ", &n);
	scanf("%d ", &m);
	array = (int*) malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	mqsort(compare, n, m);
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	free(array);
	return 0;
}