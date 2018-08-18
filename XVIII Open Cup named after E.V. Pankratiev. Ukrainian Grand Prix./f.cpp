#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
char s[100005];
int used[26],flag1,flag2;//palin:flag1
int main(){
  scanf("%d%s",&n,s);
  flag1=flag2=1;
  for (int i=0;i<n;i++){
    if (s[i]!=s[n-i-1]){
      flag1=0;
      break;
    }
  }
  if (!flag1){
    puts("1");
    return 0;
  }
  int cnt=0;
  for (int i=0;i<n;i++){
    if (!used[s[i]-'a'])cnt++;
    used[s[i]-'a']++;
  }
  if (cnt==2){
    int cn1=0,cn2=0;
    for (int i=0;i<26;i++){
      if (used[i]&&!cn1)cn1=used[i];
      if (used[i]&&cn1)cn2=used[i];
    }
    if (abs(cn1-cn2)==1){
      for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]){
          flag2=0;
          break;
        }
      }
      if (flag2)puts("-1");
      else puts("2");
    } else {
      if (cn1<cn2)swap(cn1,cn2);
      if (cn2==1)puts("-1");
      else puts("2");
    }
  }
  else if (cnt==1)puts("-1");
  else puts("2");
}
