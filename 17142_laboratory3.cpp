#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct virus{
  int x, y;
}Virus;

int N, M;
int map[52][52];
int copy_map[52][52];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<Virus> v_virus;
vector<Virus> active_virus;

int spread_virus(vector<Virus> v){
  queue<Virus> q;
  int empty = 0;

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      if ( map[y][x] == 2 ) {
        copy_map[y][x] = -1;
      } else {
        copy_map[y][x] = map[y][x];
      }
      if ( map[y][x] == 0 ) {
        empty++;
      }
    }
  }

  for ( int i = 0; i < v.size(); i++ ){
    copy_map[v[i].y][v[i].x] = 2;
    q.push(v[i]);
  }

  int depth = 0;

  while( !q.empty() ){
    int level_size = q.size();

    if ( empty == 0 ){
      return depth;
    }
    depth++;

    for ( int s = 0; s < level_size; s++ ){
      int nowX = q.front().x;
      int nowY = q.front().y;
      q.pop();

      for ( int d = 0; d < 4; d++ ){
        int nextX = nowX + dx[d];
        int nextY = nowY + dy[d];

        if ( nextX < 1 || nextX > N || nextY < 1 || nextY > N ) continue;
        if ( copy_map[nextY][nextX] > 0 ) continue;

        if ( copy_map[nextY][nextX] == 0 )
          empty--;
        Virus new_virus = { .x = nextX, .y = nextY };
        q.push(new_virus);
        copy_map[nextY][nextX] = 2;
      }
    }
  }
  return -1;
}

int final_answer = 0x7fffffff;

void select_virus(vector<Virus> v, vector<Virus> selected_virus, int count, int x){
  if ( count == 0 ){
    int output = spread_virus(selected_virus);
    if ( output != -1 ){
      final_answer = min(final_answer, output);
    }
    return;
  }

  int v_size = v.size();

  for ( int i = x; i < v_size; i++ ){
    selected_virus.push_back(v[i]);
    select_virus(v, selected_virus, count-1, i+1);
    selected_virus.pop_back();
  }
}

int main(){
  cin >> N >> M;

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      cin >> map[y][x];
      if ( map[y][x] == 2 ){
        Virus v = {.x = x, .y = y};
        v_virus.push_back(v);
      }
    }
  }

  vector<Virus> empty;
  select_virus(v_virus, empty, M, 0);

  if ( final_answer == 0x7fffffff ){
    cout << -1 << endl;
  } else {
    cout << final_answer << endl;
  }

  return 0;
}
