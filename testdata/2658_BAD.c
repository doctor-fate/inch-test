#include <stdio.h>
#include<math.h>

int main()
{ long long i,j;
long long b[93];
long long x;
 scanf("%lld",&x);

long long fib[93];
    fib[0]=1;
    fib[1]=2;
  
  for ( i=2;i<93;i++)
    {
        fib[i] = fib[i-1]+fib[i-2];
    }
    for(i=0;i<93;i++)
    b[i]=0;
    
    
    
    long long min=pow(2,63),t=1,v;
if (x!=0) {
    while (x!=0) {
   for(i=0;i<92;i++)
   if (x-fib[i]<min&&x-fib[i]>=0) {  
           min=x-fib[i];
           j=i;
           
           
   }
   if (t!=0) { v=j;
   t=0;
           
   }
  
   
   
   x=x-fib[j];
   
   b[j]=1;
  
    }
    
 
     for(v;v>=0;v--)
     printf("%lld",b[v]);
     
}

else printf("0");
  
    
   
         
        return 0;   
}