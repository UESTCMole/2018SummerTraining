#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char s[105];
int cnt[4];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] == 'N') cnt[0]++;
    if (s[i] == 'W') cnt[1]++;
    if (s[i] == 'E') cnt[2]++;
    if (s[i] == 'S') cnt[3]++;
  }
  int tot = 0;
  for (int i = 0; i < 4; i++) {
    if (cnt[i]) {
      tot++;
    }
  }
  if (tot == 3) {
    char ans;
    for (int i = 0; i < 4; i++) {
      if (!cnt[i]) {
        if (i == 0) ans = 'N';
        if (i == 1) ans = 'W';
        if (i == 2) ans = 'E';
        if (i == 3) ans = 'S';
        break;
      }
    }
    printf("%c\n", ans);
  } else if (tot == 2) {
    if (cnt[1] && cnt[0]) {
      printf("ES\n");
    }
    else if (cnt[1] && cnt[3]) {
      printf("NE\n");
    } else if (cnt[2] && cnt[0]) {
      printf("WS\n");
    } else if (cnt[2] && cnt[3]) {
      printf("WN\n");
    } else printf("X\n");
  } else if (tot == 1) {
    printf("X\n");
  }
}
