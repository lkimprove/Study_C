#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s;
    //输入
    while(getline(cin, s)){
        string ret;
        
        //遍历字符串
        for(int i = 0; i < s.size(); i++){
            string tmp;
            //获取连续的数字字符串
            while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                tmp += s[i];
                i++;
            }
            
            //判断当前字符串是否最长
            if(ret.size() < tmp.size()){
                swap(ret, tmp);
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}


//动态规划
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string str;
    while(getline(cin, str)){
        int flag = 0, size = 0;
        
        vector<int> dp(str.size() + 1, 0);
        for(int i = 1; i <= str.size(); i++){
            if(str[i - 1] >= '0' && str[i - 1] <= '9'){
                dp[i] = dp[i - 1] + 1;
                
                if(dp[i] > size){
                    size = dp[i];
                    flag = i - size;
                }
            }
        }
        
        string ret;
        for(int i = 0; i < size; i++){
            ret.push_back(str[flag++]);
        }
        
        cout << ret << endl;
    }
    
    return 0;
}

