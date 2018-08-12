#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
void solve(int n, ll k) {
  if (k <= n) printf("%lld\n", k);
  else {
    k -= n;
    //printf("%lld\n", k);
    ll loop = (k-1) / (n-1);
    int res = k % (n-1);
    //printf("%d %lld\n", res, loop);

    if (loop % 2 == 1) {
      if (res == 0) printf("%d\n", n);
      else printf("%d\n", res);
    } else {
      if (res == 0) printf("%d\n", n-1);
      else printf("%d\n", res);
    }
  }
}
int main() {
  int cas = 0;
  int n; ll k;
  while (scanf("%d%lld", &n, &k) == 2) {
    printf("Case #%d: ", ++cas);
    if (n == 2) printf("%d\n", 2 - (int)(k % 2ll));
    else solve(n, k);
  }
}