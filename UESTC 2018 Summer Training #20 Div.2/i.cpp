#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#define mod 1000000007
using namespace std;
const int maxn=100003;
int n, a[100005];
int mu[100005],primes[1000005],cnt[200005];
bool isPrime[100005];
void mobius() {
  fill(isPrime, isPrime + maxn, 1);
  mu[1] = 1;
  int num = 0;
  for (int i = 2; i < maxn; ++i) {
    if (isPrime[i]) primes[num++] = i, mu[i] = -1;
    int d;
    for (int j = 0; j < num && (d = i * primes[j]) < maxn; j++) {
      isPrime[d] = false;
      if (i % primes[j] == 0) {
          mu[d] = 0;
          break;
      } else mu[d] = -mu[i];
    }
  }
}
long long ksm(long long a, int b){
  long long res=1;
  while (b){
    if (b&1)res=(res*a)%mod;
    a=(a*a)%mod;
    b>>=1;
  }
  return res;
}
int main() {
  int cas=0;int T;scanf("%d", &T);
  mobius();
  while (T--){
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    int Min=10000000,Max=0;
    for (int i=1;i<=n;i++){
      scanf("%d", &a[i]);
      Min=min(Min,a[i]);
      Max=max(Max,a[i]);
      cnt[a[i]]++;
    }
    for (int i=1;i<=Max*2;i++)cnt[i]+=cnt[i-1];
    long long ans=0;
    for (int gcd=2;gcd<=Min;gcd++){
      long long sum=-mu[gcd];
      if (sum==0)continue;
      for (int j=1;j<=Max/gcd;j++)sum=(sum*ksm(j,cnt[(j+1)*gcd-1]-cnt[j*gcd-1]))%mod;
      ans=((ans+sum)%mod+mod)%mod;
    }
    printf("Case #%d: %lld\n",++cas,ans);
  }
}
