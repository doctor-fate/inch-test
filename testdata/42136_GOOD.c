#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef unsigned char byte;
typedef byte *pbyte;
typedef int (*comparer)(const void *a, const void *b);
typedef byte boolean;
#define ABS(a) ((a) >= 0 ? (a) : (-a))
#define MAX(a,b) ((a) > (b) ? (a) : (b)) 
#define MIN(a,b) ((a) < (b) ? (a) : (b)) 

#define UseStack(T, N) typedef struct { T *Arr; int Pointer, Length; } Stack##N, *PStack##N;\
    PStack##N NewStack##N(int size) { \
                PStack##N s = (PStack##N)malloc(sizeof(Stack##N)); \
		s->Arr = (T *)calloc(size, sizeof(T));\
		s->Length = size;\
		s->Pointer = 0; return s; } \
		\
	void Push##N(PStack##N stack, T elem) { \
		if(stack->Pointer == stack->Length - 1)\
		{ stack->Arr = (T *)realloc(stack->Arr, stack->Length * 2 * sizeof(T));   stack->Length *= 2;}\
		stack->Arr[stack->Pointer++] = elem; }\
		\
	T Pop##N(PStack##N stack) { return stack->Arr[stack->Pointer-- - 1]; }\
	void FreeStack##N(PStack##N stack) { free(stack->Arr); free(stack); }

UseStack(int, Int)

int main(void)
{
	int cmdcount, i, op1, op2;
	char cmd[256];
	PStackInt numstack = NewStackInt(32);
	scanf("%d", &cmdcount);

	for(i = 0;i < cmdcount;i++)
	{
		scanf("%s", cmd);
		
		if(!strcmp("CONST", cmd))
		{
			scanf("%d", &op1);
			PushInt(numstack, op1);
		}
		else if(!strcmp("ADD", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, op1 + op2);
		}
		else if(!strcmp("MUL", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, op1 * op2);
		}
		else if(!strcmp("SUB", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, op1 - op2);
		}
		else if(!strcmp("DIV", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, op1 / op2);
		}
		else if(!strcmp("MAX", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, MAX(op1, op2));
		}
		else if(!strcmp("MIN", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, MIN(op1, op2));
		}
		else if(!strcmp("NEG", cmd))
		{
			op1 = PopInt(numstack);
			PushInt(numstack, -op1);
		}
		else if(!strcmp("DUP", cmd))
		{
			op1 = PopInt(numstack);
			PushInt(numstack, op1);
			PushInt(numstack, op1);
		}
		else if(!strcmp("SWAP", cmd))
		{
			op1 = PopInt(numstack);
			op2 = PopInt(numstack);
			PushInt(numstack, op2);
			PushInt(numstack, op1);
		}
	}

	printf("%d", PopInt(numstack));

	FreeStackInt(numstack);
	//да знаю можно и лучше было написать
	return 0;
}
