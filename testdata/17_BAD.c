
#include <stdio.h>

int main()
{
        long smax, size, s, i, j, m, k;
        scanf ("%ld", &size);
        long A [size];
        for (i = 0; i <= size - 1; ++i) 
        {
		    A[i] = 0;
		    scanf("%ld",&A[i]);
	    }
	    k = 0;
	    scanf ("%ld", &k);
        m = 0;
        smax = s = 0;
        for (i = 0; i < k ; i++) 
		    smax += A[i];
        s = smax;
        for (j = k; j <= size - 1; j++)
        {
        s = s - A[m++];
        s = s + A[j];
        if (s > smax)
            smax = s;
        }
        printf("%ld", smax);
    
        return 0;
}

