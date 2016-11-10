#include <stdio.h>

int main(void) {
        int n,i,k=0;
	char s[6];
	scanf("%d ",&n);
	int A[n];
	for (i=0;i<n;i++) {
		scanf("%s ");
		if (s[0]=='C') {
			scanf("%d ",&A[k]);
			k++;
		}
		if (s[0]=='A') {
			k--;
			A[k-1]+=A[k];
		}
		if (s[2]=='B') {
			k--;
			A[k-1]=A[k]-A[k-1];
		}
		if (s[2]=='L') {
			k--;
			A[k-1]*=A[k];
		}
		if (s[2]=='D') {
			k--;
			A[k-1]=A[k]/A[k-1];
		}
		if (s[1]=='A') {
			k--;
			if (A[k]>A[k-1]) {
				A[k-1]=A[k];
			}
		}
		if (s[0]=='M' && s[1]=='I') {
			k--;
			if (A[k]<A[k-1]) {
				A[k-1]=A[k];
			}
		}
		if (s[0]=='N') {
			A[k-1]=-A[k-1];
		}
		if (s[2]=='P') {
			A[k]=A[k-1];
			k++;
		}
		if (s[2]=='A') {
			int v=A[k-1];
			A[k-1]=A[k-2];
			A[k-2]=v;
		}
	}
	printf("%d",A[k-1]);
	return 0;
}
