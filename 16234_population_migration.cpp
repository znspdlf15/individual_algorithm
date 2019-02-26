#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int map[52][52];
int area[52][52] = {0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int area_population[3000] = {0, };
int area_count[3000] = {0, };

int N;
int L, R;


int get_answer(){
  int ans = 0;

  while ( true ){
    int now_area = 0;
    memset(area, 0, sizeof(area));

    for ( int y = 1; y <= N; y++ ){
      for ( int x = 1; x <= N; x++ ){
        if ( area[y][x] != 0 ) continue;

        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        area[y][x] = ++now_area;

        while ( !q.empty() ){
          int nowX = q.front().first;
          int nowY = q.front().second;
          q.pop();
          for ( int d = 0; d < 4; d++ ){
            int nextX = nowX + dx[d];
            int nextY = nowY + dy[d];

            if ( nextX <= 0 || nextX > N || nextY <= 0 || nextY > N ) continue;
            if ( area[nextY][nextX] != 0 ) continue;

            int diff = abs(map[nowY][nowX] - map[nextY][nextX]);
            if ( !(diff >= L && diff <= R) ) continue;

            q.push(make_pair(nextX, nextY));
            area[nextY][nextX] = area[y][x];
          }
        }
      }
    }

    memset(area_population, 0, sizeof(area_population));
    memset(area_count, 0, sizeof(area_count));
    for ( int y = 1; y <= N; y++ ){
      for ( int x = 1; x <= N; x++ ){
        int target_area = area[y][x];
        area_population[target_area] += map[y][x];
        area_count[target_area] += 1;
      }
    }
    for ( int y = 1; y <= N; y++ ){
      for ( int x = 1; x <= N; x++ ){
        int target_area = area[y][x];
        map[y][x] = int(area_population[target_area] / area_count[target_area]);
      }
    }

    // for ( int y = 1; y <= N; y++ ){
    //   for ( int x = 1; x <= N; x++ ){
    //     cout << area[y][x];
    //   }
    //   cout << endl;
    // }

    if ( now_area == N * N ) break;
    ans++;
  }

  return ans;
}
int main(){
  cin >> N >> L >> R;

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      cin >> map[y][x];
    }
  }

  cout << get_answer() << endl;
  return 0;
}
