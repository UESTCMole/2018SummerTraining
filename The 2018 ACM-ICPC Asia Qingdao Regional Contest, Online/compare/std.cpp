#include <stdio.h>
int a,b,c,d,v,t;
int tim;
int main(){
  int T;scanf("%d",&T);
  while (T--){
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&v,&t);
    long long ans=0;
    tim=0;
    for (int i=0;i<=t;i++){
      if (i%a==0){
        int cnt=b;
        while (cnt--){
          if (tim) ans++;
          tim=v+1;
        }
      }
      if (i%c==0){
        int cnt=d;
        while (cnt--){
          if (tim)ans++;
          tim=v+1;
        }
      }
      if (tim>0 )tim--;
    }
    printf("%lld\n",ans);
  }
}
