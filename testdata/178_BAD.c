#include <stdio.h>

int main()
{
  int n, x0, i, a;
  long p, pd;
  scanf("%d", &n); /* степень полинома */
  scanf("%d", &x0); /* значение x нулевое */
  p = 0;
  pd = 0;
  for (i = n; i >= 0; i--)   { 
          scanf("%d", &a); /* коэффициенты полинома */
          if (i > 1) { 
            p = (p + a) * x0;
            pd = (pd + a * i) * x0; 
            } 
            else if (i == 1) { 
                    p = (p + a) * x0;
                    pd = pd + a; 
                    } 
    else p = p + a;
  }
  printf("%ld %ld \n", p, pd);
  return 0;
}