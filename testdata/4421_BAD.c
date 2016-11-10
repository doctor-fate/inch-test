#include <stdio.h>
int main()
{
 int a,b,x,y,i;
scanf("%d", &a);
int p = 0;
for(i=0; i<a; i++){
    scanf("%d", &x);
    p |= (1<<x);
}
scanf("%d", &b);
int c = 0;
for (i=0; i<b ;i++){
    scanf("%d", &y);
c |= (1<<y);
}
int h;
h = p & c;
int t = 1;
for(i=0; i<32; i++){
    if(h & t){
printf("%d ",i);
 }
 t *= 2;
}
return 0;
}
