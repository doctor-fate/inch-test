
#include <stdio.h>

int main()
{
        int k=0 , x , n=0 , i , j , a[8] , b[8];
	for (i=0;i<8;i++){
		scanf("%d",&a[i]);
			}
	for (i=0;i<8;i++){
		scanf("%d",&b[i]);
			}
	for (i=0;i<8;i++){
		for (j=i;j<8;j++){
			if (b[i]==a[j]){
				x=a[i];
				a[i]=a[j];
				a[j]=x;
				n++;
							}
						}
				}
	for (i=0;i<8;i++){
		if(a[i]!=b[i]){
			printf("no");
			return 0;
				}
	}
printf("yes");
	return 0;
}