#include <iostream>
#include <algorithm>
using namespace std;
int N;

int start_idx[20] = {0, };
int link_idx[20] = {0, };

int ans = 5000;

void dfs(int member[20][20], int count, int enroll){
    if ( enroll >= N ) return;
    if ( count == 0 ) {
        for ( int i = 0; i < N; i++ ){
            link_idx[i] = 1 - start_idx[i];
        }

        int start_sum = 0;
        int link_sum = 0;

        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                if ( start_idx[i] && start_idx[j] ){
                    start_sum += member[i][j];
                }
                if ( link_idx[i] && link_idx[j] ){
                    link_sum += member[i][j];
                }
            }
        }

        int diff = start_sum - link_sum;
        if ( diff < 0 ){
            diff = -diff;
        }

        ans = min(ans, diff);
    }

    start_idx[enroll] = 1;
    for ( int i = enroll+1; i < N; i++ ){
        dfs(member, count-1, i);
    }
    start_idx[enroll] = 0;
}
int main(){
    
    int member[20][20];

    cin >> N;

    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            cin >> member[i][j];
        }
    }

    for ( int i = 0; i < N/2 + 1; i++){
        dfs(member, N/2, i);
    }
    

    cout << ans << endl;

    return 0;
}