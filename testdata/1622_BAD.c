#include <stdio.h>
#include <math.h>
int main(int argc , char ** argv)
{
long long a, b, m, mm;
scanf ("%lld%lld%lld", &a, &b, &m);
int i;
long long arr[64];
for (i=0; i<64; i++)
{
        arr[i]=b%2;
        b=b/2;
}
mm=(arr[63]*a*2)%m+(a*arr[62])%m;
for (i=61; i>-1; i--)
{
        mm=(mm*2)%m+(a*arr[i])%m;
}
printf ("%lld", mm%m);
return 0;
}