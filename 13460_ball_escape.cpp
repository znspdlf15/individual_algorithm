#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M; // height, width
char org_map[10][10];
char copy_map[10][11];
int ans = 100;
int red[2];
int blue[2];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void move_ball(int x1, int y1, int x2, int y2){
    char c = copy_map[y1][x1];
    copy_map[y1][x1] = org_map[y1][x1];
    copy_map[y2][x2] = c;
    
}
void dfs(int count){
    if ( count == 11 ) return;

    for ( int d = 0; d < 4; d++ ){
        int redX = red[0];
        int redY = red[1];
        int blueX = blue[0];
        int blueY = blue[1];

        int t_redX = redX;
        int t_redY = redY;
        int t_blueX = blueX;
        int t_blueY = blueY;

        bool failed = false;

        int tmp_ans = 1000;
        for ( int i = 0; i < N || i < M; i++ ){
            t_redX = t_redX + dx[d];
            t_redY = t_redY + dy[d];
            t_blueX = t_blueX + dx[d];
            t_blueY = t_blueY + dy[d];

            if ( t_blueX >= 0 && t_blueX < M && t_blueY >= 0 && t_blueY < N ){
                char c = copy_map[t_blueY][t_blueX];
                if ( c == '#' ) {
                    t_blueX -= dx[d];
                    t_blueY -= dy[d];
                } else if ( t_blueX == t_redX && t_blueY == t_redY ){
                    t_blueX = t_blueX - dx[d];
                    t_blueY = t_blueY - dy[d];
                } else if ( c == 'O' ){
                    failed = true;
                    break;
                }
            }

            if ( t_redX >= 0 && t_redX < M && t_redY >= 0 && t_redY < N ){
                char c = copy_map[t_redY][t_redX];
                if ( c == '#' ) {
                    t_redX -= dx[d];
                    t_redY -= dy[d];
                } else if ( t_blueX == t_redX && t_blueY == t_redY ){
                    t_redX = t_redX - dx[d];
                    t_redY = t_redY - dy[d];
                } else if ( c == 'O' ){
                    tmp_ans = min(ans, count);
                }
            }
        }
        if ( failed ) {
            continue;
        } else {
            if ( tmp_ans != 1000 ){
                ans = tmp_ans;
            }
        }

        move_ball(redX, redY, t_redX, t_redY);
        move_ball(blueX, blueY, t_blueX, t_blueY);
        red[0] = t_redX;
        red[1] = t_redY;
        blue[0] = t_blueX;
        blue[1] = t_blueY;
        
        // for ( int n = 0; n < N; n++ ){
        //     for ( int m = 0; m < M; m++ ){
        //         cout << copy_map[n][m] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << red[0] << ", " << red[1] << endl;
        // cout << blue[0] << ", " << blue[1] << endl;
        // cout << endl;
        dfs(count+1);
        move_ball(t_redX, t_redY, redX, redY);
        move_ball(t_blueX, t_blueY, blueX, blueY);
        red[0] = redX;
        red[1] = redY;
        blue[0] = blueX;
        blue[1] = blueY;
    }

}
int main(){

    cin >> N >> M;

    for ( int n = 0; n < N; n++ ){
        scanf("%s", &copy_map[n]);
    }

    for ( int n = 0; n < N; n++ ){
        for ( int m = 0; m < M; m++ ){
            if ( copy_map[n][m] == 'B' ){
                org_map[n][m] = '.';
                blue[0] = m;
                blue[1] = n;
            } else if ( copy_map[n][m] == 'R' ){
                org_map[n][m] = '.';
                red[0] = m;
                red[1] = n;
            } else {
                org_map[n][m] = copy_map[n][m];
            }
        }
    }

    dfs(1);

    if ( ans == 100 ){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}