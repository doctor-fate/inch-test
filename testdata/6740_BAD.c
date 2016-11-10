#include <stdio.h>
#include <math.h>
#define p 66666
int main()
{
    unsigned int i, j, k;
    int n, max;
    short a[p];
    scanf ("%d", &n);
    if (n<0) n=-1*n;
	 //заполним решето и повычеркиваем что не надо
    for (j = 0; j < p; j++) a[j] = 1;
    a[0] = 0;
    a[1] = 0;
 
    for (i = 2; i < p; i++) 
    {        
        if (a[i] != 0) 
        {
            for (k = i*2; k <= p; k = k + i) 
            {
                a[k] = 0;
            }
        }
    }
	max = 0;
	if (n<p) 
        {
		for (i=0; i<=n; i++)
	        {
      if (a[i] != 0)  while (n%i==0)
		        {
			        n = n / i;
			        max = i;
		        }
                }
	}
	else 
        {
		for (i=0; i<p; i++)
	        {
      if (a[i] != 0)  while (n%i==0)
		        {
			        n = n / i;
			        max = i;
		        }
                }
	}
   if (n>max) printf("%d", n);
   else printf("%d", max);
   return 0;
}              