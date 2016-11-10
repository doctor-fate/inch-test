#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct {
    int *data;
    int cap;
    int top;
} s;

void InitStack(int n)
{
    s.cap = n;
    s.data = (int*)malloc(s.cap*sizeof(int));
    s.top = 0;
}

void Increase()
{
    s.data = (int*)realloc(s.data, 2*s.cap*sizeof(int));
    s.cap *= 2;
}

void Push(int x)
{
    if (s.cap == s.top)
        Increase();
    s.data[s.top] = x;
    s.top++;
}

int Pop()
{
    s.top--;
    return s.data[s.top];
}

int main()
{
    char op[6];
    int n, i, a, b, x;
    scanf("%d", &n);
    InitStack(n);
    for (i = 0; i < n; i++){
        scanf("%s", &op);
        if (op[0] == 'C'){
            scanf("%d", &x);
            Push(x);
        }
        else {
            a = Pop();
            if (op[0] == 'N')
                Push(a*(-1));
            else
                if (op[0] == 'D')
                    if (op[1] == 'I'){
                        Push(a);
                        Push(a);
                    }
                    else {
                        b = Pop();
                        Push(a/b);
                    }
                else {
                    b = Pop();
                    if (op[0] == 'A')
                        Push(a+b);
                    else
                        if (op[0] == 'S')
                            if (op[1] == 'U')
                                Push(a-b);
                            else {
                                Push(b);
                                Push(a);
                            }
                        else
                            if (op[1] == 'U')
                                Push(a*b);
                            else
                                if(op[1] == 'A')
                                    Push(a > b ? a : b);
                                else
                                    Push(a < b ? a : b);
                }
        }
    }
    printf ("%d", Pop());
    free(s.data);
    return 666;
}