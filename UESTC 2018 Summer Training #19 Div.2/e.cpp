#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
int T, n, k;
int par[20005], fa[20005], used[20005];
struct Query {
  char s[3];
  int a, b;
  int ans;
}q[5005];
int find(int x) {
  return (x == par[x]) ? x : par[x] = find(par[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  par[x] = y;
}
void init() {
  for (int i = 1; i <= n; i++) par[i] = i;
  memset(used, 0, sizeof(used));
}
int main() {
  int cas = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &fa[i]);
    for (int i = 1; i <= k; i++) {
      scanf("%s", q[i].s);
      if (q[i].s[0] == 'Q') {
        scanf("%d %d", &q[i].a, &q[i].b);
      } else {
        scanf("%d", &q[i].a);
        used[q[i].a] += 1;
      }
    }
    for (int i = 1; i <= n; i++) if (!used[i] && fa[i]) {
      merge(i, fa[i]);
    }
    for (int i = k; i >= 1; i--) {
      if (q[i].s[0] == 'Q') {
        if (find(q[i].a) == find(q[i].b)) {
          q[i].ans = 1;
        } else {
          q[i].ans = 0;
        }
      } else {
        if (fa[q[i].a] == 0) continue;
        used[q[i].a]--;
        if (!used[q[i].a]) merge(q[i].a, fa[q[i].a]);
      }
    }
    printf("Case #%d:\n", ++cas);
    for (int i = 1; i <= k; i++) {
      if (q[i].s[0] == 'Q') {
        if (q[i].ans == 1) puts("YES");
        else puts("NO");
      }
    }
  }
}
