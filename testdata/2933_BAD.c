#include <stdio.h>

int main()
{
    unsigned long x, b, a0, a1;
    int i,s;
    scanf("%ld", &x);
    i = 0;
    a0 = 1;
    a1 = 2;
    b  = 0;
    if (x == 0)
            printf("0");
	while (x > 0)
	{
		i = 0;
		a0 = 0;
		a1 = 1;
		b  = 0;
		for (; b <= x; ++ i)
		{
			b = a0 + a1;
            a0 = a1;
            a1 = b;
		}
        printf("1");
        x -= a0;
        s = i - 1;
        i = 0;
		a0 = 0;
		a1 = 1;
		b  = 0;
        for(; b <= x; ++ i)
        {
            b = a0 + a1;
            a0 = a1;
            a1 = b;
        }
        for(; s > i; ++ i)
        {
            printf("0");
        }
    }
    return 0;
}
