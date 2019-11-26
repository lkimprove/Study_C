#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        //逆置
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        //确定长的数字和短的数字
        string ret, str;
        int size = 0;
        if(s1.size() > s2.size()){
            ret = s1;
            size = s2.size();
            str = s2;
        }
        else{
            ret = s2;
            size = s1.size();
            str = s1;
        }
        
        int sign = 0;
        for(int i = 0; i < size; i++){
            int cur = (ret[i] - '0') + (str[i] - '0') + sign;
            if(cur >= 10){
                ret[i] = (cur % 10) + '0';
                sign = 1;
            }
            else{
                ret[i] = (cur + '0');
                sign = 0;
            }
        }
        
        //若一长一短数字，遍历完短的字符串后仍然存在进位
        if(sign){
            for(int i = size; i < ret.size(); i++){
                int cur = (ret[i] - '0') + sign;
                if(cur >= 10){
                    ret[i] = (cur % 10) + '0';
                    sign = 1;
                }
                else{
                    ret[i] = (cur + '0');
                    sign = 0;
                    break;
                }
            }
        }
        
        //若遍历完长的字符串后仍然存在进位
        if(sign){
            ret += '1';
        }
        
        reverse(ret.begin(), ret.end());
        
        cout << ret << endl;
    }
    
    return 0;
}
