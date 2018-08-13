#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
int T, n;
struct Dragon {
  int a, b, c, id;
  bool operator < (const Dragon& rhs) const {
    if (c == rhs.c) return b < rhs.b;
    return c < rhs.c;
  }
}d[100005];
int val[4*1000005];
int used[1000005];
void build(int o, int l, int r) {
  if (l == r) {
    val[o] = 0;
    return ;
  }
  int mid = (l + r) / 2;
  build(o<<1, l, mid);
  build(o<<1|1, mid+1, r);
  val[o] = val[o<<1] + val[o<<1|1];
}
void update (int o, int l, int r, int pos) {
  if (l == r) {
    val[o]++;
    return ;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) update(o<<1, l, mid, pos);
  else update (o<<1|1, mid+1, r, pos);
  val[o] = val[o<<1] + val[o<<1|1];
}
int query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return val[o];
  int res = 0;
  int mid = (l+r)/2;
  if (L <= mid) res += query(o<<1, l, mid, L, R);
  if (R >= mid+1) res += query(o<<1|1, mid+1, r, L, R);
  return res;
}
int main() {
  int cas = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    memset(val, 0, sizeof(val));
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
      d[i].id = i;
      mx = max(mx, d[i].a); mx = max(mx, d[i].b); mx = max(mx, d[i].c);
    }
    //printf("mx = %d\n", mx);
    for (int i = 1; i <= n; i++) {
      if (!used[d[i].a]) {
        ans++;
        update(1, 1, mx, d[i].a);
      }
      used[d[i].a] = 1;
    }
    sort(d+1, d+1+n);
    for (int i = 1; i <= n; i++) {
      int num = query(1, 1, mx, d[i].b, d[i].c);
      if (num > 1) continue;
      if (num == 0) {
        update(1, 1, mx, d[i].c);
        ans++;
        continue;
      }
      if (num == 1) {
        if (d[i].a >= d[i].b && d[i].a <= d[i].c) {
          update(1, 1, mx, d[i].c);
          ans++;
          continue;
        }
      }
    }
    printf("Case #%d: %d\n", ++cas, ans);
  }
}
