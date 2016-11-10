#include <stdio.h>

int main(int argc, char **argv)
{ 
        int n=8,k=8;
	int a[n], b[n],c[n],i,j,Pr,Fl,d;
	for (i=0;i<n; scanf("%d",&a[i]),i++);
	for (i=0;i<n; scanf("%d",&b[i]),c[i]=b[i],i++);
	for (Fl=1,i=0;i<n;i++) {
		for (Pr=0,j=0;j<k;) {
			if (a[i]!=c[j]) j++;
			else {
				d=c[j];
				c[j]=c[k-1];
				c[k-1]=d;
				Pr=1;
				k--;
				break;
				}
				}
		if (Pr==0) {
			Fl=0;
			break;
			}
			}
	if (Fl==0) printf("no");
	else printf("yes");
	return 0;
}