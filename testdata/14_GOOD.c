/*
 * main.c
 *
 *  Created on: 30 ???. 2014 ?.
 *      Author: root
 */
//sed -i 's/\([[:digit:]]\),\([[:digit:]]\)/\1\.\2/g'
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846	/* pi */
#define M_PI_2		1.57079632679489661923
#define OFFSET 0
//in 5 1 7 rec0.csv 10000000 50000001 625000


#include <math.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include "funcs.h"
#include "stack.h"
#include "integralrec.h"

//#define N_THREADS 5
/*
 fprintf(_f, "%ld; %.15G; %.15G;\n", _n, _res - _V0, _me);
 fprintf(_f, "%ld; %.15G; %.15G;\n", _n, (_res - _V0) / _V0, _me / n_V0);
 fprintf(_f, "%ld; %.15G;\n", _n, _res - _V0 - _me);
 */


double Integral0(double Left, double Right, long N, double (*func)(double)) {
	Limit tmp, top;
	top.L = Left;
	top.R = Right;
	Stack *s1 = Stack_init(N);
	Stack *s2 = Stack_init(N);
	Stack *sw = 0;
	Stack_push(s1, top);
	while (N != 1) {
		while (!Stack_empty(s1)) {
			top = Stack_pop(s1);
			tmp.L = top.L;
			tmp.R = (top.L + top.R) / 2;
			Stack_push(s2, tmp);
			tmp.R = top.R;
			tmp.L = (top.L + top.R) / 2;
			Stack_push(s2, tmp);
		}
		sw = s1;
		s1 = s2;
		s2 = sw;
		N /= 2;
	}
	double res = 0;
	while (!Stack_empty(s1)) {
		top = Stack_pop(s1);
		res += (func(top.L) + func(top.R)) * (top.R - top.L) / 2;
	}
	Stack_free(s1);
	Stack_free(s2);
	return res;
}

double Integral1(double Left, double Right, long N, double (*func)(double)) {
	double x, dx, res = 0.0;
	dx = (Right - Left) / N;
	for (x = Left; x < Right; x += dx)
		res += (func(x) + func(x + dx));
	res *= dx / 2;
	return res;
}

double Integral2(double Left, double Right, long N, double (*func)(double)) {
	double x, dx, res = 0.0;
	dx = (Right - Left) / N;
	long int i = 0;
	for (x = Left; x + dx <= Right; x += dx, i++)
		res += (func(x) + func(x + dx));
	res *= dx / 2;
	if (x < Right) {
		printf("if ");
		i++;
		res += (func(x) + func(Right)) * (Right - x) / 2;
	}
	printf("%ld %ld\n", N, i);
	return res;
}

double Integral3(double Left, double Right, long N, double (*func)(double)) {
	double x, dx;
	long double res = 0.0;
	dx = (Right - Left) / N;
	long int i;
	x = Left;
	for (i = 0; i < N; i++) {
		res += func(x + dx * i) + func(x + dx * (i + 1));
	}
	res *= dx / 2;
	return res;
}

double Integral4(double Left, double Right, long N, double (*func)(double)) {
	double x, dx;
	long double res = 0;
	dx = (Right - Left) / N;
	for (x = Left; x < Right; x += dx)
		res += (func(x) + func(x + dx));
	res *= dx / 2;
	return res;
}

double Integral5(double Left, double Right, long N, double (*func)(double)) {
	double x, dx;
	long double res = 0;
	long int i;
	dx = (Right - Left) / N;
	for (x = Left, i = -1; i < N; x += dx, i++)
		res += (func(x) + func(x + dx));
	res *= dx / 2;
	return res;
}

double Integral6(double Left, double Right, long N, double (*func)(double)) {
	double x, dx, res = 0.0;
	dx = (Right - Left) / N;
	long int i;
	x = Left;
	res += (func(Left) + func(Right)) / 2;
	for (i = 1; i < N; i++) {
		res += func(x + dx * i);
	}
	res *= dx;
	return res;
}

