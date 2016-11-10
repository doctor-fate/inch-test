
#include <stdio.h>

int main()
{
  long k=0,i=0,p=0, n=0;
  scanf("%ld", &n);
  unsigned long a[100];
  p=n;
  
  if (n==0)
    printf("0");
  else if (n==1) 
    printf("1");
  else 
  {
    a[0]=1;
    a[1]=1;
  i=2;
    while (a[i-1]<=n)
    {
      a[i]=a[i-1]+a[i-2];
      i++;
    }
    for (k=i-2;k>=1;k--)
    if (a[k]<=p) 
    {
      printf("1");
      p-=a[k];
    }
    else 
      printf("0");
    printf("\n");
      
 
  }
 
      return 0;
}
      
      