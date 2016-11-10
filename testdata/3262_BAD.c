#include <stdio.h>
int main (int argc, char **argv)
{
unsigned long a = 1, b = 0, x, f = 0;
scanf("%ld", &x);
if ( x==0) 
printf ("0") ;
else 
    {
while (f <= x) 
        {
        	f = a + b;
		b = a;
		a = f;
	}
        		if (x!=0) 
        		{
				x -= b;
				printf("1");
			}
				while (x > 0)
                		{
				a = f - b;
				if (a > x)
                		printf("0");
				else 
                		{
					x -= a;
					printf("1");
				}
		f = b;
		b = a;
	}
	
        while (f > 2)
        {
		a = f - b;
		f = b;
		b = a;
		printf("0");
	}
     }
     return 0 ;
}