#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

char tmap[22][22] = {0, };
bool visit[26] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int T;
int R, C;

int getAnswer(int nowX, int nowY){
  int aidx = tmap[nowY][nowX]-'A';
  visit[aidx] = true;

  int candidate = 0;

  for ( int d = 0; d < 4; d++ ){
    int nextX = nowX + dx[d];
    int nextY = nowY + dy[d];

    int nextIdx = tmap[nextY][nextX]-'A';
    if ( nextX < 1 || nextX > C || nextY < 1 || nextY > R ) continue;
    if ( visit[nextIdx] ) continue;

    candidate = max(candidate, getAnswer(nextX, nextY));
  }

  visit[aidx] = false;
  return candidate + 1;
}
int main(){

  cin >> T;

  for ( int t = 1; t <= T; t++ ){
    cin >> R >> C;
    for ( int y = 1; y <= R; y++ ){
      scanf("%s", &tmap[y][1]);
    }
    cout << "#" << t << " " << getAnswer(1, 1) << endl;
  }

  return 0;
}
