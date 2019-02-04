#include <iostream>
#include <vector>
using namespace std;
class CTree{
    public:
        int x;
        int y;
        int age;
        CTree(){

        }
        CTree(int _x, int _y, int _age){
            x = _x;
            y = _y;
            age = _age;
        }
        ~CTree(){

        }
};
int N;

int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[8] = { 1, -1, 1, 0, -1, 1, 0, -1 };
int main(){
    int M;
    int K;
    int map[10][10];
    int A[10][10];
    vector<CTree> trees[10][10];
    vector<CTree> dead;

    cin >> N >> M >> K;

    // init map
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            map[i][j] = 5;
            cin >> A[i][j];
        }
    }

    for ( int i = 0; i < M; i++ ){
        int x;
        int y;
        int age;
        cin >> x >> y >> age;
        
        x--;
        y--;
        CTree tree = CTree(x , y, age);
        trees[y][x].push_back(tree);
    }

    for ( int year = 0; year < K; year++ ){
        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                if ( trees[i][j].empty() ) continue;

                
                for ( int k = trees[i][j].size()-1; k >= 0; k-- ){
                    if ( map[i][j] >= trees[i][j][k].age ){
                        map[i][j] -= trees[i][j][k].age;
                        trees[i][j][k].age++;
                        cout << j << ", " << i << " is alive." << "(" << trees[i][j].size() << ")" << map[i][j] << endl;
                    } else {
                        while ( k >= 0 ){
                            dead.push_back(trees[i][j][k]);
                            trees[i][j].erase(trees[i][j].begin() + k);
                            k--;
                            cout << j << ", " << i << " is dead." << "(" << trees[i][j].size() << ")" << map[i][j] << endl; 
                        }
                    }
                }
            }
        }

        while ( !dead.empty() ){
            CTree tree = dead.back();
            int x = tree.x;
            int y = tree.y;
            int age = tree.age;

            map[y][x] += (int) (age/2);

            dead.pop_back();
        }

        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                if ( trees[i][j].empty() ) continue;

                for ( int k = 0; k < trees[i][j].size(); k++ ){
                    if ( trees[i][j][k].age % 5 == 0){
                        int nowX = trees[i][j][k].x;
                        int nowY = trees[i][j][k].y;
                        
                        for ( int a = 0; a < 8; a++ ){
                            int targetX = nowX + dx[a];
                            int targetY = nowY + dy[a];
                            if ( targetX < 0 || targetX >= N || targetY < 0 || targetY >= N ) continue;

                           
                            CTree tree = CTree(targetX, targetY, 1);

                            trees[targetY][targetX].push_back(tree);

                            cout << targetX << ", " << targetY << " is born." << "(" << trees[targetY][targetX].size() << ")" << map[targetY][targetX] << endl;
                        }
                    }
                }
            }
        }

        for ( int i = 0; i < N; i++ ){
            for ( int j = 0; j < N; j++ ){
                map[i][j] += A[i][j];
            }
        }

        cout << "next year." << endl;
    }

    int ans = 0;
    for ( int i = 0; i < N; i++ ){
        for ( int j = 0; j < N; j++ ){
            ans += trees[i][j].size();
        }
    }

    cout << ans;
        
    return 0;
}