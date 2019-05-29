#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int soil[52][52] = {0, };
int sum[52][52][52][52] = {0, };

int getPreSum(int sx, int sy, int ex, int ey){
  int sum = 0;

  int tmp;
  if ( sx > ex ){ tmp = sx; sx = ex; ex = tmp; }
  if ( sy > ey ){ tmp = sy; sy = ey; ey = tmp; }

  for ( int y = sy; y <= ey; y++ ){
    for ( int x = sx; x <= ex; x++ ){
      sum += soil[y][x];
    }
  }
  return sum;
}

int getSum(int sx, int sy, int ex, int ey){
  // int tmp;
  // if ( sx > ex ){ tmp = sx; sx = ex; ex = tmp; }
  // if ( sy > ey ){ tmp = sy; sy = ey; ey = tmp; }
  // return sum[ey][ex] - sum[ey][sx-1] - sum[sy-1][ex] + sum[sy-1][sx-1];

  return sum[sy][sx][ey][ex];
}


int main(){
  int N;

  cin >> N;

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      scanf("%d", &soil[y][x]);
    }
  }

  for ( int sy = 1; sy <= N; sy++ ){
    for ( int sx = 1; sx <= N; sx++ ){
      for ( int ey = 1; ey <= N; ey++ ){
        for ( int ex = 1; ex <= N; ex++ ) {
          sum[sy][sx][ey][ex] = getPreSum(sx, sy, ex, ey);
        }
      }
    }
  }

  int answer = 0;
  for ( int sy1 = 1; sy1 <= N; sy1++ ){
    for ( int sx1 = 1; sx1 <= N; sx1++ ){
      map<int, int> mp;
      for ( int ex1 = 1; ex1 <= sx1; ex1++ ){
        for ( int ey1 = 1; ey1 <= sy1; ey1++ ){
          int rect = getSum(sx1, sy1, ex1, ey1);
          if ( !mp.count(rect) ){
            mp[rect] = 1;
          } else {
            mp[rect]++;
          }
        }
      }

      for ( int ex1 = sx1+1; ex1 <= N; ex1++ ){
        for ( int ey1 = sx1+1; ey1 <= N; ey1++ ){
          int rect = getSum(sx1+1, sy1+1, ex1, ey1);
          answer += mp[rect];
        }
      }

      mp.clear();
      for ( int ex1 = 1; ex1 <= sx1; ex1++ ){
        for ( int ey1 = sy1; ey1 <= N; ey1++ ){
          int rect = getSum(sx1, sy1, ex1, ey1);
          if ( !mp.count(rect) ){
            mp[rect] = 1;
          } else {
            mp[rect]++;
          }
        }
      }

      for ( int ex1 = sx1+1; ex1 <= N; ex1++ ){
        for ( int ey1 = 1; ey1 <= sy1-1; ey1++ ){
          int rect = getSum(sx1+1, sy1-1, ex1, ey1);
          answer += mp[rect];
        }
      }
    }
  }

  cout << answer << endl;

  return 0;
}
