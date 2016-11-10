#include <stdio.h>
#include <stdlib.h>

struct {
  int *data, cap, top;
} s;

void InitStack(int n) {
  s.data = (int*)malloc(n*sizeof(int));
  s.cap = n-1;
  s.top = 0;
}

void Push(int x) {
  s.data[s.top] = x;
  ++s.top;
}

int Pop() {
  --s.top;
  return s.data[s.top];
}

int main(int argc, char **argv) {
  int n, i, a, b;
  scanf("%d", &n);
  InitStack(n);
  char cmd[5];
  for(i = 0; i < n; i++) {
    scanf("%s", &cmd);
    if(cmd[0] == 'C') {
      scanf(" %d", &a);
      Push(a);
      }
    if(cmd[2] == 'D') {
        a = Pop();
        b = Pop();
        Push(a+b);
      }
    if(cmd[2] == 'B') {
        a = Pop();
        b = Pop();
        Push(a-b);
      }
    if(cmd[2] == 'L') {
        a = Pop();
        b = Pop();
        Push(a*b);
      }
    if(cmd[2] == 'V') {
        a = Pop();
        b = Pop();
        Push(a/b);
      }
    if(cmd[2] == 'X') {
        a = Pop();
        b = Pop();
        if(a >= b)
          Push(a);
        else
          Push(b);
      }
    if(cmd[2] == 'N' && cmd[0] == 'M') {
        a = Pop();
        b = Pop();
        if(a <= b)
          Push(a);
        else
          Push(b);
      }
    if(cmd[2] == 'G') {
        a = Pop();
        Push(-a);
      }
    if(cmd[2] == 'P') {
        a = Pop();
        Push(a);
        Push(a);
      }
    if(cmd[2] == 'A') {
        a = Pop();
        b = Pop();
        Push(a);
        Push(b);
      }
    }
  a = Pop();
  printf("%d", a);
}
