
#include <stdio.h>

int main()
{
  int i,j,A[9],B[9],min,x ;
  x = 0;
  for (i=0;i<8;i++) 
    scanf("%d", &A[i]);
  min = A[i];
    for (i=1;i<8;i++) 
      if (A[i] < min)
        min = A[i] - 1;
  for (j=0;j<8;j++) 
    scanf("%d", &B[j]);
  for (j=1;j<8;j++) 
      if (B[j] < min)
	min = B[j] - 1;
      for (i=0;i<8;i++) {
	 for (j=0;j<8;j++) {
	   if (A[i] == B[j])
	     A[i] = B[j] = min;
	 }
      }
      for (i=0;i<8;i++)
	if (A[i] != min)
	  x = 1;
      if(x == 1)
	  printf("no! ") ;
      else
	  printf("yes! ") ; 
return 0;
}