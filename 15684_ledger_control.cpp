#include <iostream>
#include <algorithm>
using namespace std;
int N, M; // vertical line, horizontal line
int H;    //
int line[9][30] = {0, };
int ans = 1000000;

int start_ladder(int src){
  for ( int h = 0; h < H; h++ ){
    if ( src < N ){
      if ( line[src][h] ){
        src++;
        continue;
      }
    }
    if ( src > 0 ){
      if ( line[src-1][h] ){
        src--;
      }
    }
  }

  return src;
}

bool chk_perfect_ladder(){
  for ( int n = 0; n < N; n++ ){
    if ( start_ladder(n) != n ){
      return false;
    }
  }

  return true;
}

bool dfs(int count, int col, int row, int org_count){
  if ( count == org_count ) {
    if ( chk_perfect_ladder() ) {
      ans = min(org_count, ans);
      return true;
    }
    return false;
  }

  for ( int c = col; c < N; c++ ){
    for ( int r = 0; r < H; r++ ){
      if ( line[c][r] ) continue;
      if ( c < N-1 )
        if ( line[c+1][r] ) continue;

      if ( c > 0 )
        if ( line[c-1][r] ) continue;

      line[c][r] = 1;
      if ( dfs(count+1, c, r, org_count) ){
        return true;
      }
      line[c][r] = 0;
    }
  }
  return false;
}

int get_min(int count){
  int c;
  for ( c = 0; c <= count; c++ ){
    if ( dfs(0, 0, 0, c) ) break;
  }

  if ( c > count ) {
    return -1;
  } else {
    return ans;
  }
}

int main(){
  cin >> N >> M >> H;

  for ( int i = 0; i < M; i++ ){
    int row, col;
    cin >> row >> col;
    line[col-1][row-1] = 1;
  }

  cout << get_min(3) << endl;

  return 0;
}
