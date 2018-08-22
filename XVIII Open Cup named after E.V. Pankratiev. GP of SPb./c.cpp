#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int a[20],b[20];
long long ans;
int main()
{
	freopen("chickens.in","r",stdin);
	freopen("chickens.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	ans=1;
	for(int i=n;i>=1;i--)
	{
		long long cnt=0;
		for(int j=n;j>=1;j--)
		{
			if(b[j]>=a[i]) cnt++;
			else break;
		}
		ans=ans*(cnt-(n-i));
	}
	if(ans<0) ans=0;
	printf("%d",ans);
	return 0;
}
