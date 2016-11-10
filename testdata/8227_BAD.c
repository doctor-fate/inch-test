#include <stdio.h> 
main ( int argc, char **argv)
{
        long a, b = 2, c = 1, k = 2;
        scanf("%ld", &a);
        if ( a < 0) 
        a = -1 * a ;
	while ( c*c <= a )
	{
	c++ ;
	}
	long r[c] ;
	while ( b <= c ) 
	{
	r[b - 1] = b ;
	b++ ;
	}

	repeat : 
	k = 1 ;
	while (k < c )
	{
	if ( a == r[k]) break ;
	if ( a%r[k]==0 ) 
		{
		 a = a / r[k] ;
			if ( a != r[k] )
			{
			while ( c > 0 )
			{
			if ( a % r[k] == 0) 
			a = a / r[k] ;
			else break; 
			}
			}	
       			
		}
	if ( a == r[k]) break ;
	k++;
	}
	
printf("%ld", a) ;
}