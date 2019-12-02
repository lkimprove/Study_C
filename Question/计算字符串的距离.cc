#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ChangeString(string& s1, string& s2){
    int m = s1.size(), n = s2.size();
    
    //插入代价，删除代价，替换代价
    int ic = 1, dc = 1, rc = 1;
    //dp[x][y]表示s1的前x个字符要编辑成s2的前y个字符所需要付出的代价
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    
    for(int i = 1; i <= m; i++){
        //dp[m][0] s1编辑为空串的代价
        dp[i][0] = i * dc;
    }
    for(int i = 1; i <= n; i++){
        //dp[0][n] 空串编辑为s2的代价
        dp[0][i] = i * ic;
    }
    
    // dp[x - 1][y - 1]    dp[x - 1][y]
    // dp[x][y - 1]        dp[x][y]
    
    for(int x = 1; x <= m; x++){
        for(int y = 1; y <= n; y++){
            //已知dp[x - 1][y]的代价，求dp[x][y]
            //需要先将x --> x - 1，则多了一个删除的代价
            int one = dp[x - 1][y] + dc;
            //已知dp[x][y - 1]的代价，求dp[x][y]
            //已经获得y-1，要得到y，则需要多一个插入的代价
            int two = dp[x][y - 1] + ic;
            //若当前字符相等，则没有替换的代价，反之需要多一个替换的代价
            int three = dp[x - 1][y - 1];
            if(s1[x - 1] != s2[y - 1]){
                three += rc;
            }
            
            //取上述三种变换的最小变换
            dp[x][y] = min(one, min(two, three));
        }
    }
    
    return dp[m][n];
}

int main(){
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        cout << ChangeString(s1, s2) << endl;
    }
    
    return 0;
}

