
#include <stdio.h>

int main()
{
        int a[8], b[8], i, c, s, j, k, n;
        for (i = 0; i < 8; i++) scanf ("%d", &a[i]);
        for (i = 0; i < 8; i++) scanf ("%d", &b[i]);
        i = 0;
        n = 0;
         while (i < 8) {
                 c = 1;
                 s = 0;
        for (j = 0; j < 8; j++) {
                if ((a[i] == a[j]) && (i != j)) c++;
                }
        for (k = 0; k < 8; k++) if (a[i] == b[k]) s++;      
        if (c != s) {
                printf ("no\n");
                break;
        } else n++;
        i++;
        }
        if (n != 0) printf ("yes\n");
	return 0;
} 
