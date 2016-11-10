
int maxarray(void *base, unsigned long nel, unsigned long width, 
        int (*compare)(void *a, void *b)) 
{ int sr,max;
  int i;

 if (nel==1) return 0;
   max=0;

for (i=0;i<nel-1;i++){
  sr=compare(base+max*width,base+(i+1)*width);

  if (sr<0)
    max=i+1;
  //printf("%d\n",max);
}
     //
  return max;
}