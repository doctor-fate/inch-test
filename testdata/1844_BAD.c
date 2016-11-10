
#include <stdio.h>

int main()
{

long a, b, m, sum;
long array[64];
int i;

scanf("%ld %ld %ld", &a, &b, &m);

for(i = 0; i <=63; i = i + 1) 
{
  array[i] = b % 2;
  b /= 2;
}

sum = a * array[63];

for(i = 62; i >= 0; i = i - 1)
{  
 sum = (sum * 2) % m + (a * array[i]) % m ; 
}

sum = sum % m;

printf("\n%ld\n", sum);

return 0;
}
