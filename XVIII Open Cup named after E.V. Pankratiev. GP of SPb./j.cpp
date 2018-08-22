#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define pii pair<long long,long long>
long long n;
long long a[200005];
long long b[200005];
long long t[200005];
long long val;
long long tim;
long long less_;
long long greater_;
long long num;
pair<long long,long long>p[200005];
struct cmp
{
	bool operator()(pii p1,pii p2)
	{
		return p1.first>p2.first; 
	}
};
priority_queue<pii,vector<pii>,cmp>q;
void build(long long v)
{
	long long l,r;
	for(long long i=1;i<=n;i++)
	{
		l=1; r=n;
		t[i]=n+1;
		while(l<=r)
		{
			long long m=(l+r)/2;
			if(b[i]+a[m]>=v) t[i]=min(t[i],m),r=m-1;
			else if(b[i]+a[m]<v) l=m+1;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(t[i]>n) continue;
		p[i].first=b[i]+a[t[i]];
		p[i].second=i;
		q.push(p[i]);
	}
}
long long find()
{
	long long l,r;
	long long v=2e9+7;
	for(long long i=1;i<=n;i++)
	{
		l=1; r=n;
		while(l<=r)
		{
			long long m=(l+r)/2;
			if(b[i]+a[m]>val) v=min(v,b[i]+a[m]),r=m-1;
			else if(b[i]+a[m]<=val) l=m+1;
		}
	}
	return v;
}
void check1(long long v)
{
	less_=0;
	long long l,r;
	long long pos;
	for(long long i=1;i<=n;i++)
	{
		l=1; r=n;
		pos=0;
		while(l<=r)
		{
			long long m=(l+r)/2;
			if(b[i]+a[m]<v) pos=max(pos,m),l=m+1;
			else if(b[i]+a[m]>=v) r=m-1;
		}
		less_+=pos;
	}
}
void check2(long long v)
{
	greater_=0;
	long long l,r;
	long long pos;
	for(long long i=1;i<=n;i++)
	{
		l=1; r=n;
		pos=n+1;
		while(l<=r)
		{
			long long m=(l+r)/2;
			if(b[i]+a[m]>v) pos=min(pos,m),r=m-1;
			else if(b[i]+a[m]<=v) l=m+1;
		}
		greater_+=n-pos+1;
	}
}
int main()
{
//	freopen("J.in","r",stdin);
//	freopen("J.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	long long tot=n*n;
	long long low=n*(n-1)/2;
	long long vl=a[1]+b[1],vr=a[n]+b[n];
	while(vl<=vr)
	{
		long long vm=(vl+vr)/2;
		check1(vm);
		check2(vm);
		if(less_<=low&&low+1<=tot-greater_)
		{
			val=vm;
			break;
		}
		else if(less_>low) vr=vm-1;
		else if(low+1>tot-greater_) vl=vm+1;
//		else printf("wtf?");//code error
	}
	num=tot-greater_-less_;
	long long tmp=num+less_-low;
	if(tmp>=n)
	{
		for(long long i=1;i<=n;i++)
			printf("%lld ",val);
		return 0;
	}
	for(long long i=1;i<=tmp;i++)
		printf("%lld ",val);
	tim=n-tmp;
	val=find();
	build(val);
	for(long long i=1;i<=tim;i++)
	{
		pii x=q.top();
		q.pop();
		printf("%lld ",x.first);
		t[x.second]++;
		if(t[x.second]<=n)
		{
			x.first=b[x.second]+a[t[x.second]];
			q.push(x);
		}
	}
//	printf("%d %d %d",val,less_,greater_);
	return 0;
}
