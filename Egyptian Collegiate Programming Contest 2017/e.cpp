#include<stdio.h>
int T;
int n;
bool vis[100005];
int fa[100005];
long long size[100005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
struct Edge
{
	int u,v,w;
}E[100005];
struct edge
{
	int to;
	int next;
	int w;
}e[200005];
int cnt;
int head[100005];
void ins(int u,int v,int w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool check(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		int j=x/i;
		if(i*j!=x)continue;
		if(vis[i])continue;
		if(vis[j])continue;
		return 1;
	}
	return 0;
}
long long ans;
long long count(int x)
{
	long long sum1=0;
	long long sum2=0;
	long long sum3=0;
	for(int i=head[x];i;i=e[i].next)
	{
		int v=find(e[i].to);
		if(e[i].w==2) sum2+=size[v];
		else sum1+=size[v],sum3+=size[v]*size[v];
	}
	return sum2*size[x]+sum1*sum1-sum3;
}
int main()
{
	freopen("evaluations.in","r",stdin);
	for(int i=2;i<=100000;i++)
	{
		if(vis[i])continue;
//		printf("%d ",i);
		for(int j=2;j*i<=100000;j++)
			vis[j*i]=1;
	}
//	printf("\n");
	scanf("%d",&T);
	int it=0;
	while(T--)
	{
		it++;
		cnt=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			fa[i]=i,size[i]=1,head[i]=0;
		int u,v,w;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);
			u=E[i].u; v=E[i].v; w=E[i].w;
			if(w!=1) continue;
			size[u]+=size[v];
			fa[find(v)]=find(u);
		}
		for(int i=1;i<n;i++)
		{
			u=E[i].u; v=E[i].v; w=E[i].w;
			if(w==1) continue;
			if(vis[w]==0)
				ins(find(u),find(v),1),ins(find(v),find(u),1);
			else if(check(w))
				ins(find(u),find(v),2),ins(find(v),find(u),2);
		}
		for(int i=1;i<=n;i++)
			ans+=count(i);
		printf("Case %d: %lld\n",it,ans/2);
	}
	return 0;
}
