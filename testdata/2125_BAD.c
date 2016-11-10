#include <stdio.h>

unsigned long power_il(long a, long b){
    
    if(b == 0) return 1;
    else if(b%2) return a*power_il(a,b-1);
    else return power_il(a*a, (b/2));
    
}

int main(int argc, char **argv)
{

unsigned long a,b,m,x,p,h,t;

scanf("%lu",&a);
scanf("%lu",&b);
scanf("%lu",&m);

int n;

x=b;
n=64;
p=power_il(2,63);

while(x<p){
x=x<<1;
n--;    
}

int i;
h=0;

    if(x>=p) t=1;
    else t=0;
    
    h=((a%m)*(t%m))%m;

for(i=n-1; i>0; i--){
    x=x<<1;
    if(x>=p) t=1;
    else t=0;
    
    h=((((h%m)*(2%m))%m)+(((a%m)*(t%m))%m))%m;        
}

printf("%lu\n",h);


return 0;

}