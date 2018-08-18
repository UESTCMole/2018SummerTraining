#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,T,k;
struct Edge{
  int u,v,nxt;
}e[200005];
int last[200005],tot;
void add(int u,int v){
  tot++;
  e[tot].u=u,e[tot].v=v,e[tot].nxt=last[u];
  last[u]=tot;
}
int vis[200005],sz[200005];
void dfs(int u){
  if (vis[u])return;
  vis[u]=1;
  sz[u]=1;
  for (int i=last[u];i;i=e[i].nxt){
    int v=e[i].v;
    if (vis[v])continue;
    dfs(v);
    sz[u]+=sz[v];
  }
}
int main(){
  scanf("%d",&T);
  while (T--){
    scanf("%d%d",&n,&k);
    memset(last,0,sizeof(last));
    tot=0;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n-1;i++){
      int u,v;scanf("%d%d",&u,&v);
      add(u,v);
      add(v,u);
    }
    dfs(1);
    //for (int i=1;i<=n;i++)printf("%d ",sz[i]);puts("");
    int ans=0;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++){
      for (int j=last[i];j;j=e[j].nxt){
        int v=e[j].v;
        if (vis[v])continue;
        if (n-sz[v]>=k&&sz[v]>=k){
          ans++;
          vis[v]=1;
        }
      }
    }
    printf("%d\n",ans);
  }
}
