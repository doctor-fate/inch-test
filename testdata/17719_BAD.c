int strdiff(char *a, char *b)
{
long long l1 = 0, l2 = 0, l = 0;
l1 = strlen(a);
l2 = strlen(b);
if (l1 > l2)  l = l2; else l = l1;
for (int i = 0; i <= l; i++)
    if (a[i] != b[i]){
        int c = 0;
        while (a[i] % 2 == b[i] % 2){ a[i]=  a[i]/2; b[i] = b[i]/2; c++;}
        c = ((i)*8 + c);
        return c;}
if (l1 == l2) return -1; else return ((l * 8) - 1);
return 0;
}
