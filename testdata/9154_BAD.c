
#include <stdio.h>

int main()
{
        int j,j1,j2,i,i1,i2,a,b,c[10][10],k,t,max=0,LOL=0;
        scanf("%d %d",&a,&b);
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        scanf("%d",&c[i][j]);
        k=0;
        t=0;
        
        while (t!=a) {
        i=t;
        for(j=0;j<b;j++)
        if (c[i][j]>max) {
                max=c[i][j];
                i1=i;
                j1=j;
        }
        
        for(i=0;i<a;i++)
        if (max>c[i][j1]) k++;
        
        if (k==0) {
                i2=i1;
                j2=j1;
                LOL=1;
        }
        k=0;
        max=0;
        t++;
}
 if (LOL==1) printf("%d %d",i2,j2);
 else printf("none");
 
 return 0; 
}