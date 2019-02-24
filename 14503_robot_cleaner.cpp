#include <iostream>
using namespace std;

int main(){
  int N, M; // height, width
  int now_x, now_y;
  int d; // 0: 북, 1: 동, 2: 남, 3: 서
  int map[50][50];

  int dx[4] = { 0, 1, 0, -1 };
  int dy[4] = { -1, 0, 1, 0 };
  cin >> N >> M;
  cin >> now_y >> now_x >> d;

  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      cin >> map[y][x];
    }
  }

  while ( true ){
    // step1
    map[now_y][now_x] = 9;

    // step2
    int cant_count = 4;
    for ( int i = 0; i < 4; i++ ){
      int next_x = now_x + dx[i];
      int next_y = now_y + dy[i];
      if ( map[next_y][next_x] == 1 || map[next_y][next_x] == 9 ){
        cant_count--;
      }
    }

    if ( !cant_count ){
      int next_x = now_x - dx[d];
      int next_y = now_y - dy[d];
      if ( map[next_y][next_x] == 1 ) break;

      now_x = now_x - dx[d];
      now_y = now_y - dy[d];

      continue;
    }

    if ( d == 0 ) {
      d = 3;
    } else {
      d = d - 1;
    }
    if ( map[now_y + dy[d]][now_x + dx[d]] == 0 ) {
      now_x = now_x + dx[d];
      now_y = now_y + dy[d];
      continue;
    }
  }

  int ans = 0;

  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      if ( map[y][x] == 9 ){
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
