#include <bits/stdc++.h>
using namespace std;
int tot, n, k, m, f[2005][2005];
int cnt[2005];
char s[2005];
int dfs(int now, int rest) {
  if (f[now][rest] != -1) return f[now][rest];
  if (rest <= cnt[now] * k) return f[now][rest] = 1;
  f[now][rest] = 0;
  for (int K = cnt[now] * k; K >= cnt[now]; K--) {
    if (dfs(now+1, rest - K) == 0) return f[now][rest] = 1;
  }
  return f[now][rest];
}
int main() {
  int cas = 0; int T; scanf("%d", &T);
  while (T--) {
    tot = 0;
    memset(f, -1, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    int cn = 1;
    for (int i = 1; i < 2*n; i++) {
      if (s[i] == s[i-1]) {
        cn++;
      } else {
        cnt[++tot] = cn;
        cn = 1; 
      }
    }
    cnt[++tot] = cn;
    int res = dfs(1, m);
    printf("Case #%d: ", ++cas);
    if (res) puts(s[0] == 'A' ? "A":"B");
    else puts(s[0] == 'B' ? "A":"B");
  }
} 
