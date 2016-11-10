#include<stdio.h>
#include<math.h>
main()
{
  long a,b,m,p,o;
  int i;
  int n;
  
scanf("%ld %ld %ld",&a,&b,&m);

n=(round(log2(b))+1);

int k[n];

for (i=0;i<n;i++) {
                      k[i]=b%2;
        	      b=b/2;
                   }
                  
p=(k[n-1]*a%m);

for (i=n-2;i>-1;i--) {
                        o=p*2;
                        p=(o%m)+k[i]*(a%m);
                      }
                      
                      
printf("%ld",p%m);  
}

