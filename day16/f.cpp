#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
int n,m;
int a[100005];
int b[100005];
int f[100005];
int vis[100005];
int cir[100005];
int now;
long long ans;
void dfs(int x,int dep)
{
	vis[x]=1;
	if(vis[b[x]])
	{
		cir[dep]+=dep;
		return;
	}
	dfs(b[x],dep+1);
}
void dfs2(int x,int dep)
{
	vis[x]=1;
	if(vis[f[x]])
	{
		for(int i=1;i*i<=dep;i++)
		{
			if(dep%i) continue;
			now=(now+cir[i])%mod;
			int k=dep/i;
			if(k!=i) now=(now+cir[k])%mod;
		}
		ans=(ans*(long long)now)%mod;
		return;
	}
	dfs2(f[x],dep+1);
}
int main()
{
	int it=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		it++;
		ans=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
			f[i]=a[i];
		for(int i=0;i<m;i++)
		{
			if(vis[i]) continue;
			dfs(i,1);
		}
		for(int i=0;i<m;i++)
			vis[i]=0;
		ans=1;
		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			now=0;
			dfs2(i,1);
		}
		for(int i=0;i<n;i++)
			vis[i]=0;
		for(int i=1;i<=max(n,m);i++)
			cir[i]=0;
		printf("Case #%d: %lld\n",it,ans);
	}
	
	return 0;
}