double Integral7(double Left, double Right, long N, double (*func)(double)) {
	double dx;
	long double res = 0;
	dx = (Right - Left) / N;
	long int i;
	for (i = 0; i < N; i++) {
		res += (func(Left + dx * (i + 1)) + func(Left + dx * i))
				* (Left + dx * (i + 1) - (Left + dx * i));
	}
	res /= 2;
	return res;
}


typedef double (*IntegralF)(double, double, long, double (*func)(double));
IntegralF Funcs[] = { Integral1, Integral2, Integral3, Integral4, Integral5,
		Integral6, Integral7, Integral8, Integral8 };

typedef struct Args Args;
struct Args {
	int i;
	double L;
	double R;
	long n;
	double res;
	DDfunc func;
};

void *callInt(void *args) {
	Args *p;
	p = args;
	p->res = Funcs[p->i](p->L, p->R, p->n, p->func);
	return 0;
}

int main(int argc, char **argv) {
	Entry entries[] = { (Entry ) { f1, F1, df1 }, //exp(-x)
			(Entry ) { f2, F2, df2 }, //sin(x)
			(Entry ) { f3, F3, df3 }, //exp(x)
			(Entry ) { f4, F4, df4 }, //sin(x^2)
			(Entry ) { f5, F5, df5 }, //tan(x)
			(Entry ) { f6, F6, df6 }, //ln(x)
			(Entry ) { f7, F7, df7 } , //x^3
			};
	Limit limits[] = {
		(Limit ) { 1, 30 },
		(Limit ) { 0, M_PI},
		(Limit ) {-1, 1},
		(Limit ) {-M_PI, M_PI},
		(Limit ) { -0.49999 * M_PI, 0.49999 * M_PI },
		(Limit ) { 1, 100 },
		(Limit ) { -15, 15 },
	};
	long n;
	int i, fn, N_THREADS, sn;
	char file[10];
	long l, r, d;
	printf("thread c, func set, intfunc number, file name, left, right, dn\n");
	scanf("%d%d%d%s%ld%ld%ld", &N_THREADS, &sn, &fn, file, &l, &r, &d);
	i = fn;
	double L = OFFSET + limits[sn].L, R = OFFSET + limits[sn].R;
	double V0 = entries[sn].F(R) - entries[sn].F(L);
//	V0 = 0.8948314694841449588; ??? sin(x^2)
	FILE *cf = fopen(file, "w");
	fprintf(cf, "a; b; c\n");
	for (n = l; n < r; n += N_THREADS * d) {
		pthread_t threads[N_THREADS];
		int k;
		Args args[N_THREADS];
		for (k = 0; k < N_THREADS; k++) {
			args[k] = (Args )
					{ i, L, R, n + d * k, 0, entries[sn].f };
			pthread_create(&threads[k], 0, callInt, (void*) &args[k]);
		}
		for (k = 0; k < N_THREADS; k++)
			pthread_join(threads[k], 0);
		for (k = 0; k < N_THREADS; k++)
			fprintf(cf, "%ld; %.15G; %.15G;\n", n + d * k, -(args[k].res - V0),
					(R - L) * (R - L) / (n + d * k) / (n + d * k) / 12
							* fabs(entries[sn].df(R) - entries[sn].df(L)));
		//		double V = Funcs[i](L, R, n, f);
		//		fprintf(cf, "%ld; %.15G; %.15G\n", n, ((V - V0)),
		//				(R - L) * (R - L) / n / n / 12 * fabs(F(R) - F(L)));
	}
	/*pthread_t threads[24];
	 Args args[24];
	 i = 0;
	 for (i = 0; i < 24; i++) {
	 args[i] = (Args )
	 { fn, L, R, 1L << i, 0, entries[sn].f };
	 pthread_create(&threads[i], 0, callInt, (void*) &args[i]);
	 //		pthread_join(threads[i], 0);
	 }
	 for (i = 0; i < 24; i++)
	 pthread_join(threads[i], 0);
	 for (i = 0; i < 24; i++)
	 fprintf(cf, "%ld; %.15G; %.15G;\n", 1L << i, (args[i].res - V0),
	 (R - L) * (R - L) / (1L << i) / (1L << i) / 12
	 * fabs(entries[sn].df(R) - entries[sn].df(L)));*/
	fclose(cf);
	return 0;
}