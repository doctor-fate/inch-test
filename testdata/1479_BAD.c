#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
int main(int argc, char **argv)
{ 
        long int a, b, m, mulmod, tester, i;
        scanf("%ld %ld %ld", &a, &b, &m);
	mulmod = 0;
	for (i=63; i>=0; i--) {
		tester=b >> i;
		if (tester!=0){
			if (0==(tester % 2)) tester=0;
			else tester=1;
}
		mulmod = ((mulmod*2 % m) + (a*tester % m)) % m; 
}	
	printf("%ld", mulmod);
	return 0;
}