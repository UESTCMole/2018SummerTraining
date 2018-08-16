#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <queue>
#include <stdlib.h>
#include <time.h>
int random(int n){
  return (long long)rand()*rand()%n;
}
int main() {
  srand((unsigned)time(0));
  printf("100\n");
  for (int i=1;i<=100;i++){
    printf("%d %d %d\n", 1000, 1000, 999998);
  }
}
