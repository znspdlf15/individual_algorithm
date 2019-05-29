#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int dx[4] = {1, 1, 0, -1};
int dy[4] = {0, 1, 1, 1};

int main(){
  int seat[52][52] = {0, };
  int R, S;

  cin >> R >> S;

  for ( int y = 1; y <= R; y++ ){
    char row[52];
    scanf("%s", row);

    for ( int x = 1; x <= S; x++ ){
      if ( row[x-1] == '.' ){
        seat[y][x] = 0;
      } else if ( row[x-1] == 'o' ){
        seat[y][x] = 1;
      }
    }
  }

  int answer = 0;
  int maxima = 0;
  for ( int y = 1; y <= R; y++ ){
    for ( int x = 1; x <= S; x++ ){
      if ( seat[y][x] == 0 ) {
        int res = 0;
        for ( int d = 0; d < 4; d++ ){
          if ( seat[y + dy[d]][x + dx[d]] == 1 ){
            res++;
          }
          if ( seat[y - dy[d]][x - dx[d]] == 1 ){
            res++;
          }
        }
        maxima = max(res, maxima);
        continue;
      }
      for ( int d = 0; d < 4; d++ ){
        if ( seat[y + dy[d]][x + dx[d]] == 1 ){
          answer++;
        }
      }
    }
  }

  cout << answer + maxima << endl;

  return 0;
}
