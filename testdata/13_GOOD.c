/*
 ============================================================================
 Name        : main_c.c
 Author      : ZOOOO
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Date Date;

struct Date {
	int d;
	int m;
	int y;
};

void swap(Date *p1, Date *p2) {
	Date *tmp;
	tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int get_elem(Date p, char e) {
	switch (e) {
	case 'd':
		return p.d;
		break;
	case 'm':
		return p.m;
		break;
	case 'y':
		return p.y;
		break;
	};
	return 0;
}

int mpow(int x, int y) {
	return (y) ? x * mpow(x, y - 1) : 1;
}

int key(int x, int r) {
	return x / mpow(10, r - 1) % 10;
}

Date *dist_sort(Date *p, int n, char e, int m, int r) {
	int i, k, count[m];
	Date *ret = (Date*) malloc(sizeof(Date) * n);
	for (i = 0; i < m; i++)
		count[i] = 0;
	for (i = 0; i < n; i++)
		count[key(get_elem(p[i], e), r)]++;
	for (i = 1; i < m; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		k = --count[key(get_elem(p[i], e), r)];
		ret[k] = p[i];
	}
	free(p);
	return ret;
}

void print_date(Date p) {
	printf("%d ", p.y);
	(p.m / 10) ? printf("%d ", p.m) : printf("0%d ", p.m);
	(p.d / 10) ? printf("%d\n", p.d) : printf("0%d\n", p.d);
}

int main() {
	int i, n;
	scanf("%d", &n);
	Date *arr = (Date*) malloc(sizeof(Date) * n);
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &arr[i].y, &arr[i].m, &arr[i].d);
	arr = dist_sort(arr, n, 'd', 10, 1);
	arr = dist_sort(arr, n, 'd', 10, 2);
	arr = dist_sort(arr, n, 'm', 10, 1);
	arr = dist_sort(arr, n, 'm', 10, 2);
	arr = dist_sort(arr, n, 'y', 10, 1);
	arr = dist_sort(arr, n, 'y', 10, 2);
	arr = dist_sort(arr, n, 'y', 10, 3);
	arr = dist_sort(arr, n, 'y', 10, 4);
	for (i = 0; i < n; i++)
		print_date(arr[i]);
	free(arr);
	return 0;
}