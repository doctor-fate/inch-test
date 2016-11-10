#include <stdio.h>

int main(void) {
        unsigned long a, b, m, ostm;
        int i, arr[63];
	scanf ("%lu", &a);
        scanf ("%lu", &b);
        scanf ("%lu", &m);
	i=0;
	while (i< 64){ 
                arr[i]=b%2;
                b=b/2;
                i++;
                }
	ostm=arr[63];
		for (i=63; i>=0; i--){
			ostm=(((ostm*(2 % m)) % m) + ((a *arr[i]) % m)) % m;
			}
	printf("%lu", ostm);
return 0;
}