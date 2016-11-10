#include <stdio.h>
 
int main() {
        unsigned int k,b,a1=0,a2=0,i,n1,n2;
 
	scanf("%u", &n1);
	for (i=0;i<n1;i++){
		scanf("%u ", &b);
		k=1<<b;
		a1=a1|k;
	}
 
 		scanf("%u", &n2);
		for (i=0;i<n2;i++){
		scanf("%u ", &b);
		k=1<<b;
		a2=a2|k;
	}
 
 
	a1=a1&a2;

	for (i=0;i<32;i++){
		k=a1&1;
 
		a1=a1>>1;
		if (k==1)
		printf("%u ", i); 
	}
	return 0;
}