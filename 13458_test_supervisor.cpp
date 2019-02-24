#include <iostream>
#include <stdio.h>
using namespace std;
int N, B, C; // test_room count, tester number
int A[1000000];
int main(){
  cin >> N;

  for ( int n = 0; n < N; n++ ){
    scanf("%d", &A[n]);
  }

  cin >> B >> C;

  long long ans = 0;
  for ( int n = 0; n < N; n++ ){
    ans++;
    A[n] -= B;
    if ( A[n] <= 0 ) continue;

    if ( A[n] % C == 0 ){
      ans += A[n] / C;
    } else {
      ans += A[n] / C + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
