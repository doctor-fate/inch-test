
#include <math.h>
#include <stdio.h>
#define N 32

long create_mnozh(int kol) {
int i, k;
long cod_ir = 0;
    for(i = 0; i < kol; i++) {
        scanf("%d", &k);
        cod_ir += pow(2, k);
    }
return cod_ir;
}

int max_element(long mnozh) {
int max = 0;
if (mnozh >= 0) {
    while ((mnozh - pow(2, max)) >= 0)
    max++;
}
max--;
return max;
}

int main(void) {
int A[N];
long mnozh_1 = 0, mnozh_2 = 0;
int n_1, n_2, max_1 = 0, max_2 = 0, i, j;
scanf("%d", &n_1);
mnozh_1 = create_mnozh(n_1);
scanf("%d", &n_2);
mnozh_2 = create_mnozh(n_2);
for (i = 0; i < 32; i++)
A[N] = 0;
i = 0;
while (mnozh_1 != 0 && mnozh_2 != 0) {
    max_1 = max_element(mnozh_1);
    max_2 = max_element(mnozh_2);
    if (max_1 > max_2) mnozh_1 -= pow(2, max_1); else {
        if (max_1 < max_2) mnozh_2 -= pow(2, max_2); else {
           if (max_1 == max_2) {
                A[i] = max_1;
                i++;
                //printf(" %d\r", max_1);
                mnozh_1 -= pow(2, max_1);
                mnozh_2 -= pow(2, max_2);
            }
        }
    }
    if (mnozh_1 == 0 || mnozh_2 == 0) break;
}
for (j = (i - 1); j >= 0; j--)
printf("%d ", A[j]);
return 0;
}