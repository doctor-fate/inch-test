
unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{

        unsigned long  number1 = 0, i ;
        unsigned long number = nel - 1 ;
	for(; number1 <= number;)  
	{
	i =(number1 + number )/ 2 ;
	if( compare(i) > 0) number = i - 1;
	else if(compare(i) < 0) number1 = i + 1 ;
	else return i; 
	}					
				
      return nel; 
}