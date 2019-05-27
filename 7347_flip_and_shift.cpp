#include <iostream>
#include <math.h>
using namespace std;

int N;
int main(){
  cin >> N;

  for ( int n = 0; n < N; n++ ){
    int count;
    int odd = 0;
    int even = 0;
    cin >> count;
    for ( int i = 0; i < count; i++ ){
      int number;
      cin >> number;

      if ( number == 1 ){
        if ( i % 2 == 0 ){
          even++;
        } else {
          odd++;
        }
      }    
    }
    bool success = true;
    if ( count % 2 == 0 && abs(even-odd) > 1 ){
      success = false;
    }

    if ( success ){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
