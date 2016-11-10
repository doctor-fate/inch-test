
#include <stdio.h>
int main()
{
    int masA[8] = {0}, masB[8] = {0}, i, j, flag = 0, flags[8] = {0} ;
    char flags1 = 0;
    for (i=0; i<8; i++)
        scanf("%d",&masA[i]); 
    for (i=0; i<8; i++)
        scanf("%d",&masB[i]);
        
        for (i=0; i<8; i++) {
            for (j=0; j<8; j++)
            if ((masA[i] == masB[j]) && (flags[j] == 0)){
                flags[j] = 1;
                flag = 1;
                break;
            }
            else if (j == 7)
                     flag = 0;
            if (flag == 0)
                break;
        } 
    if (flag == 1)
        printf (" yes ");
    if ( flag == 0)
        printf (" no ");
        return 0;
}
