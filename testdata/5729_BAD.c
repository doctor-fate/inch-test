        
#include <stdio.h>
#include <stdlib.h>
int main()

{
long i, j, k, t, n, a, sum=0 ;
scanf("%ld", &n);
long* l;
l=(long*)malloc(n*sizeof(long));
i=0;
while(i<n)
{
scanf("%ld", &l[i]);
i++;
}
scanf("%ld",&k);
i=0;
while(i<k)
{
	sum+=l[i];
i++;
}
t=sum;
i=k;
while(i<n)
{
	t=t-l[i-k]+l[i];
	if(t>sum)
        {
                sum=t;
        }
	i++;
}
printf ("%ld",sum);
free(l);
return 0;
}