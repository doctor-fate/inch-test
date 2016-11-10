#include <stdio.h>

main(){
        int A[2][8]={0},B[8],q=0,i,j;
        printf("введите элементы массива А\n");
	for (i=0;i<=7;i++)
	scanf ("%d", &A[0][i]);
	printf("введите элементы массива B\n");
	for (i=0;i<=7;i++){
		scanf ("%d", &B[i]);
		for(j=0;j<=7;j++)
		if(B[i]==A[0][j] && A[1][j]!=1){
			A[1][j]=1;
			q++;
			break;
		}
	}
	if(q==8)
	printf("yes\n");
	else
	printf("no\n");
	return 0;
}