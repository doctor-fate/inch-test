
#include <stdio.h>

#define N 1300000
   
    unsigned int a[N];
    int main(){
     int i,s,j;
     int x,delitel;
  scanf("%d",&x);
  if (x<0) x=x*(-1);
  
 for( i=0; i<N; i++){ 
           a[i] = i;
       }
      
       a[1]=0;
       for( s=2; s<N; s++){
           if(a[s]!=0){
               for( j=s*2; j<N; j+=s){
                   a[j]=0;
               }
           }
       }
       
       for(i=0;i<N;i++)
       if (a[i]!=0&&x%a[i]==0) delitel=a[i];
       
       
       
       
  
  
  
  
  
  
  
 
          
  

  
  printf("%d",delitel);
  
       
  return 0;     
       
    }