#include <iostream>
#include <vector>
using namespace std;
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

int main(){
    int N;
    int map[20][20];
    vector<CFish*> v_fishs;
    CFish *baby_shark;

    cin >> N;

    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            int size;
            cin >> size;
            if ( size >= 1 && size <= 6){
                CFish *f = new CFish(j, i, size);
                v_fishs.push_back(f);
            } else if ( size == 9 ) {
                baby_shark = new CFish(j, i, 2);
            }
            map[i][j] = size;
        }
    }

    
    int move = 0;
    int remain_exp = 2;
    while ( !v_fishs.empty() ){
        CFish *close_fish = NULL;
        int closest_distance = 100;
        int closest_index = 0;

        for ( int i=0; i < v_fishs.size(); i++){
            int dx = v_fishs[i]->x - baby_shark->x;
            int dy = v_fishs[i]->y - baby_shark->y;
            if ( dx < 0 ) dx = -dx;
            if ( dy < 0 ) dy = -dy;

            if ( closest_distance > dx + dy ){
                CFish *temp = v_fishs[i];
                if ( temp->size >= baby_shark->size) continue;
                close_fish = temp;
                closest_distance = dx + dy;
                closest_index = i;
            } else if ( closest_distance == dx + dy ){
                if ( close_fish->y < v_fishs[i]->y ) continue;
                if ( close_fish->x < v_fishs[i]->x ) continue;
                if ( v_fishs[i]->size >= baby_shark->size) continue;
                close_fish = v_fishs[i];
                closest_index = i;
            }
        }

        if ( close_fish ){
            remain_exp--;
            if ( remain_exp == 0) {
                baby_shark->size++;
                remain_exp = baby_shark->size;
            }
            cout << close_fish->size << "is dead." << close_fish->x << ", " << close_fish->y << "i'm "<< baby_shark->size << endl;
           
            move += closest_distance;
            baby_shark->x = close_fish->x;
            baby_shark->y = close_fish->y;
            v_fishs.erase(v_fishs.begin() + closest_index);
            delete close_fish;
            
        } else {
            break;
        }
        close_fish == NULL;
    }

    cout << move << endl;

    return 0;
}