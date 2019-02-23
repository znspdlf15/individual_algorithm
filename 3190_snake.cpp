#include <iostream>
#include <deque>
#include <vector>
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
  vector<pair<int, char> > command;

  // init snake
  snake.push_back(make_pair(0, 0));
  map[0][0] = 9;

  // init command
  cin >> L;
  for ( int l = 0; l < L; l++ ){
    int count;
    char dir;
    cin >> count >> dir;
    command.push_back(make_pair(count, dir));
  }

  int dir = 0;
  int cmd_idx = 0;
  int ans = 0;
  bool find = false;
  while ( true ){
    ans++;
    int headX = snake.back().first + dx[dir];
    int headY = snake.back().second + dy[dir];

    if ( command[cmd_idx].first == ans ){
      char next_dir = command[cmd_idx].second;
      if ( next_dir == 'D' ){
        dir++;
      } else if ( next_dir == 'L' ){
        dir--;
      }

      if ( dir < 0 ) {
        dir += 4;
      } else if ( dir >= 4 ) {
        dir -= 4;
      }
      cmd_idx++;
    }

    if ( map[headY][headX] == 9 || headX < 0 || headX >= N || headY < 0 || headY >= N ) break;

    if ( map[headY][headX] != 1 ){
      int tailX = snake.front().first;
      int tailY = snake.front().second;

      map[tailY][tailX] = 0;
      snake.pop_front();
    }

    snake.push_back(make_pair(headX, headY));
    map[headY][headX] = 9;
  }

  cout << ans << endl;
  return 0;
}
