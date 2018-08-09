#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
struct Edge {
  int u, v, w;
  bool operator < (const Edge&rhs)const {
    return w < rhs.w;
  }
}e[200005];
int n, m;
int par[100005];
int find(int x) {
  return (x == par[x]) ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  par[x] = y;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    ll sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
      sum += (ll)e[i].w;
    }
    sort(e+1, e+1+m);
    for (int i = m; i >= 1; i--) {
      int u = e[i].u, v = e[i].v;
      if (find(u) == find(v)) continue;
      merge(u, v);
      sum -= e[i].w;
      cnt++;
    }
    printf("%d %lld\n", m - cnt, sum);
  }
}