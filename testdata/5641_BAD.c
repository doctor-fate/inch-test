#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
int main(int argc, char **argv)
{ 
        long int t;
	scanf("%ld", &t);	
	long int arr[t],j,i,k,sum,sum2,p;
	for (i=0;i<t;i++) scanf("%ld", &arr[i]);
	scanf("%ld", &k);
	sum=0;	
	sum2=0;	
	for (i=0;i<=(t-k);i++) {
		for(j=i,p=k;p!=0;j++,p--) {
			sum+=arr[j];
}
		if (sum>=sum2) sum2=sum;
		sum=0;
}
	printf("%ld", sum2);
	return 0;
}