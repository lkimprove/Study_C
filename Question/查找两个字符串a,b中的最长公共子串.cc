#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str1;
    while(getline(cin, str1)){
        string str2;
        getline(cin, str2);
        if(str1.size() > str2.size()){
            swap(str1, str2);
        }
        
        
        vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
        
        int flag = 0, size = 0;
        for(int i = 1; i <= str1.size(); i++){
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                
                if(size < dp[i][j]){
                    size = dp[i][j];
                    flag = i - size;
                }
            }
        }
        
        string ret = str1.substr(flag, size);
        
        cout << ret << endl;
    }
    
    return 0;
}
