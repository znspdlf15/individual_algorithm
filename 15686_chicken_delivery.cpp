#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000000;
using namespace std;
int N, M;
typedef struct tpoint{
  int x, y;
}TPoint;

vector<TPoint> home;
vector<TPoint> chicken;

int get_all_distance(vector<TPoint> choice){
  int ans = 0;
  int home_size = home.size();
  int choice_size = choice.size();

  for ( int i = 0; i < home_size; i++ ){
    int m = INF;
    for ( int j = 0; j < choice_size; j++ ){
      int dist = abs(home[i].x - choice[j].x) + abs(home[i].y - choice[j].y);
      m = min(m, dist);
    }
    ans += m;
  }

  return ans;
}

int ans = INF;
void choose_chicken(vector<TPoint> choice, int idx){
  if ( choice.size() == M ){
    ans = min(ans, get_all_distance(choice));
    return;
  }

  for ( int i = idx; i < chicken.size(); i++ ){
    choice.push_back(chicken[i]);
    choose_chicken(choice, i+1);
    choice.pop_back();
  }
}

int main(){
  cin >> N >> M;

  for ( int y = 1; y <= N; y++ ){
    for ( int x = 1; x <= N; x++ ){
      int data;
      cin >> data;
      if ( data == 1 ){
        home.push_back({.x = x, .y = y});
      } else if ( data == 2 ){
        chicken.push_back({.x = x, .y = y});
      }
    }
  }

  vector<TPoint> empty;
  choose_chicken(empty, 0);

  cout << ans << endl;

  return 0;
}
