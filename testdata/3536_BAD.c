#include<stdio.h>
main()
{

unsigned long x,a,b,c,i,j,k,n;

scanf("%ld",&x);

k=0;

if (x!=0) {
           while (x>0) {
                a=b=1;
                c=0;
                i=1;
                k++;
                
                while (x>=b) {
                        c=a+b;
                        a=b;
                        b=c;
                        i++;
                        }
                        
                if (k!=1) {for (j=n-1;j>(i-1);j--) printf("%d",0);
                }
                
                n=i-1;
                x=x-a;
                        
                printf("%d",1);
        }


for (j=i-2;j>0;j--) printf("%d",0);} else printf("%d",0);
}
        