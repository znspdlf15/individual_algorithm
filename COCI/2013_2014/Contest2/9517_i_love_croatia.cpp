#include <iostream>
using namespace std;

int main(){
  int now_time = 0;
  int bomb_time = 210;
  int player_count = 8;
  int now_player = 1;
  int q_count;

  cin >> now_player >> q_count;

  for ( int q = 1; q <= q_count; q++ ){
    int time;
    char type;

    cin >> time >> type;

    now_time += time;

    if ( now_time >= 210 ){
      cout << now_player << endl;
      break;
    }
    if ( type == 'T' ){
      now_player = now_player % player_count + 1;
    }
  }
  return 0;
}
