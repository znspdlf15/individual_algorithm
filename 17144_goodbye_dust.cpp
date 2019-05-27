#include <iostream>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
  int R, C, T;
  int map[52][52] = {0, };

  int upX = 0;
  int upY = 0;
  int downX = 0;
  int downY = 0;

  cin >> R >> C >> T;

  for ( int y = 1; y <= R; y++ ){
    for ( int x = 1; x <= C; x++ ){
      cin >> map[y][x];
      if ( map[y][x] == -1 ){
        if ( upX == 0 ){
          upX = x;
          upY = y;
        } else {
          downX = x;
          downY = y;
        }
      }
    }
  }

  int copy_map[52][52] = {0, };
  for ( int t = 0; t < T; t++ ){
    // 미세먼지 확산
    for ( int y = 1; y <= R; y++ ){
      for ( int x = 1; x <= C; x++ ){
        copy_map[y][x] = map[y][x];
      }
    }

    for ( int y = 1; y <= R; y++ ){
      for ( int x = 1; x <= C; x++ ){
        if ( copy_map[y][x] == 0 ) continue;

        int count = 0;
        int distrib_dust = copy_map[y][x]/5;
        for ( int d = 0; d < 4; d++ ){
          int nextX = x + dx[d];
          int nextY = y + dy[d];

          if ( nextX <= 0 || nextX > C || nextY <= 0 || nextY > R ) continue;
          if ( copy_map[nextY][nextX] == -1 ) continue;

          map[nextY][nextX] += distrib_dust;
          count++;
        }
        map[y][x] -= distrib_dust * count;
      }
    }

    // 공기청정기 작동
    // 윗 부분
    for ( int y = upY-1; y > 1; y-- ){
      map[y][1] = map[y-1][1];
    }
    for ( int x = 1; x < C; x++ ){
      map[1][x] = map[1][x+1];
    }
    for ( int y = 1; y < upY; y++ ){
      map[y][C] = map[y+1][C];
    }
    for ( int x = C; x > 2; x-- ){
      map[upY][x] = map[upY][x-1];
    }
    map[upY][2] = 0;

    // 아래 부분
    for ( int y = downY+1; y < R; y++ ){
      map[y][1] = map[y+1][1];
    }
    for ( int x = 1; x < C; x++ ){
      map[R][x] = map[R][x+1];
    }
    for ( int y = R; y > downY; y-- ){
      map[y][C] = map[y-1][C];
    }
    for ( int x = C; x > 2; x-- ){
      map[downY][x] = map[downY][x-1];
    }
    map[downY][2] = 0;
  }

  int ans = 0;
  for ( int y = 1; y <= R; y++ ){
    for ( int x = 1; x <= C; x++ ){
      if ( map[y][x] == -1 ) continue;
      ans += map[y][x];
    }
  }

  cout << ans << endl;

}
