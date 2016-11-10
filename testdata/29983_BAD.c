#include <stdio.h>
#include <stdlib.h>

int main()
{  
        struct Date { int day, month, year; };
         int i, n;
    
    scanf ("%d", &n);
	struct Date mas[n], mas1[n];
    
void sort (int marker, int range)
    {
    	  int i, temp, save[1000];
       
        for(i=0;i<100;i++)
        save[i]=0;
        
        if (marker == 1) {
            for (i = 0; i < n; i++) {
                temp = mas[i].day-1;
                save[temp]++;
            }
            
               for (i = 1; i < range; i++) 
              save[i] += save[i - 1];
        
        
        for (i = n - 1; i >= 0; i--) 
            {
                temp = mas[i].day - 1;
                mas1[--save[temp]] = mas[i];
            }
        
        }
        else if (marker == 2) {
               
                for (i = 0; i < n; i++) {
                    temp = mas[i].month - 1;
                    save[temp]++;
                }
                
                for (i = 1; i < range; i++) 
              save[i] += save[i - 1];
              
              
              for (i = n - 1; i >= 0; i--)
                {
                    temp = mas[i].month - 1;
                    mas1[--save[temp]] = mas[i];
                }
              
            }
            else {
                for (i = 0; i < n; i++) {
                temp = mas[i].year - 1970;
                    save[temp]++;
                }
                
                for (i = 1; i < range; i++) 
              save[i] += save[i - 1];
              
              for (i = n - 1; i >= 0; i--) {
                    temp = mas[i].year - 1970;
                    mas1[--save[temp]] = mas[i];
                }
            }
     

              for (i = 0; i < n; i++) 
               mas[i] = mas1[i];
    }

    
    for (i = 0; i < n; i++) 
    scanf ("%d %d %d", &mas[i].year, &mas[i].month, &mas[i].day);
    

    
    sort (1, 31);
    sort (2, 12);
    sort (3,61);

    for (i = 0; i < n; i++) {
        printf ("%d ", mas[i].year);

            printf ("%d ", mas[i].month);
            printf ("%d\n", mas[i].day);
    }
    return 0;
}