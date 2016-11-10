#include <stdio.h>
#include <math.h>

int  main()
{
int max=0,n=0,j=0,i=0,k=0;
float z=0;
scanf("%ld", &n);
if (n<0)
        n=-n;
z=sqrt (n);
i=40*ceil(z);
char a[i+4];
for (i=0; i<=40*z+1; i++)
        a[i]=1;
a[0]=0;
a[1]=0;
for (i=2; 40*z+1>=i*i; i++)        
        if (a[i]==1)
for(j=i*i; j<=40*z+1; j+=i)
	a[j]=0;
for (i=0; i<40*z+1; i++)
	if ( a[i] != 0)
		if (n%i==0)
			max=i;
if (max==0)
	max=n;
printf("%i ", max);


return 0;

}