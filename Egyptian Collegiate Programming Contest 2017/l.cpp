#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int main() {
  freopen("lazy.in", "r", stdin);
  int T;
  scanf("%d", &T);
  int cas = 0;
  while (T--) {
    int n;scanf("%d", &n);
    printf("Case %d: %d\n", ++cas, n-1);
  }
}
