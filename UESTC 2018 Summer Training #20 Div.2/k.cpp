#include<stdio.h>
int n;
int x[1005];
int y[1005];
int ma[2000][2000];
int x_1,x_2,x_3,x_4,x_5,x_6;
int y_1,y_2,y_3,y_4,y_5,y_6;
int ans;
int main()
{
	int it=0;
	while(scanf("%d",&n)!=EOF)
	{
		it++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			x[i]+=500;
			y[i]+=500;
			ma[x[i]][y[i]]=it;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				int ddx=x[j]-x[i];
				int ddy=y[j]-y[i];
				int dx=-ddy;
				int dy=ddx;
				x_1=x[i]+dx;
				y_1=y[i]+dy;
				x_2=x[j]+dx;
				y_2=y[j]+dy;
				x_3=x[i]-dx;
				y_3=y[i]-dy;
				x_4=x[j]-dx;
				y_4=y[j]-dy;
				/*x_5=(x[i]+x_2)/2;
				y_5=(y[i]+y_2)/2;
				x_6=(x[i]+x_4)/2;
				y_6=(y[i]+y_4)/2;*/
				if(ma[x_1][y_1]==it&&ma[x_2][y_2]==it) ans++;
				if(ma[x_3][y_3]==it&&ma[x_4][y_4]==it) ans++;
	//			if(ma[x_5][y_5]==it&&ma[x_6][y_6]==it) ans++;
			}
		}
		printf("%d\n",ans/8);
	}
	return 0;
}
