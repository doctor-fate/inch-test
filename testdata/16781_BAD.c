#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long fib_f (int n);
char *fibstr(int n);

int main () {
int n;
char *res;

scanf ("%d", &n);
res=fibstr (n);
printf ("%s\n", res);
free (res);
return 0;
}

unsigned long fib_f (int n) {
unsigned long cur_fib=1, prev_fib=1;
unsigned long tmp;
int cur_ind=2;
int prev_ind=1;

while (cur_ind<n) {
  tmp=prev_fib;
  prev_fib=cur_fib;
  prev_ind=cur_ind;
  cur_fib=tmp+prev_fib;
  cur_ind++;
  }
return (cur_fib);
}

char *fibstr(int n) {
char *prev_str;
char *cur_str;
char *helper;
int i;
unsigned long quant;

quant=fib_f (n);
prev_str=(char*)malloc (quant+1);
cur_str=(char*)malloc (quant+1);
strcpy (prev_str, "a");
strcpy (cur_str, "b");
if (n==1) {
  free (cur_str);
  return (prev_str);
  }
else if (n==2) {
  free (prev_str);
  return (cur_str);
  }
else for (i=2; i<n; i++) {
  strcat (prev_str, cur_str);
  helper=prev_str;
  prev_str=cur_str;
  cur_str=helper;
  }
free (prev_str);
return (cur_str);
}