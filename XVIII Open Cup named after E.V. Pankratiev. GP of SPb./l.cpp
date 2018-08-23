#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
int n;
long long a[55];
int main(){
  freopen("xorsep.in","r",stdin);
  freopen("xorsep.out","w",stdout);
  long long sum=0;
  scanf("%d",&n);
  for (int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    sum^=a[i];
  }
  if (sum==0)printf("%lld\n",(1ll<<n)-2);
  else puts("0");
}
