#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;

int N;
int visit[1502][1502];
int city[1502][1502];

int getMin(int left, int right, int num){
  if ( num == N+1 ){
    return 0;
  }

  int new_left = getMin(num, right, num+1) + ;
  int new_right = getMin(left, num, num+1);

  if ( new_left > new_right ){

  }

}
int main(){
  scanf("%d", &N);

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      scanf("%d", &city[y][x]);
    }
  }

  memset(visit, -1, sizeof(visit));

  cout << getMin(1, 1, 1) << endl;
  return 0;
}
