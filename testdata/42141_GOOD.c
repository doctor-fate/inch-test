#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Stack {
	int data[100000], c;
};

struct Stack S;

void CONST(int x)
{
	S.data[S.c] = x;
	S.c++;
}

void ADD()
{
	S.data[S.c-2] = S.data[S.c-2] + S.data[S.c-1];
	S.c--;
}

void SUB()
{
	S.data[S.c-2] = S.data[S.c-1] - S.data[S.c-2];
	S.c--;
}

void MUL()
{
	S.data[S.c-2] = S.data[S.c-1] * S.data[S.c-2];
	S.c--;
}

void DIV()
{
	S.data[S.c-2] = S.data[S.c-1] / S.data[S.c-2];
	S.c--;
}

void MAX()
{
	if (S.data[S.c-1] > S.data[S.c-2])
		S.data[S.c-2] = S.data[S.c-1];
	S.c--;
}

void MIN()
{
	if (S.data[S.c-1] < S.data[S.c-2])
		S.data[S.c-2] = S.data[S.c-1];
	S.c--;
}

void NEG()
{
	S.data[S.c-1] = S.data[S.c-1] * (-1);
	S.c--;
}

void DUP()
{
	int a = S.data[S.c-1];
	CONST(a);
}

void SWAP()
{
	int swap = S.data[S.c-1];
	S.data[S.c-1] = S.data[S.c-2];
	S.data[S.c-2] = swap;
}

int main()
{
	int i, n, x;
	scanf("%d", &n);
	S.c = 0;
	char proc[5];
	for (i = 0; i < n; i++) {
		scanf("%s", &proc);
		if (strcmp(proc, "CONST") == 0) {
			scanf("%d", &x);
			CONST(x);
		}
		else if (strcmp(proc, "ADD") == 0) ADD();
		else if (strcmp(proc, "SUB") == 0) SUB();
		else if (strcmp(proc, "MUL") == 0) MUL();
		else if (strcmp(proc, "DIV") == 0) DIV();
		else if (strcmp(proc, "MAX") == 0) MAX();
		else if (strcmp(proc, "MIN") == 0) MIN();
		else if (strcmp(proc, "NEG") == 0) NEG();
		else if (strcmp(proc, "DUP") == 0) DUP();
		else if (strcmp(proc, "SWAP") == 0) SWAP();
	}
	printf("%d\n", S.data[0]);
	return 0;
}