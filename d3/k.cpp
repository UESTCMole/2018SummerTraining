#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int main() {
  freopen("katryoshka.in", "r", stdin);
  int T; scanf("%d", &T);
  int cas = 0;
  while (T--) {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    int ans = min(n, min(k, m));
    ans += min((n-ans)/2, k-ans);
    printf("Case %d: %d\n", ++cas, ans);
  }
}
