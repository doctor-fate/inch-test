#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StackType long

struct Stack {
    StackType* Data;
    unsigned long Cap, Top;
};

void InitStack (struct Stack*, unsigned long);

_Bool StackEmpty (struct Stack*);

void Push (struct Stack*, StackType);

StackType Pop (struct Stack*);

int main(void) {
    unsigned long n;
    long x, y;
    struct Stack St;
    scanf("%lu", &n);
    InitStack(&St, n/2+1);
    char s[6];
    while (n--){
        scanf("%s", s);
        if (!strcmp(s, "CONST")) {
            scanf("%ld", &x);
            Push(&St, x);
            continue;
        }
        if (!strcmp(s, "ADD")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, x+y);
            continue;
        }
        if (!strcmp(s, "SUB")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, x-y);
            continue;
        }
        if (!strcmp(s, "MUL")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, x*y);
            continue;
        }
        if (!strcmp(s, "DIV")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, x/y);
            continue;
        }
        if (!strcmp(s, "MAX")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, (x>y)? x: y);
            continue;
        }
        if (!strcmp(s, "MIN")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, (x<y)? x: y);
            continue;
        }
        if (!strcmp(s, "NEG")) {
            Push(&St, -Pop(&St));
            continue;
        }
        if (!strcmp(s, "DUP")) {
            Push(&St, St.Data[St.Top-1]);
            continue;
        }
        if (!strcmp(s, "SWAP")) {
            x = Pop(&St);
            y = Pop(&St);
            Push(&St, x);
            Push(&St, y);
            continue;
        }
        printf("Unknown Command!\n");
    }
    printf("%ld\n", Pop(&St));
    if (!StackEmpty(&St)) printf("Error: Stack Not Empty!");
    free(St.Data);
    return 0;
}

void InitStack (struct Stack *St, unsigned long n) {
    (*St).Data = (StackType*)malloc(n*sizeof(StackType));
    (*St).Cap = n;
    (*St).Top = 0;
}

_Bool StackEmpty (struct Stack *St) {
    return !(*St).Top;
}

void Push (struct Stack *St, StackType x) {
    if (!((*St).Top==(*St).Cap)) (*St).Data[(*St).Top++] = x;
}

StackType Pop (struct Stack *St) {
    if (StackEmpty(St)) return (*St).Data[(*St).Top];
    else return (*St).Data[--(*St).Top];
}