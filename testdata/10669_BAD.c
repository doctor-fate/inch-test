#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
 

int maxarray(void *base, unsigned long nel, unsigned long width, int (*compare)(void *a, void *b)) 
{ 
        void *p = malloc(width);
	int i = 0;
	int k = 0;
	memcpy(p, base, width);
	for(i = 1; i < nel; i++)
	{
		if(compare(p, (base+i*width)) < 0)
		{
		memcpy(p, (base + i*width), width);
		k = i;
		}
	}
	free(p);
	return k;
}