#include <stdio.h>
#include <math.h> 
main ( int argc, char **argv)
{
        long a, k, c, d = 0, w = 0, g=0, i = 0, j = 0, v ;
	scanf ("%ld", &a) ;
	while ( a > 0)
	{
	scanf ("%ld", &v) ;
	d = d + pow(2, v) ;
	a--;
	}
	scanf ("%ld", &c);
	while ( c > 0)
	{
	scanf ("%ld", &k);
	w = w  + pow(2, k) ;
	c--;
	}
	g = ( d & w) ;
	while ( i <= 31 )
	{
	k = (g % 2) ;
	if ( k == 1)
	printf ("%ld ", i ) ;
	i++ ;
	g = ( g - (g % 2)) / 2 ;
	}
}