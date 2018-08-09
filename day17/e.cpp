#include<stdio.h>
#include<string.h>
int n,q;
long long a[100005];
long long mi[60];
int cnt[60];
int main()
{
	mi[0]=1;
	for(int i=1;i<=40;i++) mi[i]=mi[i-1]*2;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			for(int j=0;j<=33;j++)
			{
				if(a[i]&mi[j])
				{
					cnt[j]++;
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			int x;
			scanf("%d",&x);
			int num;
			long long and_=0;
			long long or_=0;
			long long xor_=0;
			for(int i=0;i<=33;i++)
			{
				if(a[x]&mi[i]) num=cnt[i]-1;
				else num=cnt[i];
				if(num) or_+=mi[i];
				if(num%2) xor_+=mi[i];
				if(num==n-1) and_+=mi[i];
			}
			printf("%lld %lld %lld\n",and_,or_,xor_);
		}
	}
	
	return 0;
}