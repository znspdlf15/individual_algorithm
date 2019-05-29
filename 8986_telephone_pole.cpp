#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int numbers[100000];

long long f(int x){
  long long sum = 0;

  for ( int i = 1; i < N; i++ ){
    sum += abs(1LL * x * i - numbers[i]);
  }
  return sum;
}
int main(){
  cin >> N;

  long long sum = 0;

  for ( int n = 0; n < N; n++ ){
    scanf("%d", &numbers[n]);
  }

  int low = 1;
  int high = numbers[N-1];

  while ( high - low >= 3 ){
    long long f_p = f((low*2 + high)/3);
    long long f_q = f((low + high*2)/3);
    if ( f_p > f_q ){
      low = (low*2 + high)/3;
    } else {
      high = (low + high*2)/3;
    }
  }

  long long answer = 1e18;
  for ( int i = low; i <= high; i++ ){
    answer = min(answer, f(i));
  }

  printf("%lld", answer);
  return 0;
}
