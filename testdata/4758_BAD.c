#include <stdio.h>
main(){
int a[8], b[8],c=0,d=0,i;
for (i=1;i<9;++i){
scanf ("%d", &a[i]);}
for (i=1;i<9;++i) {
scanf ("%d", &b[i]);}
for (i=1;i<9;++i) {
c+=a[i];
} 
for (i=1;i<9;++i) {
d+=b[i];
} 
if (c==d) printf("yes\n\n");
else printf("no\n\n");
} 