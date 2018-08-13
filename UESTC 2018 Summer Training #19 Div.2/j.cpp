#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
int n, m;
char s[1000005];
int h[1000005], sign[1000005];
int d[1000005][30];
struct Num {
  int id;
  long long val;
};
Num q[1000005];
int head, tail;
int main() {
  int cas = 0; int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    h[0] = 0;
    head = tail = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == '/') h[i] = h[i-1] + 1, sign[i] = 1;
      if (s[i] == '\\') h[i] = h[i-1] - 1, sign[i] = -1;
      if (s[i] == '_') h[i] = h[i-1], sign[i] = 0;
    }
    //for (int i = 1 ; i <= n; i++) printf("%d ", h[i]);
    //printf("\n");
    //printf("rmq%d\n", RMQ_query(9,n));
    long long ans = 0;
    for (int i = 0; i <= m; i++) {
      while (head < tail && q[tail-1].val > h[i]) tail--;
      q[tail].val = h[i];
      q[tail].id = i;
      tail++;
    }
    long long mi = q[head].val;
    //for (int i = head; i < tail; i++) printf("%d %d\n", q[i].id, q[i].val);
    for (int i = 1; i <= m; i++) ans += h[i-1] + h[i] - 2*mi;
    long long now = ans;
    for (int i = 2; i <= n-m+1; i++) {
      int j = i + m - 1;
      while (head < tail && q[head].id < i-1) head++;
      while (head < tail && q[tail-1].val > (long long)h[j]) tail--;
      q[tail].val = (long long)h[j];
      q[tail].id = j;
      tail++;
      now -= (long long)h[i-1] + (long long)h[i-2] - 2 * mi;
      long long last = mi;
      //printf("%d\n", mi);
      mi = q[head].val;
      //printf("mi, last :%d %d\n",mi, last);
      now += (long long)h[j] + (long long)h[j-1] - 2 * mi;
      now += 2*(-mi+last)*(m-1);
      //printf("%d %d\n", ans, now);
      ans = min(ans, now);
    }
    printf("Case #%d: %.1f\n", ++cas, (double)ans / 2.0);
  }
}
