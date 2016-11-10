#include <stdio.h>

int *arr, hight = 0;

int MaxElem (int x, int y)
{
        if (x > y) return x;
	else return y;
}

int MinElem (int x, int y)
{
	if (x < y) return x;
	else return y;
}

void DefStack(int n)
{
	arr = (int *)malloc(n*sizeof(int));
}

int Pop()
{
	return arr[hight--];
}

void CONST(int x)
{
	arr[hight++] = x;
}

void ADD()
{
	CONST(Pop() + Pop());
}

void SUB()
{
	CONST(Pop() - Pop());
}

void MUL()
{
	CONST(Pop() * Pop());
}

void DIV()
{
	CONST(Pop() / Pop());
}

void MAX()
{
	CONST(MaxElem(Pop(), Pop()));
}

void MIN()
{
	CONST(MinElem(Pop(), Pop()));
}

void NEG()
{
	CONST(-1 * Pop());
}

void DUP()
{
	int x = Pop();
	CONST(x);
	CONST(x);
}

void SWAP()
{
	int x = Pop();
	int y = Pop();
	CONST(x);
	CONST(y);
}

int main()
{
	char array[6];
	int i = 0, n = 0, m = 0;
	scanf("%d",&n);
	DefStack(n / 2 + 1);
	for (i = 0; i < n; i++) {
	scanf("%s",&array);
		switch (array[0]) {
			case 'C': {
				scanf("%d",&m);
				CONST(m);
				continue;
				}
			case 'A' : ADD(); continue;
            case 'S' : {
				if (array[1] == 'U') {
					SUB();
					continue;
				} else {
					SWAP();
					continue;
				}
			}
			case 'M' : {
				if (array[1] == 'U') {
					MUL();
					continue;
				}
				if (array[1] == 'A') {
					MAX();
					continue;
				}
				if (array[1] == 'I') {
					MIN();
					continue;
				}
			}
			case 'D' : {
				if (array[1] == 'I') {
					DIV();
					continue;
				} else {
					DUP();
					continue;
				}
			}
			case 'N' : NEG(); continue;
		}
	}
	printf("%d\n",Pop());
	return 0;
}