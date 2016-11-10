#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x, y) ((x)>(y) ? (x):(y))
#define min(x, y) ((x)<(y) ? (x):(y))

struct stack {
    int *data;
    int cap;
    int top;
};

int n;

char m_const[6] = "CONST";//кладёт в стек число x
char m_add[4] = "ADD";//сложение
char m_sub[4] = "SUB";//вычитание
char m_mul[4] = "MUL";//умножение
char m_div[4] = "DIV";//деление
char m_max[4] = "MAX";//максимум двух чисел
char m_min[4] = "MIN";//минимум двух чисел
char m_neg[4] = "NEG";//меняет знак числа, находящегося на вершине стека;
char m_dup[4] = "DUP";//кладёт в стек копию числа, находящегося на вершине стека;
char swag[5] = "SWAP";//меняет местами два числа, находящиеся на вершине стека.

void push (struct stack *s, int x)
{
    if (s->top == s->cap) printf("overfill\n");
    else {
        s->data[s->top] = x;
        s->top++;
    }
}

int pop (struct stack *s)
{
    if (0 == s->top) {
        printf("devastation\n");
        return -1;
    }
    else {
        s->top--;
        int ret_val = s->data[s->top];
        return ret_val;
    }
}

void s_add (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = a + b;
    push (s, ret_val);
    printf("add=%d\n", ret_val);
}

void s_sub (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = a - b;
    push (s, ret_val);
    printf("sub=%d\n", ret_val);
}

void s_mul (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = a * b;
    push (s, ret_val);
    printf("mul=%d\n", ret_val);
}

void s_div (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = a / b;
    push (s, ret_val);
    printf("div=%d\n", ret_val);
}

void s_max (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = max(a, b);
    push (s, ret_val);
    printf("max=%d\n", ret_val);
}

void s_min (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);
    int ret_val = min(a, b);
    push (s, ret_val);
    printf("min=%d\n", ret_val);
}

void s_neg (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int ret_val = a * (-1);
    push (s, ret_val);
    printf("neg=%d\n", ret_val);
}

void s_dup (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int ret_val = a;
    push (s, ret_val);
    push (s, ret_val);
    printf("dup=%d\n", ret_val);
}

void s_swag (struct stack *s)
{
    //struct stack turn;
    int a = pop(s);
    int b = pop(s);

    push (s, b);
    push (s, a);
    printf("swap\n");
}
void initstack (struct stack *s)
{
    s->data = (int*)malloc(n * sizeof(int));
    s->cap = n;
    s->top = 0;
}

int main()
{
    struct stack turn;
    int i, val;
    char s[6];

    scanf("%d", &n);

    initstack(&turn);

    for (i = 0; i < n; i++) {
        scanf("%s", s);
        if (0 == strcmp(s, m_const)) {
            scanf("%d", &val);
            push (&turn, val);
        }
        if (0 == strcmp(s, m_add)) {
            s_add (&turn);
        }
        if (0 == strcmp(s, m_sub)) {
            s_sub (&turn);
        }
        if (0 == strcmp(s, m_mul)) {
            s_mul (&turn);
        }
        if (0 == strcmp(s, m_div)) {
            s_div (&turn);
        }
        if (0 == strcmp(s, m_max)) {
            s_max (&turn);
        }
        if (0 == strcmp(s, m_min)) {
            s_min (&turn);
        }
        if (0 == strcmp(s, m_neg)) {
            s_neg (&turn);
        }
        if (0 == strcmp(s, m_dup)) {
            s_dup (&turn);
        }
        if (0 == strcmp(s, swag)) {
            s_swag (&turn);
        }
    }

    int final_val;
    final_val = pop(&turn);
    printf("\nfinal-val=%d", final_val);

    return 0;
}
