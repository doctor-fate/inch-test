#include <stdio.h>
int main()
{
int c,a=0,b=0;
int na,nb,i;
scanf("%d", &na);
i=0;
while(i<na)
{
int j,x,k=1;
scanf ("%d", &x);
j=0;
while(j-x)
{
k*=2;
j++;
        }
a+=k;
i++;
}
scanf("%d", &nb);
i=0;
while(i<nb)
{
int j,x,k=1;
	scanf ("%d", &x);
	j=0;
	while(j<x)
	{
		j++;
		k*=2;
	}
	b+=k;
	i++;
}
c= a&b;
i=0;
while(i<32)
{
	if (c%2!=0)
	{
printf("%d ",i);
		c-=1;
	}
c=c/2;
i++;
}
return 0;
}