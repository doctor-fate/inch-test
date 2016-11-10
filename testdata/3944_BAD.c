#include <stdio.h>
#include <stdlib.h>

int arr2int()
{
    int array_size=0;
    int array=0;
    int k,c,i;
    scanf("%d",&array_size );
        for(i = 0; i < array_size; i++)
	{
		k=0;
		scanf("%d",&c );
		k=1<<c;
 		array=array|k;
	}
    return array;
}

int main ()
{
    int arrX,arrY,arrZ,i;
    
    arrX=arr2int();
    arrY=arr2int();
	arrZ = arrX & arrY;
    
	for(i = 0; i < 32 ; ++i)
	{
		if(arrZ & 1)
        {
            printf("%d ", i );
		}
        arrZ = arrZ >> 1;
	}
	return 0;
}
