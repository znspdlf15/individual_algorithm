#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M; // height, width
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> virus;

int ans = 0;

int get_safe_area(int map[8][8], int width, int height){
    int count = 0;
    int n, m;

    for ( n = 0; n < height; n++ ){
        for ( m = 0; m < width; m++){
            if ( map[n][m] == 0 ){
                count++;
            }
        }
    }

    return count;
}

void spread_virus(int map[8][8], vector<pair<int, int>> v_virus){
    queue<pair<int, int>> q;

    vector<pair<int, int>>::iterator iter;

    for(int a = 0; a < v_virus.size(); a++) {
        q.push(v_virus[a]);
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

            if ( map[nextY][nextX] == 0 ) {
                map[nextY][nextX] = 2;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
}
void set_wall(int map[8][8], int count, int x, int y){
    if ( count <= 0 ) {
        int copy_map[8][8] = {0, };

        for (int n = 0; n < N; n++ ){
            for (int m = 0; m < M; m++ ){
                copy_map[m][n] = map[m][n];
            }
        }
        
        spread_virus(copy_map, virus);
        int tmp = get_safe_area(copy_map, M, N);
        if ( ans < tmp ){
            for (int n = 0; n < N; n++ ){
                for (int m = 0; m < M; m++ ){
                    cout << copy_map[n][m];
                }
                cout << endl;
            }
            cout << endl;
        }
        ans = max(ans, tmp);

        return;
    }
    
    for (int n = 0; n < N; n++ ){
        for (int m = 0; m < M; m++ ){
            if ( map[n][m] == 0 ){
                map[n][m] = 1;
                set_wall(map, count-1, 0, 0);
                map[n][m] = 0;
            }
        }
    }
}

int main(){
    int map[8][8] = {0, };
    
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

    set_wall(map, 3, 0, 0);

    cout << ans << endl;
    return 0;

}