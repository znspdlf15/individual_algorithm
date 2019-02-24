#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
char wheel[4][9];  // [0] = 12시, [2] = 3시, [6] = 9시
                  // 1 : S, 0 : N
char copy_wheel[4][8];
int visit[4];

void rotate(int input, int dir){
  visit[input] = 1;
  // cout << input << "is " << dir << "rotated." << endl;
  if ( dir == -1 ){
    int temp = copy_wheel[input][0];

    for ( int i = 0; i < 7; i++ ){
      copy_wheel[input][i] = copy_wheel[input][i+1];
    }
    copy_wheel[input][7] = temp;

  } else if ( dir == 1 ){
    int temp = copy_wheel[input][7];

    for ( int i = 7; i > 0; i-- ){
      copy_wheel[input][i] = copy_wheel[input][i-1];
    }
    copy_wheel[input][0] = temp;
  }

  if ( input > 0 && !visit[input-1] ){
    if ( wheel[input-1][2] != wheel[input][6] ){
      rotate(input-1, -dir);
    }
  }
  if ( input < 3 && !visit[input+1] ){
    if ( wheel[input+1][6] != wheel[input][2] ){
      rotate(input+1, -dir);
    }
  }
}
int main(){
  for ( int y = 0; y < 4; y++ ) {
    scanf("%s", wheel[y]);
  }

  int K;

  cin >> K;
  for ( int k = 0; k < K; k++ ){
    int command;
    int dir;
    cin >> command >> dir;

    memset(visit, 0, sizeof(visit));
    for ( int y = 0; y < 4; y++ ){
      for ( int x = 0; x < 8; x++ ){
        copy_wheel[y][x] = wheel[y][x];
      }
    }
    rotate(command-1, dir);
    for ( int y = 0; y < 4; y++ ){
      for ( int x = 0; x < 8; x++ ){
        wheel[y][x] = copy_wheel[y][x];
      }
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
