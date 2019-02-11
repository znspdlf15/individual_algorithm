#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N;
const int MAX = 20;
int map[MAX][MAX];
int ans = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int count, int next_map[MAX][MAX]){
  if ( count == 5 ) {
    for ( int i = 0; i < N; i++ ){
      for ( int j = 0; j < N; j++ ){
        ans = max(next_map[i][j], ans);
      }
    }

    return;
  }

  // for ( int i = 0; i < N; i++ ){
  //   for ( int j = 0; j < N; j++ ){
  //     cout << next_map[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;
  vector<int> line[MAX];
  int temp_map[MAX][MAX];

  // 위쪽으로 가는 경우?
  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < N; x++ ){
      int point = next_map[y][x];
      if ( point == 0 ) continue;

      if ( line[x].empty() ){
        line[x].push_back(point);
        continue;
      }

      if ( line[x].back() == point ){
        line[x].back() *= 2;
      } else {
        line[x].push_back(point);
      }
    }
  }

  memset(temp_map, 0, sizeof(temp_map));

  for ( int x = 0; x < N; x++ ){
    for ( int y = line[x].size()-1; y >= 0; y-- ){
      int point = line[x].back();
      temp_map[y][x] = point;
      line[x].pop_back();
    }
  }

  bfs(count+1, temp_map);

  // 아래 쪽으로 가는 경우?
  for ( int y = N-1; y >= 0; y-- ){
    for ( int x = 0; x < N; x++ ){
      int point = next_map[y][x];
      if ( point == 0 ) continue;

      if ( line[x].empty() ){
        line[x].push_back(point);
        continue;
      }

      if ( line[x].back() == point ){
        line[x].back() *= 2;
      } else {
        line[x].push_back(point);
      }
    }
  }

  memset(temp_map, 0, sizeof(temp_map));

  for ( int x = 0; x < N; x++ ){
    int size = line[x].size();
    for ( int y = N-size; y < N; y++ ){
      int point = line[x].back();
      temp_map[y][x] = point;
      line[x].pop_back();
    }
  }
  bfs(count+1, temp_map);

  // 왼쪽으로 가는 경우?
  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < N; x++ ){
      int point = next_map[y][x];
      if ( point == 0 ) continue;

      if ( line[y].empty() ){
        line[y].push_back(point);
        continue;
      }

      if ( line[y].back() == point ){
        line[y].back() *= 2;
      } else {
        line[y].push_back(point);
      }
    }
  }

  memset(temp_map, 0, sizeof(temp_map));

  for ( int y = 0; y < N; y++ ){
    for ( int x = line[y].size()-1; x >= 0; x-- ){
      int point = line[y].back();
      temp_map[y][x] = point;
      line[y].pop_back();
    }
  }
  bfs(count+1, temp_map);

  // 오른쪽으로 가는 경우?
  for ( int y = N-1; y >= 0; y-- ){
    for ( int x = 0; x < N; x++ ){
      int point = next_map[y][x];
      if ( point == 0 ) continue;

      if ( line[y].empty() ){
        line[y].push_back(point);
        continue;
      }

      if ( line[y].back() == point ){
        line[y].back() *= 2;
      } else {
        line[y].push_back(point);
      }
    }
  }

  memset(temp_map, 0, sizeof(temp_map));

  for ( int y = 0; y < N; y++ ){
    int size = line[y].size();
    for ( int x = N-size; x < N; x++ ){
      int point = line[y].back();
      temp_map[y][x] = point;
      line[y].pop_back();
    }
  }
  bfs(count+1, temp_map);
}
int main(){

  cin >> N;

  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < N; j++ ){
      cin >> map[i][j];
    }
  }

  bfs(0, map);

  cout << ans << endl;


  return 0;
}
