/*srzy*/
#include<stdio.h>
#define ll long long
#define mod 998244353
int T;
int n,m,k;
ll ans;
ll A[200005], B[200005];
ll ksm(ll a, int b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}
void init() {
  A[0] = 1;
  for (int i = 1; i <= 200001; i++) A[i] = (A[i-1] * i) % mod;
  B[200001] = ksm(A[200001], mod-2);
  for (int i = 200000; i >= 0; i--) B[i] = (B[i+1] * (i+1)) % mod;
}
ll C(int i, int j) {
  if (i<j) return 0;
  return (A[i]*B[j]%mod*B[i-j]%mod)%mod;
}
int main()
{
	init();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ans=0;
		int tmax=k/n;
		for(int t=0;t<=tmax;t++)
		{
			if(t%2) ans=(ans-C(k-t*n+m-1,m-1)*C(m,t)%mod+mod)%mod;
			else ans=(ans+C(k-t*n+m-1,m-1)*C(m,t)%mod)%mod;
		}
		printf("%lld\n",ans);
	}
}
