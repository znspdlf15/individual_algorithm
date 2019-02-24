#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
char wheel[4][9];  // [0] = 12시, [2] = 3시, [6] = 9시
                  // 1 : S, 0 : N
int arrRotate[4];

void rotate(int input, int dir){
  if ( dir == -1 ){
    int temp = wheel[input][0];

    for ( int i = 0; i < 7; i++ ){
      wheel[input][i] = wheel[input][i+1];
    }
    wheel[input][7] = temp;

  } else if ( dir == 1 ){
    int temp = wheel[input][7];

    for ( int i = 7; i > 0; i-- ){
      wheel[input][i] = wheel[input][i-1];
    }
    wheel[input][0] = temp;
  }
}

int main(){
  for ( int y = 0; y < 4; y++ ) {
    scanf("%s", wheel[y]);
  }

  int K;

  cin >> K;
  for ( int k = 0; k < K; k++ ){
    int command, dir;
    cin >> command >> dir;
    command--;

    memset(arrRotate, 0, sizeof(arrRotate));
    arrRotate[command] = dir;
    for ( int k = command - 1; k >= 0; k-- ){
      if ( wheel[k+1][6] != wheel[k][2] ){
        arrRotate[k] = -arrRotate[k+1];
      } else {
        break;
      }
    }
    for ( int k = command + 1; k <= 3; k++ ){
      if ( wheel[k-1][2] != wheel[k][6] ){
        arrRotate[k] = -arrRotate[k-1];
      } else {
        break;
      }
    }
    for( int k = 0; k < 4; k++ ){
      rotate(k, arrRotate[k]);
    }
  }

  int ans = 0;
  for ( int y = 0; y < 4; y++ ){
    if ( wheel[y][0] == '1' ){
      int x = 1;
      ans += x << y;
    }
  }

  cout << ans << endl;

  return 0;
}
