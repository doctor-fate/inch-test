#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10000
char *concat (char **s, int n);

int  main () {
char ** str_arr;
int str_count;
char *res_str;
int i;

scanf("%d ", &str_count);
str_arr = (char **) malloc(str_count*sizeof(char*));
for (i=0; i<str_count; i++) {
  str_arr[i]=(char*) malloc(MAX_LEN);
  gets (str_arr[i]);
  }
res_str=concat(str_arr, str_count); 
printf ("%s\n", res_str);
free (res_str);
for (i=0; i<str_count; i++)
  free (str_arr[i]);
free (str_arr);
return 0;
}

char *concat (char **s, int n) {
char *res_str;
int sum_len=0;
int i;
for (i=0; i<n; i++)
  sum_len+=strlen(s[i]);
res_str=(char*)malloc(sum_len+1);
strncpy (res_str, s[0], strlen (s[0])+1);
for (i=1; i<n; i++)
  strncat (res_str, s[i], strlen (s[i])+1);
return (res_str);
}