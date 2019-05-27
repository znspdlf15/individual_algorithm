#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int round;
  int game;

  cin >> round >> game;

  for ( int i = 0; i < game; i++ ){
    int M, N;
    bool success = true;
    scanf("%d%d", &M, &N);
    if ( M > N ){
      if ( M - N > round - M + 2 ){
        success = false;
      }
    } else if ( N > M ) {
      if ( N - M > round - N + 1 ){
        success = false;
      }
    }
    if ( success ) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
  return 0;
}
