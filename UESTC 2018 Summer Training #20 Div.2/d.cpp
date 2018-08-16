#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#define mod 1000000007
using namespace std;
long long n, m, p;
int main(){
  int T;scanf("%d",&T);
  while (T--){
    scanf("%lld%lld%lld",&n,&m,&p);
    long long tot=0,sum=n*m-1;
    for (int cnt=0;sum>0;cnt++){
      long long num=(sum-1)/p;
      tot+=(p-1-cnt+p-1-cnt+(num-1)*(p-cnt-1))*num/2;
      sum-=num+1;
      //if (!cnt) printf("%d\n", tot);
      //printf("%d\n", num);
    }
   // printf("%d\n",tot);
   if (tot%2==0)puts("YES");
   else puts("NO");
  }
}
