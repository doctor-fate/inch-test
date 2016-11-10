#include <stdio.h>
#include <string.h>
void revarray(void *base, unsigned long nel, unsigned long width) 
{

unsigned long i,j;

  char k[width];

   
 for (i=0,j=nel-1; i<nel/2; i++,j--) {
    memcpy(k, base+width*j , width);                //k=a[j];
    memcpy(base+width*j , base+width*i , width );                    //a[j]=a[i];
    memcpy( base+width*i , k, width);            //a[i]=k;
 }               
}