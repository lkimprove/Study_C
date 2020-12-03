//递归
#include <iostream>
using namespace std;

int Path(int n, int m){
    if(n == 1 || m == 1){
        return n + m;
    }
    
    return Path(n - 1, m) + Path(n, m - 1);
}

int main(){
    int n, m;
    while(cin >> n >> m){
        cout << Path(n, m) << endl;
    }
    
    return 0;
}


//动态规划
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j - 1];
                }
                else if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        cout << dp[n][m] << endl;
    }
    
    return 0;
}


