#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    long int x, tempX,i,j;
    long int prime;
    char *arrX;
    
    scanf("%ld", &x);
    if(x<0)
        x=abs(x);
    tempX = x;
    x = sqrt(x);
    arrX = (char *)malloc((x/2 + 2) * sizeof(char));
    
    for(i = 0; i <= x/2 + 1; ++i)
        {
		arrX[i]=1;
	}
	
	for(i = 2; i <= x/2 + 1; ++i)
	{
		if(arrX[i])
		{
            prime = i;
            while (!(tempX%i)&&tempX!=i){
                tempX /= i;
            }
			for(j =i+prime; j < x/2 ; j=j+prime)
			{
                arrX[j]=0;
			}
		}
	}
    
    printf("%ld", tempX);
    free(arrX);
	return 0;
}
