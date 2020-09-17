// write your code here cpp
//子串：顺序取出，且连续
//子序列：顺序取出，可不连续

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



//需要输出最长子序列
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i  -1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int maxlen = dp[n][m];
        if(maxlen == 0){
            return "-1";
        }
        
        string ret;
        int i = 1, j = 1;
        while(maxlen > 0 && i <= n && j <= m){
            if(dp[i - 1][j] == dp[i][j]){
                i++;
            }
            else if(dp[i][j - 1] == dp[i][j]){
                j++;
            }
            else{
                ret.push_back(s1[i - 1]);
                i++;
                j++;
                maxlen--;
            }
        }
        return ret;
    }
};
