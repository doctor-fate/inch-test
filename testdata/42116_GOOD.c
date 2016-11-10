#include <stdio.h>
#include <stdlib.h>

struct {
    int *data;
    int cap;
    int top;
} s;

void InitStack(int n)
{
    s.cap = n-1;
    s.data = (int*)malloc(n*sizeof(int));
    s.top = 0;
}

void Push(int x)
{
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
    InitStack(2*n);
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
                    if (op[1] == 'U'){
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