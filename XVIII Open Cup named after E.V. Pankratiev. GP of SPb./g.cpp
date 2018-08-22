#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
char g[505][505];
int vis[505][505];
int h,w;
bool inside(int x,int y){
  if (x>=1&&x<=h&&y>=1&&y<=w)return true;
  return false;
}
void dfs(int x,int y){
  vis[x][y]=1;
  int nx,ny;
  nx=x+1,ny=y;
  if (inside(nx,ny)&&!vis[nx][ny]){
    if (g[nx][ny]=='.')dfs(nx,ny);
    else {
      nx=x,ny=y+1;
      if (inside(nx,ny)&&!vis[nx][ny])
        if (g[nx][ny]=='.')dfs(nx,ny);
      nx=x,ny=y-1;
      if (inside(nx,ny)&&!vis[nx][ny])
        if (g[nx][ny]=='.')dfs(nx,ny);
    }
  }
}
int main(){
  freopen("mole.in","r",stdin);
  freopen("mole.out","w",stdout);
  scanf("%d%d",&h,&w);
  for (int i=1;i<=h;i++)scanf("%s",g[i]+1);
  for (int j=1;j<=w;j++)
    if (g[1][j]=='.')dfs(1,j);
  int find=0;
  for (int i=1;i<=h;i++){
    for (int j=1;j<=w;j++){
      if (!find&&g[i][j]=='.'&&!vis[i][j]){
        find=1;
        g[i][j]='X';
      }
    }
  }
  if (!find)puts("No");
  else {
    puts("Yes");
    for (int i=1;i<=h;i++){
      for (int j=1;j<=w;j++)
        printf("%c",g[i][j]);
      printf("\n");
    }
  }
}
