#include <stdio.h>
#include <stdlib.h>

long max(long a, long b){
        if (a>b) return a; else return b;
}
long min(long a, long b){
        if (a<b) return a; else return b;
}

struct stack{
        long cap, top, data[0];
};

struct stack *initstack(long n){
        struct stack *s=(struct stack*)malloc(sizeof(struct stack) + n*sizeof(long));
        s->cap = n;
        s->top=0;
        long i=0;
        for (i=0;i<n;i++) s->data[i]=0;
        return s;
}

void push(struct stack *s, long x){
        s->data[s->top]=x;
        s->top++;
}

long pop(struct stack *s){
        s->top--;
        return s->data[s->top];
}

int main(){
        long n;
        scanf ("%ld", &n);
        long i;
        char word[6];
        long a, b;
        struct stack *s=initstack(n);
        for (i=0;i<n;i++){
                scanf ("%s", word);
                if (word[0]=='C'){
                        scanf ("%ld", &a);
                        push(s, a);
                }
                if (word[0]=='A') push(s, pop(s)+pop(s));
                if (word[0]=='S' && word[1]=='U') push(s, pop(s)-pop(s));
                if (word[0]=='M' && word[1]=='U') push(s, pop(s)*pop(s));
                if (word[0]=='D' && word[1]=='I') push(s, pop(s)/pop(s));
                if (word[0]=='M' && word[1]=='A') push(s, max(pop(s), pop(s)));
                if (word[0]=='M' && word[1]=='I') push(s, min(pop(s), pop(s)));
                if (word[0]=='N') push(s, -pop(s));
                if (word[0]=='D'){
                        a=pop(s);
                        push(s, a);
                        push(s, a);
                }
                if (word[0]=='S' && word[1]=='W'){
                        a=pop(s);
                        b=pop(s);
                        push(s, b);
                        push(s, a);
                }
        }
        printf("%ld\n", pop(s));
        free(s);
        return 0;
}