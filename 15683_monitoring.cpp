#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define U (1<<0)
#define R (1<<1)
#define D (1<<2)
#define L (1<<3)

using namespace std;
typedef struct TCamera{
  int x, y;
  char type;
}Camera;

char org_map[8][8];
int N, M; // height, width
vector<Camera> cameras;

vector<int> moving[5] = {
    {U, R, D, L},
    {U|D, R|L},
    {U|R, U|L, D|R, D|L},
    {U|R|L, D|R|L, R|U|D, L|U|D},
    {U|R|D|L}
};

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
  int dx[4] = { 0, 1, 0, -1 };
  int dy[4] = { -1, 0, 1, 0 };

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

  int type = (int)(cam.type - '0');

  for ( int i = 0; i < moving[type-1].size(); i++ ){
    copy_arr(temp_map, target);
    for ( int b = 0; b < 4; b++ ){
      int move = 1 << b;
      move = moving[type-1][i] & move;
      if ( move != 0 ){
        monitor(temp_map, cam.x, cam.y, b);
      }
    }
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
      org_map[y][x] = input;
    }
  }

  dfs(cameras.size(), org_map);

  cout << ans << endl;

  return 0;
}
