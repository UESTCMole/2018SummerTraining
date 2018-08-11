#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#define maxn 100004
using namespace std;
int a[100005];
int par[100005];
int tot;
vector <int> v[100005];
int find(int x) {
  return (x == par[x]) ? x : par[x] = find(par[x]);
}
void merge(int x ,int y) {
  x = find(x), y = find(y);
  par[x] = y;
}
void init(int n) {
  tot = 0;  
  for (int i = 1; i <= n; i++) par[i] = i;
  for (int i = 1; i <= maxn; i++) v[i].clear();
}
int main() {
  freopen("dream.in", "r", stdin);
  int T; scanf("%d", &T);
  int cas = 0;
  while (T--) {
    int n; scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      for (int j = 1; j <= (int)sqrt(a[i]); j++) {
        if (a[i] % j == 0) {
          //printf("000\n");
          v[j].push_back(i);
          if (a[i] != j * j) {
            v[a[i] / j].push_back(i);
          }
        }
      }
    }
    //for (int i = 1; i <= 6; i++) for (auto x : v[i]) printf("%d\n", x);
    long long ans = 0;
    for (int i = maxn; i; i--) {
      if (tot == n-1) break;
      if (v[i].size() >= 2) {
        for (int j = 1; j < v[i].size(); j++) {
          if (find(v[i][0]) != find(v[i][j])) {
            merge(v[i][0], v[i][j]);
            ans += i;
            tot++;
          }
        }
      }
    }
    printf("Case %d: %lld\n", ++cas, ans);
  }
}
