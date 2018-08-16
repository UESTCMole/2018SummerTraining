#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#define mod 1000000007
using namespace std;
int n, a[250005], b[250005], mx[250005];
int main() {
  while (scanf("%d", &n)!=EOF) {
    int ans = 0, Max = 0;
    priority_queue<int> q;
    memset(mx, 0, sizeof(mx));
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = n; i >= 1; i--) mx[i] = max(mx[i+1], a[i]-i);
    for (int i = 1; i <= n; i++) q.push(mx[b[i]]);
    for (int i = n+1; i <= 2*n; i++) {
      int now = q.top(); q.pop();
      Max = max(Max, now-i);
      ans = (ans + max(Max, now)) % mod;
    }
    printf("%d\n", ans%mod);
  }
}
