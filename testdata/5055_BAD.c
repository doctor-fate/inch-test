
#include <stdio.h>

int main(int argc, char **argv)
{
        int i = 0;
        int n = 8;
        int a1[n], a2[n], a0[n];
        
        for (i = 0; i < n; i++) scanf("%d", &a1[i]);
        
        for (i = 0; i < n; i++) scanf("%d", &a2[i]);
        
        for (i = 0; i < n; i++) a0[i] = 0;
        
        int j = 0;
        
        for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
	        if ((a1[i] == a2[j]) & (a0[j] == 0)) {
		a0[j] = 1;
		break;
	        }
	}
        }
        
        int m = 0;
        for (i = 0; i < n; i++) {
	if (a0[i] == 1) m++;
        }
        
        if (m == n) printf("yes\n");
	else printf("no\n");
        return 0;
}
