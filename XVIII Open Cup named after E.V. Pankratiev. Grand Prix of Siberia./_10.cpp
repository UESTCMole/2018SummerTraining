#include<stdio.h>
char a[10];
char b[10];
int n,m;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i=1;i<=6;i++)
		scanf(" %c",&a[i]);
	for(int i=1;i<=6;i++)
		scanf(" %c",&b[i]);
		
	for(int i=1;i<=6;i++)
	{
		if(a[i]<b[i]) n++;
		else if(a[i]>b[i]) m++;
	}
	printf("%d\n%d",n,m);
	return 0;
}
