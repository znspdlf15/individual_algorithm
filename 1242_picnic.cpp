#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N, M, K;

    cin >> N >> M >> K;

    queue<int> q;
    queue<int> q2;

    int out_cnt = 0;
    int idx = 0;

    for ( int n = 1; n <= N; n++ ){
        q.push(n);
    }

    while( !q.empty() ){
        int x = q.front();
        idx++;
        if ( idx == M ){
            idx = 0;
            out_cnt++;
            if ( x == K ) break;
            q.pop();
        } else {
            q.push(x);
            q.pop();
        }
    }

    cout << out_cnt << endl;

    return 0;
}