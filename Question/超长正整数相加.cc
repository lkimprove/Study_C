#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        //使第一个字符串始终为长的字符串
        if(s1.size() < s2.size()){
            swap(s1, s2);
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        //进位标志
        int sign = 0;
        //遍历每一位
        for(int i = 0; i < s2.size(); i++){
            int cur = (s1[i] - '0') + (s2[i] - '0') + sign;
            if(cur >= 10){
                s1[i] = (cur % 10 + '0');
                sign = 1;
            }
            else{
                s1[i] = (cur + '0');
                sign = 0;
            }
        }
        
        //若遍历完s2仍存在进位
        if(sign){
            for(int i = s2.size(); i < s1.size(); i++){
                int cur = (s1[i] - '0') + sign;
                if(cur >= 10){
                    s1[i] = (cur % 10 + '0');
                    sign = 1;
                }
                else{
                    s1[i] = (cur + '0');
                    sign = 0;
                    break;
                }
            }
        }
        
        //遍历完s1仍存在进位
        if(sign){
            s1 += '1';
        }
        
        reverse(s1.begin(), s1.end());
        
        cout << s1 << endl;
    }
    
    return 0;
}


//修建版
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        string ret;
        //从最低位开始相加
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int sign = 0;
        
        while(i >= 0 || j >= 0){
            //遍历s1
            if(i >= 0){
                sign += (s1[i] - '0');
            }
            //遍历s2
            if(j >= 0){
                sign += (s2[j] - '0');
            }
            
            //获取本位结果
            ret += (sign % 10 + '0');
            //获取进位（0或1）
            sign /= 10;
            
            i--;
            j--;
        }
        
        //若两个字符串均遍历完后仍存在进位
        if(sign){
            ret += '1';
        }
        
        //逆置
        reverse(ret.begin(), ret.end());
        
        cout << ret << endl;
    }
    
    return 0;
}








