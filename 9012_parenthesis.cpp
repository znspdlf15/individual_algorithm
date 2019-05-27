#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
  int N;

  cin >> N;
  for ( int n = 0; n < N; n++ ){
    char tmp[51];
    int left = 0;
    int right = 0;
    scanf("%s", tmp);
    int size = strlen(tmp);
    bool success = true;
    for ( int s = 0; s < size; s++ ){
      if ( tmp[s] == '(' ){
        left++;
      } else if ( tmp[s] == ')' ){
        right++;
        if ( left < right ){
          success = false;
          break;
        }
      }
    }
    if ( left != right ){
      success = false;
    }
    if ( success ){
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
