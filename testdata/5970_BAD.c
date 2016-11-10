#include <stdio.h>
int main()
{
        int n, i, k, s, sm=0;
        scanf("%d", &n);
        int a[n];        
	for(i=1; i<=n; i++)
	        scanf("%d", &a[i]);
	scanf("%d", &k);		
	a[0]=k+1;
        s=0;	
	if (k == n)	
		for(i=1;i<=k;i++)
			sm=s=s+a[i];
	else{ 
		for(i=0;i<=k-1;i++)
			s=s+a[i];
			for(i=k;i<=n;i++){ 
				s=s+a[i]-a[i-k];
			if(s > sm) sm = s;}
	}			
	printf ("%d\n", sm);	
	return 0;
} 