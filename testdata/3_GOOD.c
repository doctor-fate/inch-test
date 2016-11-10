
#include <stdio.h>

int main(int argc, char **argv) {
	int i, j, s, C[7];
	unsigned long long A[7], B[7];
	s = 0;
	for (i = 0; i <= 7; ++i) 
	{
		A[i] = 0;
		C[i] = 1;
		scanf("%llu", &A[i]);
	}
	for (i = 0; i <= 7; ++i) {
		B[i] = 0;
		scanf("%llu", &B[i]);
	}
	for (i = 0; i <= 7; ++i)
		for (j = i + 1; j <= 7; ++j)
			if (A[i] == A[j] && C[j] != 0) {
				C[j] = 0;
				++C[i];
			}

	for (i = 0; i <= 7; ++i)
		for (j = 0; j <= 7; ++j)
			if (B[i] == A[j] && C[j] != 0)
				++C[j];
	for (i = 0; i <= 7; ++i)
		if (C[i] % 2 == 0)
			s = s + C[i];
	if (s == 16)
		printf("yes");
	else
		printf("no");

	return 0;
}