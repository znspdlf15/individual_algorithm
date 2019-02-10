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

   return 0;
}
