#include <stdio.h>

int main () {
int am, k;
int i;
int *arr;
int start_ind, end_ind;
long sum, max_sum;
arr = (int*)malloc(1000000*sizeof(int));
if (arr==NULL) 
  return -1;
scanf ("%d", &am);
for (i=0; i<am; i++)
  scanf ("%d", &arr[i]);
scanf ("%d", &k);
start_ind = 0;
end_ind = k-1;
sum = 0;
for (i=start_ind; i<=end_ind; i++)
  sum += arr[i];
max_sum = sum;
while (end_ind<am-1) {
  sum-=arr[start_ind];
  start_ind++;
  end_ind++;
  sum+=arr[end_ind];
  if (sum>max_sum)
    max_sum = sum;
  }
printf ("%ld\n", max_sum);
free (arr);
return 0;
}