#include <stdio.h>
 
int main() {
 int n,k,i,l, max,sum;
 sum=0;
 max=0;
scanf("%d",&n);
int arr[n];
 for (i=0; i<n; i++)
        scanf("%d",&arr[i]);
scanf("%d",&k);
for (l=0;l<k;l++)
        sum=sum+arr[l];
max=sum;
for(i=0;k+i<n;i++){
                        sum=sum-arr[i]+arr[k+i];
                        if (sum>max)
                                        max=sum;
}
printf("%d  ", max);
	return 0;
}