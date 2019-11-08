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
