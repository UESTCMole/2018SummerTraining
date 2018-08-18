#include <stdio.h>
#include <algorithm>
#include <set>
#define ll long long
using namespace std;
int n,k;
set <int> s[10005];
int x[1005],y[1005];
int nx[1005],ny[1005];
bool inside(int a,int b){
  return a>=0&&a<n&&b>=0&&b<n;
}
int did(int a,int b){
  if (a==0&&b==n-1)return 3;
  if (a==0&&b==0)return 3;
  if (a==n-1&&b==0)return 3;
  if (a==n-1&&b==n-1)return 3;
  if (a==0||a==n-1||b==0||b==n-1)return 4;
  return 5;
}
ll gcd(ll a, ll b){
  if (b==0) return a;
  return gcd(b,a%b);
}
int main() {
  int T;scanf("%d",&T);
  int cas=0;
  while (T--){
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)s[i].clear();
    for (int i=1;i<=k;i++){
      scanf("%d%d",&x[i],&y[i]);
      s[x[i]].insert(y[i]);
    }
    ll ans1=0,ans2=0;
    ans1=12ll+4ll*4*(n-2)+5ll*(n-2)*(n-2);//sum
    ans2=(ans1-3ll*2-5ll*(n-2))/2+6+5ll*(n-2);//effictive
    for (int i=1;i<=k;i++){
      nx[1]=x[i],ny[1]=y[i];
      nx[2]=x[i]-1,ny[2]=y[i];
      nx[3]=x[i]+1,ny[3]=y[i];
      nx[4]=x[i],ny[4]=y[i]-1;
      nx[5]=x[i],ny[5]=y[i]+1;
      ans1-=did(nx[1],ny[1]);
      if (nx[1]+ny[1]>=n-1)ans2-=did(nx[1],ny[1]);
      for (int i=2;i<=5;i++){
        if (inside(nx[i],ny[i])){
          if (s[nx[i]].count(ny[i]))continue;
          ans1--;
          if (nx[i]+ny[i]>=n-1)ans2--;
        }
      }
    }
    ll _gcd=gcd(ans2,ans1);
    printf("Case #%d: %lld/%lld\n",++cas,ans2/_gcd,ans1/_gcd);
  }
}
