#include <stdio.h>
typedef struct Stack Stack;

struct Stack {
    int length, top, *data;
};

Stack *InitStack(int length)
{
    Stack *s = (Stack*)malloc(sizeof(Stack) * length);
    s->length = length;
    s->top = 0;
    s->data = (int*)malloc(sizeof(int) * length);
    return s;
}

void DestroyStack(Stack *s)
{
    free(s->data);
    free(s);
    return;
}

int StackEmpty(Stack *s)
{
    return s->top == 0;
}

void resizeStack(Stack *s, int newLength)
{
    Stack *newStack = (Stack*)malloc(sizeof(Stack) * newLength);
    Stack *oldStack = s;
    s = newStack;
    int i;
    for(i = 0; i < oldStack->top; i++){
        s->data[i] = oldStack->data[i];
    }
    s->length = oldStack->length;
    s->top = oldStack->top;
    DestroyStack(oldStack);
}

void Push(Stack *s, int x)
{
    if (s->top == s->length){
        resizeStack(s, s->length * 2);
    }
    s->data[s->top] = x;
    s->top++;
    return;
}

int Pop(Stack *s)
{
    if (StackEmpty(s)) return;
    s->top--;
    return s->data[s->top];
}

int equalStrings(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != 0 && s2[i] != 0){
        if (s1[i] != s2[i]) return 0;
        i++;
    }
    if (s1[i] == 0 && s2[i] == 0) return 1;
    return 0;
}
int max(int a, int b)
{
    if (a > b) return a;
    return b;
}
int min(int a, int b)
{
    if (a < b) return a;
    return b;
}
int main()
{
    int nel, i, number;
    scanf("%d", &nel);

    Stack *s = InitStack(128);

    char str[8], c;
    for(i = 0; i < nel; i++){
        scanf("%s", str);

        if (equalStrings(str, "CONST")){
            scanf("%d%c", &number, &c);
            Push(s, number);
            continue;
        }
        if (equalStrings(str, "ADD")){
            number = Pop(s);
            Push(s, number + Pop(s));
            continue;
        }
        if (equalStrings(str, "SUB")){
            number = Pop(s);
            Push(s, number - Pop(s));
            continue;
        }
        if (equalStrings(str, "MUL")){
            number = Pop(s);
            Push(s, number * Pop(s));
            continue;
        }
        if (equalStrings(str, "DIV")){
            number = Pop(s);
            Push(s, number/Pop(s));
            continue;
        }
        if (equalStrings(str, "MAX")){
            number = Pop(s);
            Push(s, max(number, Pop(s)));
            continue;
        }
        if (equalStrings(str, "MIN")){
            number = Pop(s);
            Push(s, min(number, Pop(s)));
            continue;
        }
        if (equalStrings(str, "NEG")){
            number = Pop(s);
            Push(s, -number);
            continue;
        }
        if (equalStrings(str, "DUB")){
            number = Pop(s);
            Push(s, number);
            Push(s, number);
            continue;
        }
        if (equalStrings(str, "SWAP")){
            number = Pop(s);
            int number2 = Pop(s);
            Push(s, number);
            Push(s, number2);
            continue;
        }
    }
    printf("%d", Pop(s));
    DestroyStack(s);
    return 0;
}