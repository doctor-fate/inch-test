void bubblesort(unsigned long nel,
int (*compare)(unsigned long i, unsigned long j),
void (*swap)(unsigned long i, unsigned long j))
{
int i=0,a=0,t,bound=0;
t=nel-1;
while ((t-a)>0){

bound=t;
t=a;
i=a;
while (i<bound){
if (compare(i+1, i)==-1){
swap(i+1,i);
t=i;
}
i++;
}


bound=a;
a=t;
i=t;
while (i>bound){
if (compare(i-1, i)==1){
swap(i-1,i);
a=i;
}
i--;
}

}
}