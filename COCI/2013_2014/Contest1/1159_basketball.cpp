#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int N;
  int alphabet[26] = {0, };

  cin >> N;

  for ( int n = 0; n < N; n++ ){
    char name[31];
    scanf("%s", name);
    alphabet[name[0] - 'a']++;
  }

  bool success = false;
  for ( int n = 0; n < 26; n++ ){
    if ( alphabet[n] >= 5 ){
      printf("%c", n + 'a');
      success = true;
    }
  }
  if ( !success ){
    printf("PREDAJA");
  }
  printf("\n");


  return 0;
}
