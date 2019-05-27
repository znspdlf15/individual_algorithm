#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct struct_shark{
  int speed;
  int dir;
  int size;
}Shark;

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, -1, 1, 0, 0};

int main(){
  Shark *map[102][102] = {0, };

  int R, C, M;

  cin >> R >> C >> M;

  for ( int m = 0; m < M; m++ ){
    int r, c, s, d, z;

    cin >> r >> c >> s >> d >> z;

    map[r][c] = (Shark *)malloc(sizeof(Shark));
    Shark *shark = map[r][c];
    shark->speed = s;
    shark->dir = d;
    shark->size = z;
  }

  int answer = 0;
  for ( int x = 1; x <= C; x++ ){
    for ( int y = 1; y <= R; y++ ){
      if ( map[y][x] == 0 ) continue;
      Shark *target = map[y][x];
      answer += target->size;
      free(target);
      map[y][x] = 0;
      break;
    }

    Shark *moved_map[102][102] = {0, };

    for ( int xx = 1; xx <= C; xx++ ){
      for ( int yy = 1; yy <= R; yy++ ){
        if ( map[yy][xx] == 0 ) continue;
        Shark *target = map[yy][xx];
        int dir = target->dir;

        int nextX = xx + dx[dir]*target->speed;
        int nextY = yy + dy[dir]*target->speed;

        while ( nextX < 1 || nextX > C || nextY < 1 || nextY > R ){
          if ( nextX < 1 ){
            nextX = -nextX + 2;
            target->dir = 3;
          } else if ( nextX > C ){
            nextX = 2 * C - nextX;
            target->dir = 4;
          }
          if ( nextY < 1 ){
            nextY = -nextY + 2;
            target->dir = 2;
          } else if ( nextY > R ){
            nextY = 2 * R - nextY;
            target->dir = 1;
          }
        }

        if ( moved_map[nextY][nextX] == 0 ){
          moved_map[nextY][nextX] = target;
        } else {
          Shark *enemy = moved_map[nextY][nextX];
          if ( enemy->size < target->size ){
            moved_map[nextY][nextX] = target;
            free(enemy);
          } else {
            free(target);
          }
        }
      }
    }
    for ( int xx = 1; xx <= C; xx++ ){
      for ( int yy = 1; yy <= R; yy++ ){
        map[yy][xx] = moved_map[yy][xx];
      }
    }
  }

  cout << answer << endl;

  return 0;
}
