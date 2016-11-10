#include <stdio.h>
 
int main()
{
 int i=0;
 const int k=8;
 int b[k];
 int a[k];
 int sum1=0;
 int sum2=0;
 
  for(i=0;i<k;i++)
   {
      scanf("%d\n", &a[i]);
   }
  for(i=0;i<k;i++)
   {
      scanf("%d",&b[i]);
   }
  for(i=0;i<k;i++)
   {
      sum1+=a[i];
   }
  for(i=0;i<k;i++)
   {
      sum2+=b[i];
   }
    if(sum1==sum2)
    {
	printf("yes");
    }
    else
    {
	printf("no");
    }
return 0;
}