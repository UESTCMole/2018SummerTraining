#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int n,m,k,d;
int a[100005];
int c[100005];
ll ans;
int main(){
  scanf("%d%d%d%d",&n,&m,&k,&d);
  for (int i=1;i<=m;i++)scanf("%d",&c[i]);
  for (int i=1;i<=k;i++)scanf("%d",&a[i]);
  sort(a+1,a+1+k);
  a[0]=1,a[k+1]=n;
  int flag=0;
  for (int i=1;i<=k;i++)if (a[i]-a[i-1]>d)flag++;
  if (flag){
    
  }
}
