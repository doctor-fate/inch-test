#include <stdio.h>

int main(int argc, char **argv)

{
        int n,m,i,j,k;
	int max,min,nom_i,nom_j,Pr;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[n][m];
	for (i=0;i<n;i++)
		for (j=0;j<m;scanf("%d",&a[i][j]),j++);
	nom_i=nom_j=-1;
	for (Pr=0,k=0;k<n;k++) {
		for (max=a[k][0],nom_j=0,j=1;j<m;j++)
			if (a[k][j]>max) {
				max=a[k][j];
				nom_j=j;
				}
		for (min=a[0][nom_j],nom_i=nom_j,i=1;i<n;i++)
			if (a[i][nom_j]<min) {
				min=a[i][nom_j];
				nom_i=i;
				}
			if (min==max) {
				printf("%d %d \n", nom_i,nom_j);
				Pr=1;
				}
		}
if (Pr==0) printf("none \n");

return 0;
}
