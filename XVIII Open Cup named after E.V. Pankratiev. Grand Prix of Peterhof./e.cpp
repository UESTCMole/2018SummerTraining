#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cassert>
using namespace std;
char s[200005];
int l, nxt[100][200005], last[100];
int main() {
  scanf("%[^\n]", s);
  getchar();
  l = strlen(s);
  for (int i = 0; i < l; i++) s[i+l] = s[i];
  for (int i = 2 * l - 1; i >= 0; i--) {
    int c = s[i] - '!';
    for (int j = 0; j < 97; j++) {
      if (j == c) {
        nxt[j][i] = i;
        last[j] = i;
      } else {
        nxt[j][i] = last[j];
      }
    }
  }
  long long ans = 0;
  while (scanf("%[^\n]", s) != EOF) {
    getchar();
    int len = strlen(s);
    long long anss = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == ' ') continue;
      int c = s[i] - '!';
      anss = (long long)max(anss, nxt[c][(i+ans)%l] - (i+ans)%l);
    }
    ans += anss+1;
  }
  printf("%lld\n", ans);
}
