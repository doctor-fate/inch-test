#include <stdio.h>

int main() 
{
    unsigned long b, b1, p, a, m;
	int n, n1, i;
	scanf("%ld", &a);
	scanf("%ld", &b);
	scanf("%ld", &m);
	n = 0;
	b1 = b;
	while (b >= 1) 
	{
		b = b / 2;
		++n;
	}
	b = b1;
	n1 = n;
	unsigned long K[n];
	while (b >= 1) {
		K[n - 1] = (b % 2) * a;
		b = b / 2;
		--n;
	}
	n = n1 - 1;
	p = K[0];
	for (i = 1; i <= n; ++i)
		p = (((p * 2) % m) + (K[i] % m)) % m;
	printf("%ld", p);
	return 0;
}
