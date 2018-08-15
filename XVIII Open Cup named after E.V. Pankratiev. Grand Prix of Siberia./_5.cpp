#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
const int N = 200005;
int n, m, par[N];
int x, y, a, b;
char s[10];
int find(int x) {
  return (x == par[x]) ? x : par[x] = find(par[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  par[x] = y;
}
vector <int> ans;
bool same(int u, int v) {
  return find(u) == find(v);
}
int main() {
  scanf("%d%d", &n, &m);
  n += 2; int u = n-1, v = n;
  for (int i = 1; i <= 2 * n; i++) par[i] = i;
  merge(u, v+n), merge(v, u+n);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    if (s[0] == 'v') {
      scanf("%d", &a);
      if (same(a, u) || same(a+n, u+n) || same(a, v+n) || same(a+n, v)) {
        puts("inconsistent");
        return 0;
      }
      if (same(a, v) || same(a+n, v+n)) ans.push_back(i);
      merge(a, v), merge(a+n, v+n);
    }
    if (s[0] == 'h') {
      scanf("%d", &a);
      if (same(a, v) || same(a+n, v+n) || same(a, u+n) || same(a+n, u)) {
        puts("inconsistent");
        return 0;
      }
      if (same(a, u) || same(a+n, u+n)) ans.push_back(i);
      merge(a, u), merge(a+n, u+n);
    }
    if (s[0] == 'p' && s[1] == 'a') {
      scanf("%d%d", &a, &b);
      if (same(a, b+n) || same(a+n, b)) {
        puts("inconsistent");
        return 0;
      }
      if (same(a, b) || same(a+n, b+n)) ans.push_back(i);
      merge(a, b), merge(a+n, b+n);
    }
    if (s[0] == 'p' && s[1] == 'e') {
      scanf("%d%d", &a, &b);
      if (same(a, b) || same(a+n, b+n)) {
        puts("inconsistent");
        return 0;
      }
      if (same(a, b+n) || same(a+n, b)) ans.push_back(i);
      merge(a, b+n), merge(a+n, b);
    }
  }
  printf("consistent\n");
  int sz = ans.size();
  printf("%d\n", sz);
  for (auto x : ans) printf("%d ", x);
}
