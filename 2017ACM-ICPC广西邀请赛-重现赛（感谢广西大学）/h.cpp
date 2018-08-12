#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
int n;
ll a;
ll m;
ll ksm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res*a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res % m;
}
int main() {
  while (scanf("%d%lld", &n, &a) != EOF)
  {
    int cnt = 0;
    m = 1ll << n;
    if ( a % 2 == 1 ) printf("1\n");
    else {
      for (int i = 1; i <= n; i++) if (ksm((ll)i, a) == ksm(a, (ll)i)) cnt++;
      int x;
      if (n % a == 0) x = n/a;
      else x = n/a+1;
      x = (1 << x);
      cnt += (m/x) - (n/x);
      printf("%d\n", cnt);
    }
  }
}