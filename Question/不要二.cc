#include <iostream>
#include <vector>
using namespace std;

static int Point[4][2] = {{0, 2}, {0, -2}, {2, 0}, {-2, 0}};

void Box(vector<vector<int>>& vv, int H, int M, int x, int y){
    //判断该位置是否有蛋糕
    //若有蛋糕，将与其欧几里得距离为2的位置的蛋糕拿走
    if(vv[x][y] != 1){
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int newx = x + Point[i][0];
        int newy = y + Point[i][1];
        
        //防越界
        if(newx >= 0 && newy >= 0 && newx < H && newy < M){
            if(vv[newx][newy] == 1){
                vv[newx][newy] = 0;
            }
        }
    }
}


int main(){
    int M, H;
    while(cin >> M >> H){
        vector<vector<int>> vv(H, vector<int>(M, 1));
        
        
        for(int i = 0; i < H; i++){
            for(int j = 0; j < M; j++){
                Box(vv, H, M, i, j);
            }
        }
        
        //判断蛋糕个数
        int ret = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < M; j++){
                if(vv[i][j] == 1){
                    ret++;
                }
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}

//优化
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int W, H;
    while(cin >> W >> H){
        //将每个位置都放上蛋糕
        vector<vector<int>> box(H, vector<int>(W, 1));
        
        int ret = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(box[i][j] == 1){
                    ret++;
                    
                    //将不符合题意的蛋糕去掉
                    if(i + 2 < H){
                        box[i + 2][j] = 0;
                    }
                    if(j + 2 < W){
                        box[i][j + 2] = 0;
                    }
                }
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
