// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int n = s1.size(), m = s2.size();
        
        //dp[i][j]:
        //    1.dp[i - 1][j - 1] + 1; s1[i - 1] == s2[j - 1]
        //    2.max(dp[i - 1][j], dp[i][j - 1]); otherwise
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        cout << dp[n][m] << endl;
    }
    
    
    return 0;
}
