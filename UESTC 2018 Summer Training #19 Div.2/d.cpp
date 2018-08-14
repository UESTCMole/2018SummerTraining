#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll A[505], B[505];
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
  for (int i = 1; i <= 500; i++) A[i] = (A[i-1] * i) % mod;
  B[500] = ksm(A[500], mod-2);
  for (int i = 499; i >= 0; i--) B[i] = (B[i+1] * (i+1)) % mod;
}
ll C(int i, int j) {
  if (i<j) return 0;
  return A[i]*B[j]%mod*B[i-j]%mod)%mod;
}
int main() {
  int cas = 0; int T; scanf("%d", &T);
  init();
  while (T--) {
    int n, k, p; scanf("%d%d%d", &n, &k, &p);
    ll ans = 0;
    for (int j = k+1; j <= n; j++) {
      if (j == n) {
        ans = (ans + A[n-1]%mod*ksm(A[j-k], mod-2))%mod;
        continue;
      }
      ans = (ans + (A[n-1] * ksm(A[j-k], mod-2))%mod)%mod;
      //printf("%lld ", ans);
      ans = (ans - C(p-1, j-k)%mod*A[n-j+k-1]%mod)%mod;
      //printf("%lld\n", ans);
    }
    printf("Case #%d: %lld\n", ++cas, ans);
  }
}
