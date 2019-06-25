#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string PublicString(string& s1, string& s2){
    //两个字符串的长度
    int len1 = s1.size();
    int len2 = s2.size();
    //创建一个二维结果数组
    vector<vector<int>> vv;
    vv.resize(len1 + 1);
    for(int i = 0; i < len1 + 1; i++){
        vv[i].resize(len2 + 1, 0);
    }
    //记录最长字符串的长度和起始位置
    int max = 0;
    int start = 0;
    //遍历字符串
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            //如果有相等的字符，则更新结果数组
            if(s1[i - 1] == s2[j - 1]){
                vv[i][j] = vv[i - 1][j - 1] + 1;
            }
            //比较最大字符串和此公共字符串的长度
            if(max < vv[i][j]){
                max = vv[i][j];
                start = i - max;
            }
        }
    }
    //结果字符串
    string ret;
    ret = s1.substr(start, max);
    return ret;
}

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        string ret;
        //保证s1为短的字符串
        if(s1.size() > s2.size()){
            swap(s1, s2);
        }
        ret = PublicString(s1, s2);
        cout << ret << endl;
    }
    return 0;
}
