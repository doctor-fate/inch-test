unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i)) 
{  unsigned long x, y, c,p;

 if (nel>0){
         x = 0;
         y = nel-1;
 }
 else{
         x=nel+1;
         y=0;
 }
 while(x <= y) {
    c = (x+y)/2;
    if(compare(c)==1) y = c-1;
    else if(compare(c)==-1) x = c+1;
    else return c; 
 }
  return nel;
}