
#include <stdio.h>

int a[8], b[8],i, k, summ=0,dop[8];

int main()
{
    for (i=0; i<8; i++)
        scanf("%d", &a[i]);
    for (k=0; k<8; k++)
        scanf("%d", &b[k]);
    for (i=0; i<8; i++) {
        for (k=0; k<8; k++) {
            if ((a[i]==b[k])&&(dop[k]==0)) {
                dop[k]=1;
                summ+=1;
                break;
            }
        }
    }
    if (summ==8)
        printf("yes");
        else
            printf("no");
return 0;
}