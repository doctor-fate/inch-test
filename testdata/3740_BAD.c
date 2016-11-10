#include <stdio.h>
main (){
unsigned int A,B,AM=0,BM=0,N,i;
printf("введите размерность А\n");
scanf("%d", &A);
printf("введите элементы А\n");
for(i=A;i>0;i--){
        scanf ("%d", &N);
	AM|=1<<N;
	}
printf("введите размерность В\n");
scanf ("%d", &B);
printf ("введите элементы B\n");
for(i=B;i>0;i--){
	scanf ("%d",&N);
	BM|=1<<N;
	}
N=AM&BM; 
for (i=0;i<=31;i++){
	if(N%2==1)
		printf("%d ",i);
	N=N>>1;
}
return 0;
}