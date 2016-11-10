
#include <stdio.h>

int main()
{int i;
    int x;
        unsigned long long a, z, array[100], b ,cv[100];
       ;
array[1] = 1;
array[2] = 2;
       scanf("%llu", &z);
i = 2;
    while (array[i] <= z){
i = i+1;
array[i]=array[i-1] + array[i-2];
    }
    for (x = 1; x <= i; x++)
cv[x] = 0;
b = i;
a = z;
    while (a>0) {
        while (a < array[b])
b = b-1;
cv[b] = 1;
a = a - array[b];
    }
    for (x = i-1; x >= 1; x--)
        printf("%llu", cv[x]);
        return 0;
}

