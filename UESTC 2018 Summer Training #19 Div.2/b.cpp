#include <bits/stdc++.h>
using namespace std;
int n, m;
int to[10005], nxt[10005], dfn[105], low[105], last[105], tot;
bool bridge[10005];
void add(int u, int v) {
  tot++; to[tot] = v; nxt[tot] = last[u]; last[u] = tot;
}
int num;
void dfs(int x, int in_edge) {
  dfn[x] = low[x] = ++num;
  for (int i = last[x]; i; i = nxt[i]) {
    int y = to[i];
    if (!dfn[y]) {
      dfs(y, i);
      low[x] = min(low[x], low[y]);
      if (low[y] > dfn[x]) bridge[i] = bridge[i^1] = true;
    } else if (i != (in_edge ^ 1)) low[x] = min(low[x], dfn[y]);
  } 
}
int main() {
  int cas = 0; int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    memset(last, 0, sizeof(last));
    tot = 1; num = 0;
    for (int i = 1; i <= m; i++) {
      int u, v; scanf("%d%d", &u, &v);
      add(u, v); add(v, u);
    }    
    for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i, 0);
    for (int i = 2; i <= tot; i++) if (bridge[i]) {
      printf("%d %d\n", to[i], to[i^1]);
    }
  }
}

