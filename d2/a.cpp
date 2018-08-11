#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
ull n;
ull ans[16] = {1,
4,
27,
256,
3125,
46656,
823543,
16777216,
387420489,
10000000000,
285311670611,
8916100448256,
302875106592253,
11112006825558016,
437893890380859375};

int main() {
  while (cin >> n) {
    int cnt  = 0;
    for (int i = 14; i >= 0; i--) {
      if (ans[i] <= n) cnt++;
    }
    printf("%d\n", cnt);
  }
}