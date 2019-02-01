#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[20][20];

class CFish{
    public:
        int x;
        int y;
        int size;
        CFish(){}
        CFish(int _x, int _y, int _size){
            x = _x;
            y = _y;
            size = _size;
        }
        ~CFish(){
            
        }
};

class CShark: public CFish{
    public:
        int remain_exp;
        CShark(int _x, int _y, int _size, int _exp): CFish(_x, _y, _size){
            remain_exp = _exp;
        }
        void move(int _x, int _y){
            map[y][x] = 0;
            x = _x;
            y = _y;
            map[y][x] = 9;
        }
};

int main(){
    int N;
    
    vector<CFish*> v_fishs;
    CShark *baby_shark;

    cin >> N;

    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            int size;
            cin >> size;
            if ( size >= 1 && size <= 6){
                CFish *f = new CFish(j, i, size);
                v_fishs.push_back(f);
            } else if ( size == 9 ) {
                baby_shark = new CShark(j, i, 2, 2);
            }
            map[i][j] = size;
        }
    }

    int mx[4] = {-1, 1, 0, 0};
    int my[4] = {0, 0, -1, 1};
    int move = 0;
    while ( true ){
        CFish *close_fish = NULL;
        int closest_distance = 100;
        int closest_index = 0;

        queue<pair<int, int>> q;
        q.push(make_pair(baby_shark->x, baby_shark->y));
        
        int moved[20][20] = {0, };
        int move_num = 0;
        bool is_find = false;
        while ( !q.empty() ){
            int now_x = q.front().first;
            int now_y = q.front().second;

            if ( is_find && move_num < moved[now_y][now_x]) break;

            if ( map[now_y][now_x] != 0 && map[now_y][now_x] < baby_shark->size ) {
                move_num = moved[now_y][now_x];
                is_find = true;
            }

            for ( int i=0; i < 4; i++){
                int target_x = now_x + mx[i];
                int target_y = now_y + my[i];
                if ( target_x < 0 || target_x >= N || target_y < 0 || target_y >= N ) continue;
                if ( moved[target_y][target_x] > 0 ) continue;
                if ( map[target_y][target_x] > baby_shark->size) continue;

                q.push(make_pair(target_x, target_y));
                moved[target_y][target_x] = moved[now_y][now_x] + 1;
            }

            q.pop();
        }

        if ( move_num == 0 ) break;

        is_find = false;
        for ( int i=0; i < N; i++ ){
            for ( int j=0; j < N; j++ ){
                if ( moved[i][j] == move_num && map[i][j] != 0 && map[i][j] < baby_shark->size){
                    baby_shark->move(j, i);
                    move += moved[i][j];
                    baby_shark->remain_exp--;
                    if ( baby_shark->remain_exp == 0 ){
                        baby_shark->size++;
                        baby_shark->remain_exp = baby_shark->size;
                    }
                    is_find = true;
                    break;
                }
            }
            if ( is_find ) break;
        }
    }

    cout << move;

    return 0;
}