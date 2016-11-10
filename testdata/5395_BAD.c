#include <stdio.h>
#include <math.h>
#define n 10000
int main()
{
         
  long int f,k,s,i,maxs;
         long int a[n];
	 scanf("%ld", &f);
   for (i=0;i<f;i++)
     scanf("%ld", &a[i]);
     scanf("%ld", &k);
    s = 0;
    for (i=0; i<k; i++)
    s = s + a[i];
    maxs = s;
    for (i=0; i+k<f; i++)
        {
          s = s - a[i] + a[i+k];
          if (s>maxs) maxs = s;
        }
	printf("%ld", maxs); 
}          