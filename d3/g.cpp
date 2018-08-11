#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
const double pi = acos(-1.0);
int main() {
  freopen("glorious.in", "r", stdin);
  int cas = 0; int T; scanf("%d", &T);
  while (T--) {
    int n, r, k; scanf("%d%d%d", &n, &r, &k);
    double t = sin((double)(k-2)*pi / 2.0 / (double)k);
    double base = t * t;
    double sum = 1.0;
    for (int i = 2; i <= 2*(n-1); i += 2) {
      sum += 1 / base;
      base = base * t * t;
    }
    double ans = 1.0;
    ans *= sum * (double)r * (double)r;
    printf("Case %d: %.5f\n", ++cas, ans * ((double)k*tan(pi/(double)k) - pi));
  }
}
