#include <stdio.h>

int main()
{
int k=0 , x , n=0 , i , j , a[8] , b[8];
i=0;
while(i<8)
{
scanf("%d",&a[i]);
i++;
}
i=0;
while(i<8)
{
scanf("%d",&b[i]);
i++;
}
i=0;
while(i<8)
{
        j=i;
	while(j<8)
{
	if (b[i]==a[j])
	{
	x=a[i];
	a[i]=a[j];
a[j]=x;
n++;
}
	j++;
}
i++;
}
i=0;
while(i<8)
{
	if(a[i]!=b[i])
	{
		printf("no");
		return 0;
	}
	i++;
}
printf("yes");
return 0;
}