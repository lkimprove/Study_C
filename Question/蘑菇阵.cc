#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int N, M, k;
    while(cin >> N >> M >> k){
        vector<vector<double>> path(N + 1, vector<double>(M + 1, 0));
        //起点概率为1
        path[1][1] = 1.0;
        
        //0代表没有蘑菇，1代表有蘑菇
        vector<vector<int>> map(N + 1,vector<int>(M + 1, 0));
        int x, y;
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            map[x][y] = 1;
        }
        
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                //跳过起点
                if(i == 1 && j == 1){
                    continue;
                }
                
                //i+1 横着走，j+1竖着走
                //每个位置的概率均可从他前面的两个位置的概率推导出来
                path[i][j] = path[i - 1][j] * (j == M ? 1 : 0.5) 
                    + path[i][j - 1] * (i == N ? 1 : 0.5);
                
                //碰到蘑菇，概率为0
                if(map[i][j]){
                    path[i][j] = 0;
                }
                
            }
        }
        
        //setprecision和fixed合用的话，可以控制小数点后面有几位
        cout << fixed <<  setprecision(2) << path[N][M] << endl;
        
    }
    
    
    return 0;
}
