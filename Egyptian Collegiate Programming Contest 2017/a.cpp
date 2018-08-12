#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int T;
int n,x,y,k;
double p;
double A[52][52][2];
int last,now;
double pr=1;
int main()
{
	freopen("assessment.in","r",stdin);
	scanf("%d",&T);
	int it=0;
	while(T--)
	{
		it++;
		scanf("%d%lf%d%d%d",&n,&p,&x,&y,&k);
		if(n==1)
		{
			printf("Case %d: %.5lf\n",it,pr);
			continue;
		}
		memset(A,0,sizeof(A));
		A[x][y][0]=1;
		last=0;
		now=0; 
		while(k--)
		{
			if(last==1) now=0;
			else now=1;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					A[i][j][now]=0;
			for(int i=1;i<n;i++)//swap(i-1,i)
			{
				A[i][i-1][now]+=A[i-1][i][last]*p/(double)(n-1);
				A[i-1][i][now]+=A[i][i-1][last]*p/(double)(n-1);
				A[i][i][now]+=A[i-1][i-1][last]*p/(double)(n-1);
				A[i-1][i-1][now]+=A[i][i][last]*p/(double)(n-1);
				for(int j=0;j<n;j++)
				{
					if(j==i||j==i-1)continue;
					A[i][j][now]+=A[i-1][j][last]*p/(double)(n-1);
					A[j][i][now]+=A[j][i-1][last]*p/(double)(n-1);
					A[i-1][j][now]+=A[i][j][last]*p/(double)(n-1);
					A[j][i-1][now]+=A[j][i][last]*p/(double)(n-1);
				}
			}
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					int pos=0;
					int a=i,b=j;
					if(a>b)swap(a,b);
					if(a-0>=2) pos+=a-1;
					if(b-a>=3) pos+=b-a-2;
					if(n-1-b>=2) pos+=n-1-b-1;
					A[i][j][now]+=A[i][j][last]*p*(double)pos/(double)(n-1);//swap other place
					A[i][j][now]+=A[i][j][last]*(1-p);//no swap
				}
			last=now;
		}
		printf("Case %d: %.5lf\n",it,A[y][x][now]);
	}
	return 0;
}
