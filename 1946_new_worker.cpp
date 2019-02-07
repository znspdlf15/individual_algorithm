#include <iostream>
#include <stdio.h>
using namespace std;
const int MAX = 100000;

int applicant[MAX][2];

int main(){
    int T;
    int N;
    int ans[20];
    cin >> T;

    for ( int t = 0; t < T; t++ ){
        cin >> N;
        for ( int n = 0; n < N; n++ ){
            scanf("%d%d", &applicant[n][0], &applicant[n][1]);
        }

        int case_ans = N;
        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                if ( applicant[i][0] > applicant[j][0] && applicant[i][1] > applicant[j][1] ){
                    case_ans--;
                    break;
                }
            }
        }
        ans[t] = case_ans;
    }

    for ( int t = 0; t < T; t++ ){
        cout << ans[t] << endl;
    }
}
