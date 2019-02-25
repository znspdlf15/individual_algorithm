#include <iostream>
#include <algorithm>
using namespace std;
int N, M; // vertical line, horizontal line
int H;    //
int line[9][30] = {0, };
int ans = -1;

int start_ledger(int src){
  for ( int h = 0; h < H; h++ ){
    if ( line[src][h] ){
      src++;
      continue;
    }
    if ( src > 0 ){
      if ( line[src-1][h] ){
        src--;
      }
    }
  }

  return src;
}

bool perfect_ledger(){
  for ( int n = 0; n < N; n++ ){
    if ( start_ledger(n) != n ){
      return false;
    }
  }
  return true;
}

void dfs(int count, int col, int row){
  if ( perfect_ledger() ) {
    ans = max(count, ans);
    return;
  }
  if ( count == 0 ) return;

  for ( int c = 0; c < N; c++ ){
    for ( int r = 0; r < H; r++ ){
      if ( line[c][r] ) continue;
      line[c][r] = 1;
      dfs(count-1, c, r);
      line[c][r] = 0;
    }
  }
}

int get_min(int count){
  for ( int c = 0; c < N; c++ ){
    for ( int r = 0; r < H; r++ ){
      dfs(count, c, r);
    }
  }

  return count - ans;
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
