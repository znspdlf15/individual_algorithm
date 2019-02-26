#include <iostream>
#include <vector>
using namespace std;
typedef struct tpoint{
  int x, y;
  int dir;
}TPoint;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int map[102][102] = {0, };

int main(){
  int N;  // dragon curve's count

  cin >> N;

  while ( N-- ){
    int x, y, d, g;
    vector<TPoint> dragon;
    cin >> x >> y >> d >> g;

    dragon.push_back({.x = x, .y = y, .dir = d});
    while ( g-- ){
      int size = dragon.size();
      for ( int i = size-1; i >= 0; i-- ){
        TPoint temp = dragon[i];
        TPoint last_dragon = dragon.back();
        dragon.push_back({.x = last_dragon.x + dx[last_dragon.dir], .y = last_dragon.y + dy[last_dragon.dir], .dir = (temp.dir + 1) % 4});
      }
    }
    for ( int n = 0; n < dragon.size(); n++ ){
      int x = dragon[n].x;
      int y = dragon[n].y;
      int dir = dragon[n].dir;
      map[y][x] = 1;
      map[y + dy[dir]][x + dx[dir]] = 1;
    }
  }

  int ans = 0;
  for ( int y = 0; y <= 100; y++ ){
    for ( int x = 0; x <= 100; x++ ){
      if ( map[y][x] && map[y][x+1] && map[y+1][x] && map[y+1][x+1]) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
