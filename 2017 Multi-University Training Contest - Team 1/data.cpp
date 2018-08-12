#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int b[105];
int main() {
  freopen("h.in", "w", stdout);
  int cnt = 1;
  b[0] = 1, b[1] = 2;
  while (1) {
    b[cnt+1] = b[cnt] + b[cnt-1];
    if (b[cnt+1] > 1e7) break;
    cnt++;
  }
  printf("10000000 %d 1 1 1\n", cnt);
  for (int i = 0; i <= cnt; i++) printf("%d ", b[i]);
  printf("\n");
}