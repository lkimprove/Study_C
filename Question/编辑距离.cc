class Solution {
public:
    /**
     * 
     * @param word1 string字符串 
     * @param word2 string字符串 
     * @return int整型
     */
    int minDistance(string word1, string word2) {
        // write code here
        int s1 = word1.size(), s2 = word2.size();
        
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        //初始化
        for(int i = 1; i <= s1; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= s2; j++){
            dp[0][j] = j;
        }
        
        //增删可看作同一种操作，dp[i - 1][j]和du[i][j - 1]到dp[i][j]均只需要一步操作
        //替换是需要判断word1的i- 1与word2的j - 1是否一致,若一致不需要操作，不一致则需要一步操作
        //dp则为上述两个操作中的较小值
        
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                int cur1 = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                
                int cur2 = 0;
                if(word1[i - 1] == word2[j - 1]){
                    cur2 = dp[i - 1][j - 1];
                }
                else{
                    cur2 = dp[i - 1][j - 1] + 1;
                }
                
                dp[i][j] = min(cur1, cur2);
            }
        }
        
        return dp[s1][s2];
        
    }
};
