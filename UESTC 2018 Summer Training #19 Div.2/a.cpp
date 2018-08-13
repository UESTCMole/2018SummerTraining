#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
int T;
int n, k, a[105];
int par[105], used[105];
void init() {
  for (int i = 1; i <= n; i++) par[i] = i;
  memset(used, 0, sizeof(used));
}
int find(int x) {
  return (x == par[x]) ? x : par[x] = find(par[x]);
}
void merge(int x, int y) {
  x = find(x); y = find(y);
  par[x] = y;
}
int main() {
  int cas = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (abs(a[i] - a[j]) <= k) merge(i, j);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = find(i);
      if (!used[x]) {
        ans++;
        used[x] = 1;
      }
    }
    printf("Case #%d: %d\n", ++cas, ans);
  }
}
