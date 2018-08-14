#include <bits/stdc++.h>
using namespace std;
int T, n, k, e;
int a[1005];
int f[1005][5][55][15];
int E[4] = {0, 4, 8, 11};
int main() {
  int cas = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &k, &e);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(f, 63, sizeof(f));
    f[0][0][e][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int p = 0; p <= e; p++) {
        for (int q = 0; q <= k; q++) {
          for (int j = 0; j < 4; j++) {
            for (int last = 0; last < 4; last++) {
              if (last == j) {
                if (p+j <= e) f[i][j][p][q] = min(f[i][j][p][q], f[i-1][last][p+j][q] + max(0, a[i] - E[j]));
              } else {
                if (q && p+j <= e) f[i][j][p][q] = min(f[i][j][p][q], f[i-1][last][p+j][q-1] + max(0, a[i] - E[j]));
                if (q == k && j==0) f[i][j][p][q] = min(f[i][j][p][q], f[i-1][last][p+j][q] + max(0, a[i] - E[j]));
              }
            }
          }
        }
      }
    }
    int ans = 1e9;
    for (int p = 0; p <= e; p++) {
      for (int q = 0; q <= k; q++) {
        for (int j = 0; j < 4; j++) {
          ans = min(ans, f[n][j][p][q]);
        }
      }
    }
    printf("Case #%d: %d\n", ++cas, ans);
  }
}
