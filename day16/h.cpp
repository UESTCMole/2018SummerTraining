#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
unsigned a[10000005];
struct Query {
  int b, id;
  bool operator < (const Query& rhs) const {
    return b < rhs.b;
  }
}q[105];
unsigned ans[105];
unsigned A, B, C;
unsigned x, y, z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

void quickSelect(int l, int r, int rank) {
  int i = l, j = r;
  unsigned mid = a[(l + r) / 2];
  do {
    while (a[i] < mid) ++i;
    while (a[j] > mid) --j;
    if (i <= j) {
      swap(a[i], a[j]);
      ++i; --j;
    }
  } while (i <= j);
  if (l <= j && rank <= j-l+1) quickSelect(l, j, rank);
  if (i <= r && rank >= i-l+1) quickSelect(i, r, rank-(i-l));
}
int main() {
  int cas = 0;
  //ios::sync_with_stdio(0); cin.tie(0);
  while (scanf("%d%d%u%u%u", &n, &m, &A, &B, &C) != EOF) {
    x = A, y = B, z = C;
    for (int i = 1; i <= n; i++) a[i] = rng61();
    //for (int i = 1; i <= n; i++) cout << a[i] << endl;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &q[i].b);
      q[i].id = i;
    }    
    //sort(a+1, a+n+1);
    //for (int i = 1; i <= n; i++) {
      //cout << a[b[i]+1] << endl;
    //}
    //for (int i = 1; i <= n; i++) printf("%u\n", a[i]);
    q[m+1].b = n;
    //sort(q+1, q+m+1);
    for (int i = m; i >= 1; i--) {
      //cout << q[i].b << endl;
      if (q[i].b == q[i+1].b) ans[q[i].id] = a[q[i].b+1];
      else {
        quickSelect(1, q[i+1].b, q[i].b+1);
        ans[q[i].id] = a[q[i].b+1];
      }
    }
    printf("Case #%d:", ++cas);
    for (int i = 1; i <= m; i++) printf(" %u", ans[i]);
    printf("\n");
  }
}