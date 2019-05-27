#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
  int M, N, L;  // 사대수, 동물수, 사정거리

  int position[100000];

  cin >> M >> N >> L;
  for ( int m = 0; m < M; m++ ){
    scanf("%d", &position[m]);
  }

  sort(position, position+M);

  int answer = 0;
  for ( int n = 0; n < N; n++ ){
    int x, y;
    scanf("%d%d", &x, &y);

    int start_idx = 0;
    int end_idx = M-1;
    int target_idx;
    while ( true ){
      int center_idx = (start_idx + end_idx) / 2;
      if ( position[center_idx] >= x ){
        end_idx = center_idx;
      } else {
        start_idx = center_idx;
      }
      if ( end_idx - start_idx == 1 ){
        if ( position[end_idx] - x > x - position[start_idx]){
          target_idx = start_idx;
        } else {
          target_idx = end_idx;
        }
        break;
      }
    }

    if ( abs(position[target_idx] - x) + y <= L ){
      answer++;
    }
  }

  cout << answer << endl;

  return 0;
}
