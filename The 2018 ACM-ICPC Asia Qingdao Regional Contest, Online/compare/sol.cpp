#include<stdio.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
int T;
int n;
long long a,b,c,d,v,t;
long long gcd(long long a,long long b)
{
	if (a==0) return (b);
	else return gcd(b%a,a);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		if(a>c)
		{
			swap(a,c);
			swap(b,d);
		}
		long long bound=a*c/gcd(a,c);
		long long x=1;
		long long ans0=b+d-1;
		long long ans=0;
		long long last=0;
		long long add=0;
		long long p=t%bound;
		bool sign=0;
		for(long long now=a;now<=bound;now+=a)
		{
			if(now>=c*x)
			{
				if(c*x>p&&sign==0&&p!=0) sign=1,add=ans;
				if(c*x-last<=v) ans+=d;
				else ans+=d-1;
				last=now;
				x++;
			}
			if(now>p&&sign==0&&p!=0) sign=1,add=ans;
			if(now-last<=v) ans+=b;
			else ans+=b-1;
			last=now;
		}
		{
			ans*=t/bound;
			ans+=add+ans0;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
