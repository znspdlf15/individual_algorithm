#include <iostream>
#include <vector>
using namespace std;

int map[2001] = {0, };

int gcd(int a, int b){
  if ( b == 0 ){
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main(){
  int d1, d2;

  cin >> d1 >> d2;

  int answer = 0;
  for ( int i = d1; i <= d2; i++ ){
    vector<int> temp;
    for ( int n = 0; n < i; n++ ){
      int gcd_number = gcd(i, n);
      int boonmo = i / gcd_number;

      if ( !map[boonmo] ){
        answer++;
        temp.push_back(boonmo);
      }
    }
    for ( int i=0; i < temp.size(); i++ ){
      map[temp[i]] = 1;
    }
  }

  cout << answer << endl;
  return 0;
}
