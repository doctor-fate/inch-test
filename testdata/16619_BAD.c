#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *fibstr(int n) {
        char *fib, *s1,*s2;
        int a,b,c,i;
        a = b = 1;
        c = i = 0;
        for (i=3;i<=n;i++) {
                c = a + b;
                a = b;
                b = c;
        }       
	s1 = (char*)malloc(c+1);
       	s2 = (char*)malloc(c+1);
        fib = (char*)malloc(c+1);
        strcpy(s1,"a");
        strcpy(s2,"b");
	strcpy(fib,"");
        for (i=3;i<=n;i++) {
                if (i == 3) {
                        strcat(fib, s1);
                        strcat(fib, s2);
                        strcpy(s1,s2);
                        strcpy(s2,fib);
                }
        else { 
                if (i%2) {
                        strcat(fib, s1);
                        strcpy(s1,s2);
                        strcpy(s2,fib);
                }
                else { 
                        strcat(s1, fib);
                        strcpy(s2,s1);
                }              
                }
        }
        if (i % 2) {       
                free (s2);
                free (fib);
                return s1;
        }
        else {
                free (s1);
                free (s2);
                return fib;
        }       
}
int main() {
        
        int n;
	n = 0;
        scanf("%i", &n);
        if (n==1) {
                printf ("a");
                return 0;
        }
        if (n==2) {
                printf ("b");
                return 0;
        }
        char *str; 
	str = fibstr(n);
        printf ("%s", str);
	free (str);
        return 0;
}