#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 80

char *concat(char **s, int n) {
	int j, i, k;
	k = 1;
	char *A;
	for (i = 0; i < n; ++i)
		for (j = 0; s[i][j] != '\0'; ++j)
			++k;
	A = (char*) malloc(k * sizeof(char));
	strcpy(A, "");
	for (i = 0; i < n; ++i)
		strcat(A, s[i]);
	return A;
}

int main(int argc, char **argv) {
	int n, i;
	n = 0;
	scanf("%d ", &n);
	char **S = (char**) malloc(n * sizeof(char*));
	for (i = 0; i < n; ++i) {
		S[i] = (char*) malloc(L * sizeof(char));
		gets(S[i]);
	}
	char *Y = concat(S, n);
	printf("%s", Y);
	free(Y);
	for (i = 0; i < n; ++i)
		free(S[i]);
	free(S);
	return 0;
}