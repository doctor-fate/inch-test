#include <stdio.h>

int main(int argc, char **argv)

{
    int i,a,b,n,k,f,g,c;

    c=0;
    a=0;
    b=0;
    i=0;
    f=0;
    g=0;

    scanf ("%d", &n);

    for (i=0; i<n; i++){
        scanf ("%d", &f);
        a=(1<<f)|a;
    }

    scanf ("%d", &k);

    for (i=0; i<k; i++){
        scanf ("%d", &g);
        b=(1<<g)|b;
    }

c=a&b;

    for (i=0; i<32; i++){

        if (c&1==1) printf ("%d ", i);
        c=(c>>1);

    }

    return 0;
}
