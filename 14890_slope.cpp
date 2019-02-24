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
  int slope[100][100];

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
    TLevel temp;
    temp.num = map[y][0];
    temp.len = 1;
    level.push_back(temp);
    for ( int x = 1; x < N; x++ ){
      if ( level.back().num == map[y][x]){
        level.back().len++;
      } else {
        TLevel temp;
        temp.num = map[y][x];
        temp.len = 1;
        level.push_back(temp);
      }
    }
    for ( int x = 0; x < level.size()-1; x++ ){
      if ( level[x+1].num - level[x].num >= 2 ){
        ans--;
        break;
      } else if ( level[x+1].num - level[x].num == 1 ){
        level[x].len -= L;
        if ( level[x].len < 0 ){
          ans--;
          break;
        }
      }

      if ( level[x].num - level[x+1].num >= 2 ){
        ans--;
        break;
      } else if ( level[x].num - level[x+1].num == 1 ){
        level[x+1].len -= L;
        if ( level[x+1].len < 0 ){
          ans--;
          break;
        }
      }
    }

    level.clear();
  }

  // horizontal line search
  for ( int x = 0; x < N; x++ ){
    TLevel temp;
    temp.num = map[0][x];
    temp.len = 1;
    level.push_back(temp);
    for ( int y = 1; y < N; y++ ){
      if ( level.back().num == map[y][x]){
        level.back().len++;
      } else {
        TLevel temp;
        temp.num = map[y][x];
        temp.len = 1;
        level.push_back(temp);
      }
    }
    for ( int x = 0; x < level.size()-1; x++ ){
      if ( level[x+1].num - level[x].num >= 2 ){
        ans--;
        break;
      } else if ( level[x+1].num - level[x].num == 1 ){
        level[x].len -= L;
        if ( level[x].len < 0 ){
          ans--;
          break;
        }
      }

      if ( level[x].num - level[x+1].num >= 2 ){
        ans--;
        break;
      } else if ( level[x].num - level[x+1].num == 1 ){
        level[x+1].len -= L;
        if ( level[x+1].len < 0 ){
          ans--;
          break;
        }
      }
    }

    level.clear();
  }
  cout << ans << endl;
  return 0;
}
