#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 
int main(int argc, char **argv)
{ 
        long int arr[8],ar[8], j,i,k;
	k=0;
	for (i=0;i<8;i++) scanf("%ld", &arr[i]);
	for (i=0;i<8;i++) scanf("%ld", &ar[i]);
	for (j=0;j<8;j++) {	
		for (i=0;i<8;i++) {
			if ((arr[j]==ar[i]) && (arr[j]!=9)) {
				k+=1;
				arr[j]=9;
				ar[i]=9;
}
}
}
	if (k==8) printf("yes");
	else printf("no");
	return 0;
}