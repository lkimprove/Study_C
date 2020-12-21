//N个物品，V容量；
//produce[i][0]:价值；produce[i][1]:质量
//求最大价值

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, V;
    while(cin >> N >> V){
        vector<vector<int>> produce(N, vector<int>(2, 0));
        for(int i = 0; i < N; i++){
            cin >> produce[i][0];
            cin >> produce[i][1];
        }
        
        int ret = 0;
        
        vector<vector<int>> dp(V + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= V; i ++){
            for(int j = 1; j <= N; j++){
                int curr = j - 1;
                //当前物品能装下
                if(produce[curr][1] <= i){
                    //判断装当前物品和不装当前物品哪个收益高
                    dp[i][j] = max(dp[i][j - 1], dp[i - produce[curr][1]][j - 1] + produce[curr][0]);
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                }
                
                if(dp[i][j] > ret){
                    ret = dp[i][j];
                }
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}


