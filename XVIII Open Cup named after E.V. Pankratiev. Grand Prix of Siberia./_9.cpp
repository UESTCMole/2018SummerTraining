#include<stdio.h>
#define mod 1000000007
long long q,n;
long long p;
long long ksm(long long x,long long a)
{
	long long b=1;
	long long tmp=x;
	while(a)
	{
		if(a&1) b=(b*tmp)%p;
		tmp=(tmp*tmp)%p;
		a>>=1;
	}
	return b;
}
int cnt;
long long pri[1000005];
bool vis[10000005];
int maxn=10000000; 
void init()
{
    for(long long i=2;i<=maxn;i++)
    {
        if(!vis[i])
        {
        	pri[++cnt]=i;
//        	printf("%d ",i);
		}
        for(int j=1;j<=cnt&&i*pri[j]<=maxn;j++)
        {
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)
            	break;
        }
    }
}
int ans=0;
long long lis[10000005];
int main()
{
	init();
	scanf("%lld%lld",&q,&n);
	for(int i=1;i<=cnt;i++)
	{
		p=pri[i];
		if(n>=p)continue;
		if(q%p==0)continue;
		if(ksm(q,n)-1!=0)continue;
		bool sign=1;
		for(long long j=1;j*j<=p-1&&j<n;j++)
		{
			long long k=(p-1)/j;
			if(k*j!=p-1)continue;
			if(j<n&&ksm(q,j)-1==0)
			{
				sign=0;
				break;
			}
			if(k<n&&ksm(q,k)-1==0)
			{
				sign=0;
				break;
			}
		}
		if(sign) lis[++ans]=p;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
		printf("%lld ",lis[i]);
	return 0;
}
