#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int *data;
    int cap;
    int top;
};

void initstack (struct stack *s)
{
    int n;
    s->data = (int*)malloc(n * sizeof(int));
    s->cap = n;
    s->top = 0;
}

void push (struct stack *s, int t)
{
    s->data[s->top] = t;
    s->top++;
}

int pop (struct stack *s)
{
    s->top--;
    int q = s->data[s->top];
    return q;
}

void add (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, a + b);
}

void sub (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, a - b);
}

void mul (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, a * b);
}

void m_div (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, a / b);
}

void max (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, (((a)<(b) ? (a)) : (b)));
}

void min (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, ((a)<(b) ? (a):(b)));
}

void neg (struct stack *s)
{
    int a = pop(s);
    push (s, -a);
}

void dup (struct stack *s)
{
    int a = pop(s);
    push (s, a);
    push (s, a);
}

void swap (struct stack *s)
{
    int a = pop(s);
    int b = pop(s);
    push (s, a);
    push (s, b);
}


int main()
{
    struct stack zxc;
    int i, x;
    char s[2];
    scanf ("%d", &n);
    initstack(&zxc);
    for (i = 0; i < n; i++) {
        scanf ("%s", &s);
        switch (s) {
            case CON:scanf("%d", &x); push(&zxc, x); break;
            case ADD:add(&zxc); break;
            case SUB:sub(&zxc); break;
            case MUL:mul(&zxc); break;
            case DIV:m_div(&zxc); break;
            case MAX:max(&zxc); break;
            case MIN:min(&zxc); break;
            case NEG:neg(&zxc); break;
            case DUP:dup(&zxc); break;
            default:swap(&zxc); break;
        }
    }
    printf("%d", pop(&zxc));
    free(zxc.data);
    return 0;
}