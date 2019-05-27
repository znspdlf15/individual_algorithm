#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
  int tree[100000];
  int N;
  int max_cf = 0x7fffffff; // 최대 공약수

  cin >> N;

  int number;
  cin >> tree[0];

  for ( int i = 1; i < N; i++ ){
    int diff;
    scanf("%d", &tree[i]);
    diff = tree[i] - tree[i-1];
    if ( i == 1 ) max_cf = diff;
    if ( diff % max_cf == 0 ) continue;

    for ( int a = diff/2; a >= 1; a-- ){
      if ( diff % a == 0 && max_cf % a == 0 ){
        max_cf = a;
        break;
      }
    }
  }

  int answer = 0;
  for ( int i = 1; i < N; i++ ){
    int diff = tree[i] - tree[i-1];
    answer += diff / max_cf - 1;
  }

  cout << answer << endl;
  return 0;
}
