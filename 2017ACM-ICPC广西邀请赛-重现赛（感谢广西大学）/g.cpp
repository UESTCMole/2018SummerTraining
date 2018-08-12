#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#define ll long long
#define ull unsigned long long
using namespace std;
int n, a[1000005], cnt[1000005];
int main() {
  while (scanf("%d", &n) != EOF) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      while (cnt[i] > 2) {
        ans ++;
        cnt[i] -= 2; 
      }
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 2) {
        if (i == 1 || i == 2) {
          ans ++;
          cnt[i] -= 2;
        } else {
          if (cnt[i-1] == 1 && cnt[i-2] == 1) {
            ans ++;
            cnt[i]--,cnt[i-1]--,cnt[i-2]--;
          } else {
            ans ++;
            cnt[i] -= 2;
          }
        }
      } else if (cnt[i] == 1) {
        if (i == 1 || i == 2) continue;
        if (cnt[i-1] == 1 && cnt[i-2] == 1) {
          ans ++;
          cnt[i]--;
          cnt[i-1]--;
          cnt[i-2]--;
        }
      }
    }
    printf("%d\n", ans);
  }
}