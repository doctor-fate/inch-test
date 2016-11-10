#include <stdio.h>
int set_bit (int val, int number);
int get_bit (int val, int number);

int main () {
int size_a, size_b;
int set_a, set_b, set_inter;
int tmp_in;
int i;
scanf ("%d", &size_a); 
set_a=0;
for (i=0; i<size_a; i++) {
  scanf ("%d", &tmp_in);
  set_a = set_bit (set_a, tmp_in);
  }
scanf ("%d", &size_b);
set_b=0;
for (i=0; i<size_b; i++) {
  scanf ("%d", &tmp_in);
  set_b = set_bit (set_b, tmp_in);
  }
set_inter = set_a & set_b;
for (i=0; i<32; i++)
  if (get_bit (set_inter, i))
    printf ("%d ", i);
}

int set_bit (int val, int number) {
return (val | (1 << number));
}

int get_bit (int val, int number) {
if (val & (1 << number))
  return 1;
  else return 0;
}