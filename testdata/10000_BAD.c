void revarray(void *base, unsigned long nel, unsigned long width)
{
long i, k ;
char *bit1, *bit, L;
for ( i = 0 ; i < (nel/2) ; i++ )
        {
	bit1 = ((char *)base + (i)*width) ;
	bit =  ((char *)base + (nel-i-1)*width) ;
		for ( k = 0; k < width; k++)
			{
			L = *(bit1+ k*sizeof(char)) ;
			*(bit1 + k*sizeof(char)) = *(bit + k*sizeof(char)) ;
			*(bit+ k*sizeof(char)) = L ;
			}
	}
}