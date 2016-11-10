unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
        
  unsigned long  low=0,mid,high=nel;
   
   mid=(low+high)/2;
   
    while(high-low>1) 
     {
    	
  if (compare(mid)==-1) {
  	low=mid;
  	mid=(low+high)/2;
}
  
 if (compare(mid)==1) {
	high=mid;
	mid=(low+high)/2;
}

 if (compare(mid)==0) return mid;
 
      }
   
   return nel;
    
}
        
