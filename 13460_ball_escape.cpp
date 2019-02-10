#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int N, M; // height, width
char org_map[10][10];
char copy_map[10][11];
int ans = 1000;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue< pair< pair<int, int>, int> > red_q;
queue< pair< pair<int, int>, int> > blue_q;

int redX;
int redY;
int blueY;
int blueX;
void bfs() {
  int count = 0;

   while ( !red_q.empty() && !blue_q.empty() && count < 10 ){
     redX = red_q.front().first.first;
     redY = red_q.front().first.second;
     blueX = blue_q.front().first.first;
     blueY = blue_q.front().first.second;
     count = red_q.front().second;

     red_q.pop();
     blue_q.pop();

     // cout << redX << ", " << redY << "   " << blueX << ", " << blueY << "is poped."<< endl;

     for ( int d = 0; d < 4; d++ ){
       int t_redX = redX, t_redY = redY;
       int t_blueX = blueX, t_blueY = blueY;
       bool goal = false;
       bool fail = false;
       for ( int i = 0; i < N || i < M; i++ ){
         if ( copy_map[t_redY + dy[d]][t_redX + dx[d]] == 'O' ){
           goal = true;
         }
         if ( copy_map[t_redY + dy[d]][t_redX + dx[d]] == '#' ) break;
         if ( t_redY + dy[d] == t_blueY && t_redX + dx[d] == t_blueX ) break;

         t_redX += dx[d];
         t_redY += dy[d];
       }

       for ( int i = 0; i < N || i < M; i++ ){
         if ( copy_map[t_blueY + dy[d]][t_blueX + dx[d]] == 'O' ){
           fail = true;
           break;
         }
         if ( copy_map[t_blueY + dy[d]][t_blueX + dx[d]] == '#' ) break;
         if ( t_blueY + dy[d] == t_redY && t_blueX + dx[d] == t_redX ) break;

         t_blueX += dx[d];
         t_blueY += dy[d];
       }

       for ( int i = 0; i < N || i < M; i++ ){
         if ( copy_map[t_redY + dy[d]][t_redX + dx[d]] == 'O' ){
           goal = true;
         }
         if ( copy_map[t_redY + dy[d]][t_redX + dx[d]] == '#' ) break;
         if ( t_redY + dy[d] == t_blueY && t_redX + dx[d] == t_blueX ) break;

         t_redX += dx[d];
         t_redY += dy[d];
       }

       if ( fail ) continue;
       // cout << t_redX << ", " << t_redY << "   " << t_blueX << ", " << t_blueY << "   " << count <<"is pushed."<< endl;
       if ( goal && !fail ){
         ans = count+1;
         return;
       }

       copy_map[redY][redX] = '.';
       copy_map[blueY][blueX] = '.';
       copy_map[t_redY][t_redX] = 'R';
       copy_map[t_blueY][t_blueX] = 'B';

       if ( redX == t_redX && redY == t_redY && blueX == t_blueX && blueY == t_blueY ) continue;
       red_q.push(make_pair(make_pair(t_redX, t_redY), count+1));
       blue_q.push(make_pair(make_pair(t_blueX, t_blueY), count+1));
     }
   }
}
<<<<<<< HEAD
int main() {

   cin >> N >> M;

   for (int n = 0; n < N; n++) {
      scanf("%s", copy_map[n]);
   }

   for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
         if (copy_map[n][m] == 'B') {
            org_map[n][m] = '.';
            blueX = m;
            blueY = n;
         }else if (copy_map[n][m] == 'R') {
            org_map[n][m] = '.';
            redX = m;
            redY = n;
         }
         else {
            org_map[n][m] = copy_map[n][m];
         }
      }
   }


   red_q.push(make_pair(make_pair(redX, redY), 0));
   blue_q.push(make_pair(make_pair(blueX, blueY), 0));

   bfs();

   if ( ans == 1000 ){
     cout << -1 << endl;
   } else {
     cout << ans << endl;
   }
=======
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
>>>>>>> f853fca647f5e5149b39c6d0c8bc6a42b7adff03

   return 0;
}
<<<<<<< HEAD
=======
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
>>>>>>> f853fca647f5e5149b39c6d0c8bc6a42b7adff03
