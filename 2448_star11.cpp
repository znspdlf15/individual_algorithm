#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int N;

char map[1025][1025] = {0, };

void push_to_q(int level){
  if ( level <= 1 ){
    map[1][1] = 1;
    return;
  }

  int move = 1 << (level-2);
  push_to_q(level-1);
  for ( int y = 1; y <= move; y++ ){
    for ( int x = 1; x <= y; x++ ){
      map[y+move][x] = map[y][x];
      map[y+move][x+move] = map[y][x];
    }
  }

}

void print_answer(){
  for ( int y = 1; y <= N/3; y++ ){
    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }

    for ( int x = 1; x <= y; x++ ){
      if ( map[y][x] ){
        printf("  *   ");
      } else {
        printf("      ");
      }
    }
    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }
    printf("\n");

    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }
    for ( int x = 1; x <= y; x++ ){
      if ( map[y][x] ){
        printf(" * *  ");
      } else {
        printf("      ");
      }
    }
    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }
    printf("\n");

    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }
    for ( int x = 1; x <= y; x++ ){
      if ( map[y][x] ){
        printf("***** ");
      } else {
        printf("      ");
      }
    }
    for ( int x = 0; x < N/3-y; x++ ){
      printf("   ");
    }
    printf("\n");
  }
}

int main(){
  cin >> N;

  int level = 1;
  while ( N/3 != 1 << (level-1) ){
     level++;
  }

  push_to_q(level);
  print_answer();
  return 0;
}
