#include <stdio.h>
int main()
{
int i, j, k=0, l=0;
int a[7], b[7];
        for(i=0; i<=7; i++){ 
		scanf("%d", &a[i]);
                }
	for(j=0; j<=7; j++){ 
		scanf("%d", &b[j]);
                }
	for(i=0; i<=7; i++){
		for(j=0; j<=7; j++){
			if (a[i] == b[j]) a[i] = b[j] = 0;
			}
		}
	for(i=0; i<=7; i++){
		if (a[i] == 0) k+=1;
                }
	for(j=0; j<=7; j++){
		if (b[j] == 0) l+=1;
                }
	if (k == 8 && l == 8) printf("yes\n");
		else printf("no\n");
	return 0;
} 