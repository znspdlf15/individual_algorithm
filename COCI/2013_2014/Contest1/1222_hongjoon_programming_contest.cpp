#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int team_count_able[2000001] = {0, };

long long getPartedStudentCount(int minima){
  long long sum = 0;

  return minima * team_count_able[minima];
}
int main(){

  cin >> N;

  int maxima = 0;

  for ( int n = 0; n < N; n++ ){
    int cnt;
    scanf("%d", &cnt);
    for ( int i = 1; i*i <= cnt; i++ ){
      if ( cnt % i == 0 ){
        team_count_able[i]++;
        if ( i != cnt/i ){
          team_count_able[cnt/i]++;
        }
      }
    }
    maxima = max(maxima, cnt);
  }

  long long answer = 0;

  for ( long long i = 1; i <= maxima; i++ ){
    if ( team_count_able[i] < 2 ) continue;
    answer = max(answer, i * team_count_able[i]);
  }

  cout << answer << endl;

  return 0;
}
