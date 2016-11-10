#include <stdio.h>
main ( int argc, char **argv) 
{
        long Z = 0, M = 0, l = 0,  k, i, w = 0, N ;
        scanf ("%ld", &i) ;
        long a[i] ;
        while ( w < i )
	{
	scanf ("%ld", &a[w]) ;
	w++;
	}
	scanf ("%ld", &k) ;
	while ( l < k) 
	{
 	M = M + a[l] ;
	l++;
	} 
	l = 0 ;
	N = M;
	while  ( k < i)
	{
	Z = M + a[k] - a[l] ;
	if ( Z > N)     {
 			 N = Z ; 
			 Z = 0 ;
			}
	else Z = 0;
	M = M + a[k] - a[l] ;
	k++;
	l++;
	}
	printf ("%ld\n", N) ;
        return 0 ;
}