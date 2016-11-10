
#include <stdio.h>

int main()
{
   int i,k, a[8], b[8],X;
  for (i=0;i<8; i++)
    scanf ("%d", &a[i]);
  for (k=0;k<8; k++)
    scanf ("%d", &b[k]);
  X=0;
  for (i=0;i<8;i++)
    for (k=0;k<8;k++)
    {
      if (b[k]==a[i])
          a[i]=b[k]=X;
    }
 for (i=0;i<8;i++)
    {
      if (a[i]!= X)
     break;
    else 
      { 
        if (i!=7) 
           continue;
           else printf("yes\n");
      
       }
       return 0;
    }
    printf("no\n");
      return 0;
}
