#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n <= 2){
            cout << -1 << endl;
        }
        
        vector<vector<int>> vv(n + 1);
        for(int i = 1; i < n + 1; i++){
            int cur = 2 * i - 1;
            vv[i].resize(cur);
            vv[i][0] = vv[i][cur - 1] = 1;
        }
        vv[2][1] = 1;
        
        for(int i = 3; i <= n; i++){
            int cur = 2 * i - 1;
            //左半部分
            for(int j = 1; j <= cur / 2; j++){
                vv[i][j] += vv[i - 1][j];
                if(j - 1 >= 0){
                    vv[i][j] += vv[i - 1][j - 1];
                }
                if(j - 2 >= 0){
                    vv[i][j] += vv[i - 1][j - 2];
                }
            }
            
            //右半部分
            int tmp = cur / 2 - 1;
            for(int j = cur / 2 + 1; j < cur - 1; j++){
                vv[i][j] = vv[i][tmp];
                tmp--;
            }
        }
        
        int i;
        for(i = 0; i < 2 * n - 1; i++){
            if(vv[n][i] % 2 == 0){
                cout << i + 1 << endl;
                break;
            }
        }
        
        if(i == 2 * n - 1){
            cout << -1 << endl;
        }
    }
    
    return 0;
}


//花费更多的空间，但使算法更加精简
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<vector<int>> vv(n, vector<int>(2 * n - 1, 0));
        vv[0][0] = 1;
        for(int i = 1; i < n; i++){
            vv[i][0] = vv[i][2 * i] = 1;
            for(int j = 1; j < 2 * i; j++){
                //如果为第一列，只需加两个值
                if(j == 1){
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
                }
                //不为第一列，需要加三个值
                else{
                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j - 2];
                }
            }
        }
        
        int i = 1;
        for(; i < 2 * n; i++){
            if(vv[n - 1][i] % 2 == 0){
                cout << i + 1 << endl;
                break;
            }
        }
        
        if(i == 2 * n){
            cout << -1 << endl;
        }
    }
    
    return 0;
}
