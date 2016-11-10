
#include <stdio.h>
#define N 66

int main(void)
{
long mod_res = 0;
long a, b, m;
short mass_bin[N], i = 0, j = 0;
scanf("%ld", &a);
scanf("%ld", &b);
scanf("%ld", &m);
do
{
mass_bin[i] = b % 2;
b = (b / 2);
i++;
}
while (b/2 != 0);
mass_bin[i] = 1;
for (j = i; j >=0; j--)
mod_res = ((((mod_res % m) * (2 % m)) % m) + (a*mass_bin[j] % m)) % m;
printf("%ld\n", mod_res);
return 0;
}
