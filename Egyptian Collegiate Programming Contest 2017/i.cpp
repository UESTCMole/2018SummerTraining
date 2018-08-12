#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int n, m, q;
int a[205][205];
int ans[4005], anss;
int main() {
  freopen("important.in", "r", stdin);
  int T; scanf("%d", &T);
  int cas = 0;
  while (T--) {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    printf("Case %d:\n", ++cas);
    while (q--) {
      anss = 0;
      int A, b, c, d; scanf("%d%d%d%d", &A, &b, &c, &d);
      for (int i = A; i <= c; i++) {
        for (int j = b; j <= d; j++) ans[anss++] = a[i][j];
      }
      int num = (d-b+1) * (c-A+1);
      num /= 2; num++;
      //printf("%d\n", num);
      nth_element(ans, ans + num - 1, ans+anss);
      printf("%d\n", ans[num-1]);
    }
  }
}
