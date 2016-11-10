#include <stdio.h>
#include <stdlib.h>
unsigned long f (unsigned long x, int *fib_ind);

int main () {
unsigned long x;
unsigned long max_fib;
unsigned long cur_x;
char *ind_arr=NULL;
int max_ind;
int arr_size=0;
int i;

scanf ("%lu", &x);
cur_x=x;
while (cur_x>0) {
  max_fib=f(cur_x, &max_ind);
  if (arr_size==0) {
    ind_arr=(char*)malloc(max_ind+1);
    if (ind_arr==NULL) {
      printf ("Not enough memory");
      return -1;
      }
    arr_size=max_ind+1;
    for (i=0; i<arr_size; i++)
      ind_arr[i]=0;
    }
  ind_arr[max_ind]=1;
  cur_x-=max_fib;
  }
if (arr_size==0)
  printf ("%d\n", 0);
else {
  for (i=arr_size-1; i>=0; i--)
    printf ("%d", ind_arr[i]);
  printf ("\n");
  }
if (ind_arr!=NULL)
  free (ind_arr);
return 0;
}

unsigned long f (unsigned long x, int *fib_ind) {
unsigned long cur_fib=1, prev_fib=1;
unsigned long tmp;
int cur_ind=0;
int prev_ind=0;

while (cur_fib<=x) {
  tmp=prev_fib;
  prev_fib=cur_fib;
  prev_ind=cur_ind;
  cur_fib=tmp+prev_fib;
  cur_ind++;
  }
*fib_ind=prev_ind;
return (prev_fib);
}