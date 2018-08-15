#include<stdio.h>
#include<algorithm>
using namespace std;
int a1,a2,a3,a4;
int b1,b2,b3,b4;
int T;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		scanf("%d%d%d%d",&a3,&b3,&a4,&b4);
		if(a1<=a3&&b1<=b3&&a2>=a4&&b2>=b4)
		{
			printf("B in A\n");
			continue;
		}
		else if(a1>=a3&&b1>=b3&&a2<=a4&&b2<=b4)
		{
			printf("A in B\n");
			continue;
		}
		int up,down,left,right;
		up=max(b1,b3);
		down=min(b2,b4);
		left=max(a1,a3);
		right=min(a2,a4);
		if(up>down||left>right)
		{
			printf("Separate\n");
			continue;
		}
		else
		{
			printf("Intersect\n");
			continue;
		}
	}
}
