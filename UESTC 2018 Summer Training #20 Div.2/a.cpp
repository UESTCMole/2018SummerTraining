#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
char a[300005], b[300005];
int Abs(int x) {
  return x > 0?x:(-x);
}
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int cnt1 = 0, cnt2 = 0;
    int n, A, B;
    scanf("%d%d%d", &n, &A, &B);
    scanf("%s%s", a, b);
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i]) cnt1++;
      else cnt2++;
    }
    if (n+cnt1>=A+B&&Abs(A-B)<=cnt2) puts("Not lying");
    else puts("Lying");
  }
}
