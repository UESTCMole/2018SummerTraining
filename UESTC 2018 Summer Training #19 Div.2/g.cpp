#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int T;
int n,k;
int a[1005];
int vis[1005];
int m;
int s[1005];
int num[1005];
int cnt;
int ans;
void check(int d)
{
	int add=0;
	int cnt2;
	for(int i=d;i<=m;i++)
	{
		cnt2=0;
		for(int j=1;j*s[i]<=n;j++)
		{
			if(num[j*s[i]]%2) cnt2--;
			else cnt2++;
		}
		if(cnt2>0) add+=cnt2;
	}
	ans=max(ans,cnt+add);
}
void dfs(int d)
{
	if(s[d]>31||d>m)
	{
		check(d);
		return;
	}
	dfs(d+1);
	for(int i=1;i*s[d]<=n;i++)
	{
		num[i*s[d]]++;
		if(num[i*s[d]]%2) cnt++;
		else cnt--; 
	}
	dfs(d+1);
	for(int i=1;i*s[d]<=n;i++)
	{
		num[i*s[d]]--;
		if(num[i*s[d]]%2) cnt++;
		else cnt--;
	}
}
int main()
{
	scanf("%d",&T);
	int it=0;
	while(T--)
	{
		it++;
		scanf("%d%d",&n,&k);
		memset(vis,0,sizeof(vis));
		m=0;
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>n) continue;
			if(!vis[a[i]]) s[++m]=a[i];
			vis[a[i]]=1;
		}
		sort(s+1,s+1+m);
		cnt=0;
		ans=0;
		dfs(1);
		printf("Case #%d: %d\n",it,ans);
	}
	return 0;
}
