#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
typedef struct SLevel{
  int num;
  int len;
}TLevel;
int main(){
  int N, L;
  int map[100][100];

  cin >> N >> L;

  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < N; x++ ){
      cin >> map[y][x];
    }
  }

  int ans = 2 * N;
  // vertical line search
  vector<TLevel> level;

  for ( int y = 0; y < N; y++ ){
    level.push_back( {.num = map[y][0], .len = 1} );
    for ( int x = 1; x < N; x++ ){
      if ( level.back().num == map[y][x]){
        level.back().len++;
      } else {
        level.push_back( {.num = map[y][x], .len = 1} );
      }
    }

    for ( int x = 0; x < level.size()-1; x++ ){
      if ( abs(level[x].num - level[x+1].num) >= 2 ){
        ans--;
        break;
      }
      if ( level[x].num > level[x+1].num ){
        level[x+1].len -= L;
      } else {
        level[x].len -= L;
      }
      if ( level[x+1].len < 0 || level[x].len < 0 ){
        ans--;
        break;
      }
    }

    level.clear();
  }

  // horizontal line search
  for ( int x = 0; x < N; x++ ){
    level.push_back( {.num = map[0][x], .len = 1} );
    for ( int y = 1; y < N; y++ ){
      if ( level.back().num == map[y][x]){
        level.back().len++;
      } else {
        level.push_back( {.num = map[y][x], .len = 1} );
      }
    }

    for ( int x = 0; x < level.size()-1; x++ ){
      if ( abs(level[x].num - level[x+1].num) >= 2 ){
        ans--;
        break;
      }
      if ( level[x].num > level[x+1].num ){
        level[x+1].len -= L;
      } else {
        level[x].len -= L;
      }
      if ( level[x+1].len < 0 || level[x].len < 0 ){
        ans--;
        break;
      }
    }

    level.clear();
  }

  cout << ans << endl;
  return 0;
}
