#include <stdio.h>


unsigned int powr(int x, int y)
{
    if(y){
        if(y%2)  return x*powr(x,y-1);
	else return powr(x*x,y/2);
    } else return 1;

}

int main(int argc, char **argv)
{

int n,i,j;
unsigned int ma=0, mb=0, mc, et;

scanf("%d", &n);

for(i=0; i<n; i++) {
    
    scanf("%d", &j);
    ma += powr(2,31-j);  

}

scanf("%d", &n);

for(i=0; i<n; i++) {
    
    scanf("%d", &j);
    mb += powr(2,31-j);
    
}

mc = ma&mb;
et = powr(2,31);

//printf("%d\n",mc);

for(i=0; i<32;i++) {
    
    if(mc>=et) printf("%d ",i);
    mc = mc << 1;
}


//printf("%d\n", powr(2,j));


return 0;
}