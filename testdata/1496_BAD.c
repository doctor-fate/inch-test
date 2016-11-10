#include<stdio.h>


int main() {
        
long long array[64],a,b,m,i=0,sum=0,j,i1;

scanf("%lld%lld%lld",&a,&b,&m);

while(a!=0) {
        
if (a  %  2 != 0)  array[i]=1;
   else  array[i] = 0;

a= a/2;

i++;
            }

i1=i;

  for (j=i-1; j>=0; j--) 
  sum = (b *array[j] + 2*sum) % m;
        
 if (i1 == 63) printf ("%lld ", sum%m*2);  
    else  printf ("%lld ", sum%m);  

	
	return 0;
	
}