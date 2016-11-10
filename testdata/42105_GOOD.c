#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct {
    long long *data;
    int cap;
    int top;
} s;

void InitStack()
{
    s.cap = 20;
    s.data = (long long*)malloc(s.cap*sizeof(long long));
    s.top = 0;
}

void Increase()
{
    s.data = (long long*)realloc(s.data, 2*s.cap*sizeof(long long));
    s.cap *= 2;
}

void Push(long long x)
{
    if (s.cap == s.top)
        Increase();
    s.data[s.top] = x;
    s.top++;
}

long long Pop()
{
    s.top--;
    return s.data[s.top];
}

int main()
{
    InitStack();
    char op[6];
    int n, i;
    long long a, b, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%s", &op);
        if (op[0] == 'C'){
            scanf("%lld", &x);
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
                    if (op[0] = 'A')
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
    printf ("%lld", Pop());
    return 666;
}