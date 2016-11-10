#include<stdio.h>
main()
{
  long int a[8];
  long int b[8];
  int c[8]={0};
  int d[8]={0};
  char i,j;
  
  for (i=0;i<8;i++) scanf("%ld",&a[i]);
  for (i=0;i<8;i++) scanf("%ld",&b[i]);
  
  
  for (i=0;i<8;i++) {
    
    for (j=0;j<8;j++) {
      
      if (a[i]==b[j]) c[i]++;
      }
  }   
    
  for (i=0;i<8;i++) {
    
    for (j=0;j<8;j++) {
      
      if (a[i]==a[j]) d[i]++;
    }
  }
    
    for (i=0;i<8;i++) {
    
   
      
      if (c[i]!=d[i]) {printf("no");break;}
      else { if (i==7) printf("yes");}
      
    }
      
    }
