#include <iostream>
#include <deque>
using namespace std;
int N, K, L; // size, apple number, conversion number
int map[100][100];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(){
  cin >> N >> K;

  for ( int k = 0; k < K; k++ ){
    int x, y;
    cin >> y >> x;
    map[y-1][x-1] = 1;
  }

  deque<pair<int, int> > snake;

  snake.push_back(make_pair(0, 0));
  map[0][0] = 9;

  cin >> L;

  int dir = 0;
  int count = 0;
  int pre_count = 0;
  int ans = 0;
  bool find = false;
  for ( int l = 0; l < L; l++ ){
    char input_dir;
    cin >> count >> input_dir;

    for ( int n = 0; n < count - pre_count; n++ ){
      if ( !find ) ans++;
      int headX = snake.back().first + dx[dir];
      int headY = snake.back().second + dy[dir];

      snake.push_back(make_pair(headX, headY));

      if ( map[headY][headX] == 9 || headX < 0 || headX >= N || headY < 0 || headY >= N ){
        find = true;
        cout << ans << endl;
        return 0;
      }

      if ( map[headY][headX] != 1 ){
        int tailX = snake.front().first;
        int tailY = snake.front().second;

        map[tailY][tailX] = 0;
        snake.pop_front();
      }

      map[headY][headX] = 9;
    }

    if ( input_dir == 'D' ){
      dir++;
    } else if ( input_dir == 'L' ){
      dir--;
    }

    if ( dir < 0 ) {
      dir += 4;
    } else if ( dir >= 4 ) {
      dir -= 4;
    }
    pre_count = count;
  }

  if ( !find ){
    while ( true ){
      ans++;
      int headX = snake.back().first + dx[dir];
      int headY = snake.back().second + dy[dir];

      if ( map[headY][headX] == 9 || headX < 0 || headX >= N || headY < 0 || headY >= N ) break;

      snake.push_back(make_pair(headX, headY));

      if ( map[headY][headX] != 1 ){
        int tailX = snake.front().first;
        int tailY = snake.front().second;

        map[tailY][tailX] = 0;
        snake.pop_front();
      }

      map[headY][headX] = 9;
    }
  }

  cout << ans << endl;
  return 0;
}
