#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int mx = 1e9+10, mi=-1e9-10, n;
char s[1005][15];
int a[1005];
int len[1005];
bool sign[1005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (s[i][0] != 'x') {
      int num = 0;
      int flag = 0;
      if (s[i][0] == '-') flag = 1;
      if (!flag) for (int j = 0; j < len[i]; j++) {
        num = num*10 + s[i][j] - '0';
      }
      else for (int j = 1; j < len[i]; j++) num = num*10 + s[i][j] -'0';
      if (flag) num = -num;
      a[i] = num;
      sign[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s[i][0] == 'x') {
      if (i == 1) {
        if (!sign[i+1]) {
          puts("none");
          return 0;
        } else {
          mx = min(mx, a[i+1]-1);
        }
      } else if (i == n) {
        if (i % 2  == 1) {
          if (!sign[i-1]) {
            puts("none");
            return 0;
          } else {
            mx = min(mx, a[i-1]-1);
          }
        } else {
          if (!sign[i-1] ) {
            puts("none");
            return 0;
          } else {
            mi = max(mi, a[i-1] + 1);
          }
        }
      } else {
        if (i % 2 == 1) {
          if (!sign[i-1] || !sign[i+1]) {
            puts("none");
            return 0;
          } else {
            mx = min(mx, a[i-1]-1);
            mx = min(mx, a[i+1]-1);
          }
        } else {
          if (!sign[i-1] || !sign[i+1]) {
            puts("none");
            return 0;
          } else {
            mi = max(mi, a[i-1]+1);
            mi = max(mi, a[i+1]+1);
          }
        }
      }
    } else {
      if (i % 2 == 1) {
        if (sign[i+1]) {
          if (a[i] >= a[i+1]) {
            puts("none");
            return 0;
          }
        }
        if (sign[i-1]) {
          if (a[i] >= a[i-1]) {
            puts("none");
            return 0;
          }
        }
      } else {
        if (sign[i+1]) {
          if (a[i] <= a[i+1]) {
            puts("none");
            return 0;
          }
        }
        if (sign[i-1]) {
          if (a[i]<= a[i-1]){
            puts("none");
            return 0;
          }
        }
      }
    }
  }
  if (mi == mx) {
    printf("%d\n", mi);
  } else if (mi < mx){
    printf("ambiguous\n");
  } else {
    printf("none\n");
  }
}
