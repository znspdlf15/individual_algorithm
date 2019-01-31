#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M; // width, height
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void print_safe_area(int map[8][8], int width, int height){
    int count = 0;
    int n, m;

    for ( n = 0; n < height; n++ ){
        for ( m = 0; m < width; m++){
            // cout << map[n][m] << " ";
            if ( map[n][m] == 0 ){
                count++;
            }
        }
        // cout << endl;
    }

    cout << count << endl;
}
void spread_virus(int map[8][8], vector<pair<int, int>> v_virus){
    queue<pair<int, int>> q;

    vector<pair<int, int>>::iterator iter;

    for ( iter = v_virus.begin(); iter != v_virus.end(); iter++ ){
        q.push(*iter);
    }

    while ( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for ( int n = 0; n < 4; n++){
            int nextX = x + dx[n];
            int nextY = y + dy[n];

            if ( nextX < 0 || nextX >= M ) continue;
            if ( nextY < 0 || nextY >= N ) continue;

            if ( map[nextX][nextY] == 0 ) {
                map[nextX][nextY] = 2;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
}
int main(){
    int map[8][8] = {0, };
    vector<pair<int, int>> virus;
    
    int virus_num = 0;

    cin >> N >> M;
    int n, m;
    for ( n = 0; n < N; n++ ){
        for ( m = 0; m < M; m++ ){
            cin >> map[n][m];
            if ( map[n][m] == 2 ){
                virus.push_back(make_pair(m, n));
                virus_num++;
            }
        }
    }
    spread_virus(map, virus);

    print_safe_area(map, M, N);

    return 0;
}