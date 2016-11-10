#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long  x=0;
    unsigned long i=2;
    unsigned long mass[10000];
    unsigned long k=0;
  
    scanf("%lu", &x);
       if(x==1)
       {
        printf("1");
       }
       else
       {
        if(x==0)
       {
        printf("0");
       }
       
       else
       {

    mass[0]=mass[1]=1;
   for(i=2;mass[i-1]<=x;i++)//задаем массив чисел фиб
  {
   mass[i]=mass[i-2]+mass[i-1];
  }        


    for(k=i-2;k>0;k--)//сравниваем с числом фиб и записываем результат(0 или 1) 
    {
        if(x>=mass[k])
         {
          printf("1");
          
          x=x-mass[k];
         }
            else
            
            printf("0");
            
     }  
        }
        }
 return 0;
}