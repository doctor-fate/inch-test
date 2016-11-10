#include <stdio.h>

int main(int argc, char **argv)
{
    
long int quantity1, quantity2, count1, count2, n, m;
long int i;
long int set1 = 0;
long int set2 = 0;

scanf("%ld", &quantity1);
for (count1 = 0; count1 < quantity1; count1++)
{
    scanf("%ld", &n);
    set1 += 1 << n;
}
scanf("%ld", &quantity2);
for (count1 = 0; count1 < quantity2; count1++)
{
    scanf("%ld", &m);
    set2 += 1 << m;
}
set1 &= set2;
for (i = 0; i < 32; i++)
{
    if (set1 & (1 << i))
    {
        printf("%ld", i);
        printf("\n");
    }
    else
    {
        printf("");
    }
}
return 0;
}