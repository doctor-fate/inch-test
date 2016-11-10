#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
unsigned long long a=0,b=0,m=1;
unsigned long long p1=0;
int i=0;

  scanf("%lld %lld %lld", &a , &b , &m);
 
int mass[64];

  for(i=63;i>=0;i--)//задаем массив b(переводим 10->2 основание)
 {
   mass[i]= b%2;
   b = b/2;
 }

  for(i=0;i<64;i++)
 {
   p1=(p1*mass[i]*a*2)%m;//задаем выражение (a*b)mod m
 }

  for(i=1;i<64;i++)
 {
   p1=(((p1*(2 % m)) % m) + ((a * mass[i]) % m)) % m;//достаточное условие (x+y)mod m
 }

  printf("%lld\n", p1);
   
 return 0;
}