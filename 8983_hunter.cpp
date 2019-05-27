#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct animal{
  int x, y;
}Animal;

bool compare(Animal a, Animal b){
  return a.x < b.x;
}

int main(){
  int M, N, L;  // 사대수, 동물수, 사정거리

  int position[100000];
  Animal animals[100000];

  cin >> M >> N >> L;
  for ( int m = 0; m < M; m++ ){
    scanf("%d", &position[m]);
  }
  for ( int n = 0; n < N; n++ ){
    int x, y;
    scanf("%d%d", &x, &y);
    animals[n].x = x;
    animals[n].y = y;
  }

  sort(position, position+M);
  sort(animals, animals+N, compare);

  int answer = 0;
  int target_idx = 0;
  for ( int n = 0; n < N; n++ ){
    while ( position[target_idx] <= animals[n].x ){
      if ( target_idx >= M - 1 ) break;
      target_idx++;
    }

    int x = animals[n].x;
    int y = animals[n].y;
    if ( target_idx > 0 ){
      if ( abs(position[target_idx] - x) + y <= L || abs(position[target_idx-1] - x) + y <= L){
        answer++;
      }
    } else {
      if ( abs(position[target_idx] - x) + y <= L ){
        answer++;
      }
    }
  }

  cout << answer << endl;

  return 0;
}
