#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int random(int n){
  return (long long)rand()*(long long)rand()%n;
}
int main(){
  printf("5\n");
  for (int cas=0;cas<5;cas++){
    printf("%d %d %d %d %d %d\n",random(1000)+1,random(1000)+1,random(1000)+1,random(1000)+1,
    random(1000)+1,random(100000)+1);
  }
}
