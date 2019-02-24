#include <iostream>
#include <stdio.h>
using namespace std;
int N, M; // height, width.
int map[20][20];
int dice_x, dice_y;
int K; // command count
int north = 0;
int west = 0;
int east = 0;
int south = 0;
int down = 0;
int up = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main(){
  cin >> N >> M >> dice_y >> dice_x >> K;

  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      scanf("%d", &map[y][x]);
    }
  }

  // 1, 2, 3, 4 동 서 북 남
  for ( int n = 0; n < K; n++ ){
    int command;
    cin >> command;

    int next_x = dice_x + dx[command-1];
    int next_y = dice_y + dy[command-1];

    if ( next_x < 0 || next_x >= M || next_y < 0 || next_y >= N ) continue;

    dice_x = next_x;
    dice_y = next_y;

    int temp = down;
    switch ( command ){
      case 1:
        down = east;
        east = up;
        up = west;
        west = temp;
        break;
      case 2:
        down = west;
        west = up;
        up = east;
        east = temp;
        break;
      case 3:
        down = north;
        north = up;
        up = south;
        south = temp;
        break;
      case 4:
        down = south;
        south = up;
        up = north;
        north = temp;
        break;
      default:
        break;
    }

    if ( map[dice_y][dice_x] == 0 ){
      map[dice_y][dice_x] = down;
    } else {
      down = map[dice_y][dice_x];
      map[dice_y][dice_x] = 0;
    }

    printf("%d\n", up);
  }
  return 0;
}
