#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void Push (int *stack, int *top, int v)
{
        stack[*top]=v;
	(*top)++;
}

int Pop (int *stack, int *top)
{
        (*top)--;
	return stack[*top];
}

int Ident(char *s) {
	if (!strcmp(s, "CONST")) return 1;
	if (!strcmp(s, "ADD")) return 2;
	if (!strcmp(s, "SUB")) return 3;
	if (!strcmp(s, "MUL")) return 4;
	if (!strcmp(s, "DIV")) return 5;
	if (!strcmp(s, "MAX")) return 6;
	if (!strcmp(s, "MIN")) return 7;
	if (!strcmp(s, "NEG")) return 8;
	if (!strcmp(s, "DUP")) return 9;
	if (!strcmp(s, "SWAP")) return 10;
}

int main()
{
	int n, i, j, k;
	char s[5];
	scanf("%d", &n);
	int stack[n], top=0;
	for (i=0; i<n; i++) {
		scanf("%s", s);
		switch (Ident(s)) {
			case 1 :
				scanf("%d", &k);
				Push(stack, &top, k);
				break;
			case 2 : 
				Push(stack, &top, Pop(stack, &top)+Pop(stack, &top));
				break;
			case 3 :
				Push(stack, &top, Pop(stack, &top)-Pop(stack, &top));
				break;
			case 4 :
				Push(stack, &top, Pop(stack, &top)*Pop(stack, &top));
				break;
			case 5 :
				Push(stack, &top, Pop(stack, &top)/Pop(stack, &top));
				break;
			case 6 :
				Push(stack, &top, MAX(Pop(stack, &top), Pop(stack, &top)));
				break;
			case 7 :
				Push(stack, &top, MIN(Pop(stack, &top), Pop(stack, &top)));
				break;
			case 8 :
				Push(stack, &top, -Pop(stack, &top));
				break;
			case 9 :
				Push(stack, &top, stack[top-1]);
				break;
			case 10 :
				k=stack[top-1];
				stack[top-1]=stack[top-2];
				stack[top-2]=k;
				break;
		}
					
	}
	printf("%d\n", stack[0]);
	return 0;
}