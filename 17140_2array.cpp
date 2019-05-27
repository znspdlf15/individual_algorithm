#include <iostream>
#include <algorithm>
using namespace std;

typedef struct line{
  int number;
  int count;
}Line;

bool compareByCount(const Line &a, const Line &b){
  return a.count < b.count;
}
bool compareByNumber(const Line &a, const Line &b){
  return a.number < b.number;
}
int main(){
  int data[100][100] = {0, };

  int r, c, k;
  cin >> r >> c >> k;

  for ( int y = 0; y < 3; y++ ){
    for ( int x = 0; x < 3; x++ ){
      cin >> data[y][x];
    }
  }

  int row = 3, column = 3;
  int answer = 0;

  while ( data[r-1][c-1] != k ){
    answer++;
    if ( answer > 100 ){
      answer = -1;
      break;
    }

    int max_row = 0;
    int max_column = 0;
    if ( row >= column ){
      for ( int y = 0; y < row; y++ ){
        Line counts[100];

        for ( int n = 0; n < 100; n++ ){
          counts[n].number = n+1;
          counts[n].count = 0;
        }

        for ( int x = 0; x < column; x++ ){
          int num = data[y][x];
          if ( num == 0 ) continue;
          counts[num-1].count++;
        }

        stable_sort(counts, counts+100, compareByNumber);
        stable_sort(counts, counts+100, compareByCount);

        int index = 0;
        for ( int i = 0; i < 100; i++ ){
          if ( counts[i].count != 0 ){
            data[y][index] = counts[i].number;
            data[y][index+1] = counts[i].count;
            index += 2;
          }
        }

        max_column = max(index, max_column);
        for ( ; index < 100; index++ ){
          data[y][index] = 0;
        }
      }
      column = max_column;
    } else {
      for ( int x = 0; x < column; x++ ){
        Line counts[100];

        for ( int n = 0; n < 100; n++ ){
          counts[n].number = n+1;
          counts[n].count = 0;
        }

        for ( int y = 0; y < column; y++ ){
          int num = data[y][x];
          if ( num == 0 ) continue;
          counts[num-1].count++;
        }

        stable_sort(counts, counts+100, compareByNumber);
        stable_sort(counts, counts+100, compareByCount);

        int index = 0;
        for ( int i = 0; i < 100; i++ ){
          if ( counts[i].count != 0 ){
            data[index][x] = counts[i].number;
            data[index+1][x] = counts[i].count;
            index += 2;
          }
        }
        max_row = max(index, max_row);
        for ( ; index < 100; index++ ){
          data[index][x] = 0;
        }
      }
      row = max_row;
    }
  }

  cout << answer << endl;

  return 0;
}
