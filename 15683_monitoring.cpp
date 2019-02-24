#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct TCamera{
  int x, y;
  char type;
}Camera;

char map[8][8];
int N, M; // height, width
vector<Camera> cameras;

int ans = 10000000;

int get_safe(char target[8][8]){
  int count = 0;
  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      if ( target[y][x] == '0' ){
        count++;
      }
    }
  }
  return count;
}

void copy_arr(char dest[8][8], char src[8][8]){
  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      dest[y][x] = src[y][x];
    }
  }
}

void monitor(char target[8][8], int x, int y, int dir){
  int dx[4] = { 1, -1, 0, 0 };
  int dy[4] = { 0, 0, 1, -1 };

  int nextX = x + dx[dir];
  int nextY = y + dy[dir];
  while ( nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && target[nextY][nextX] != '6' ){
    target[nextY][nextX] = '#';
    nextX = nextX + dx[dir];
    nextY = nextY + dy[dir];
  }
}

void dfs(int count, char target[8][8]){
  if ( count == 0 ) {
    ans = min(ans, get_safe(target));
    return;
  }

  char temp_map[8][8];
  Camera cam = cameras[count-1];

  if ( cam.type == '1' ){
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 1);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 2);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
  } else if ( cam.type == '2' ){
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 1);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 2);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
  } else if ( cam.type == '3' ){
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 2);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 2);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
  } else if ( cam.type == '4' ){
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 2);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 2);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 2);
    dfs(count-1, temp_map);
  } else if ( cam.type == '5' ){
    copy_arr(temp_map, target);
    monitor(temp_map, cam.x, cam.y, 0);
    monitor(temp_map, cam.x, cam.y, 1);
    monitor(temp_map, cam.x, cam.y, 2);
    monitor(temp_map, cam.x, cam.y, 3);
    dfs(count-1, temp_map);
  }
}

int main(){
  cin >> N >> M;

  for ( int y = 0; y < N; y++ ){
    for ( int x = 0; x < M; x++ ){
      char input;
      cin >> input;
      if ( input != '0' && input != '6' ){
        cameras.push_back({.x = x, .y = y, .type = input});
      }
      map[y][x] = input;
    }
  }

  dfs(cameras.size(), map);

  cout << ans << endl;

  return 0;
}
