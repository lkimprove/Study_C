#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string PublicString(string& s1, string& s2){
	//让s1为短的字符串
	if (s1.size() > s2.size()){
		swap(s1, s2);
	}
	//计算长度，记录字符串位置
	int count = 0;
	int sign = 0;
	//开始遍历
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			//如果有字符相等，则开始计算
			if (s1[i] == s2[j]){
				//该字符串的长度
				int cur = 0;
				//记录此时的位置，不破坏外部循环
				int a = i;
				int b = j;
				while (s1[a] == s2[b] && a < s1.size() && b < s2.size()){
					cur++;
					a++;
					b++;
				}
				//判断该字符串的长度
				if (cur > count){
					count = cur;
					sign = i;
				}
				if (cur == count && sign > i){
					sign = i;
				}
			}
		}
	}
	string ret;
	ret.resize(count);
	int i = 0;
	while (count--){
		ret[i++] = s1[sign++];
	}
	return ret;
}

int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		string ret = PublicString(s1, s2);
		cout << ret << endl;
	}
	return 0;
}




//dp思想
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int s1 = str1.size(), s2 = str2.size();
        int maxlen = 0, sign = 0;
        
        //dp[i][j]:
        //    1.dp[i - 1] + dp[j - 1]; str1[i] == str2[j]
        //    2.0;    str1[i] != str2[j]
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    if(maxlen < dp[i][j]){
                        maxlen = dp[i][j];
                        sign = i - maxlen;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        if(maxlen == 0){
            return "-1";
        }
        string ret;
        for(int i = 0; i < maxlen; i++){
            ret.push_back(str1[sign++]);
        }
        return ret;
        
    }
};
