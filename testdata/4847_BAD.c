
#include <stdio.h>

int main()
{
        int a[8],b[8],i,j,k=0,f=1;
        
        for(i=0;i<8;i++)
        scanf("%d",&a[i]);
        
         for(i=0;i<8;i++) 
         scanf("%d",&b[i]);
         
        for(j=0;j<8;j++) {
                
        for(i=0;i<8;i++)
        
        if (a[i]==b[j]&&f==1) {
        	a[i]=0;
        	k++;
        	f=0;
        }
       
        f=1;
                          }     
         
         
     if (k==8) printf("yes");
         else printf("no");
         
         
        
        
        return 0;
}



