#include <stdio.h>
#include <math.h>
int n, i, k, p=0, sum=0;

int main(int argc, const char * argv[])
{
scanf("%d", &n);
int a[n];
for (i=0; i<n; i++) scanf("%d", &a[i]);
scanf("%d", &k);
    
for (i=0; i<k; i++) sum=sum+a[i];
p=sum;
for (i=k; i<n; i++)
    {p=p+a[i]-a[i-k];
        if (p>sum) sum=p;}
    
    
printf("%d", sum);
return 0;
}