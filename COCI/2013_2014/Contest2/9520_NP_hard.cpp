#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int minimum[1501];
  static int city[1502][1502];
  int N;

  scanf("%d", &N);

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      scanf("%d", &city[y][x]);
    }
  }

  int left = 1;
  int right = 1;
  minimum[1] = 0;

  for ( int next = 2; next <= N; next++ ){
    if ( city[next][left] > city[right][next] ){
      minimum[next] = minimum[next-1] + city[right][next];
      right = next;
    } else {
      minimum[next] = minimum[next-1] + city[next][left];
      left = next;
    }
  }

  cout << minimum[N] << endl;
  return 0;
}
