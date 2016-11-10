#include <stdio.h>
main()
{
long i,j,a,b,m,k,u;
scanf("%ld%ld%ld", &a,&b,&m);
u=0; j=b;
while (j!=0){
j/=2; u++;
}
k=a*((b>>u-1)%2)*2;
for (i=u-2;i>0;i--){
k=((k+a*((b>>i)%2))%m)*(2%m);
}
k%=m;
j=((b%2)*a)%m;
j=(j+k)%m;
printf("%ld\n", j);
}