#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
  int m;
  int cas = 0;
  while (cin >> m) {
    int k = floor(m * log10(2));
    printf("Case #%d: ", ++cas);
    cout << k << endl;
  }
}