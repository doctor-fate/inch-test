void revarray(void *base, unsigned long nel, unsigned long width) 
{ 


unsigned long a1, a2, a3;
long long a[width],a4;


a1 = width;
a2 = nel;
a3 = a2 - 1;
for (a4 = 0;a4 < ( a2 / 2 ); a4++)
{
memcpy (a, ( a1 * a4 + base), a1);
memcpy ( ( a1 * a4 + base ), ( ( a3 - a4 ) * a1 + base ), a1);
memcpy ( ( a1 * ( a3 - a4 ) + base), a, a1); 
}
}