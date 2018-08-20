#include<stdio.h>
#include<algorithm>
using namespace std;
int T;
int n;
int m[30];
char num,opt;
void rotate(int a,int b,int c,int d,char mode)
{
	if(mode=='C')//clockwise
	{
		swap(m[a],m[b]);
		swap(m[a],m[d]);
		swap(m[a],m[c]);
	}
	else if(mode=='R')//counterclockwise
	{
		swap(m[a],m[c]);
		swap(m[a],m[d]);
		swap(m[a],m[b]);
	}
}
void block(char a,char b)
{
	if(a=='1')
		rotate(1,2,4,5,b);
	else if(a=='2')
		rotate(2,3,5,6,b);
	else if(a=='3')
		rotate(4,5,7,8,b);
	else if(a=='4')
		rotate(5,6,8,9,b);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=9;i++)
				scanf(" %c",&m[i]);
		for(int i=1;i<=n;i++)
		{
			scanf(" %c%c",&num,&opt);
			block(num,opt);
		}
		for(int i=1;i<=3;i++)
			printf("%c",m[i]);
		printf("\n");
		for(int i=4;i<=6;i++)
			printf("%c",m[i]);
		printf("\n");
		for(int i=7;i<=9;i++)
			printf("%c",m[i]);
		printf("\n");
	}
	return 0;
}
