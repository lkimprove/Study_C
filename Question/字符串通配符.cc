#include <iostream>
#include <string>
using namespace std;

bool MatchString(string& s1, string& s2, int i, int j){
    //同时到结尾，表示已经匹配完
    if(s1[i] == '\0' && s2[j] == '\0'){
        return true;
    }
    
    //只有一个到结尾，匹配出错
    if(s1[i] == '\0' || s2[j] == '\0'){
        return false;
    }
    
    if(s1[i] == s2[j]){
        return MatchString(s1, s2, i + 1, j + 1);
    }
    //匹配一个字符
    else if(s1[i] == '?'){
        //若对应字符合法，则跳过
        if((s2[j] >= 'a' && s2[j] <= 'z') || (s2[j] >= 'A' && s2[j] <= 'Z') || (s2[j] >= '0' && s2[j] <= '9')){
            return MatchString(s1, s2, i + 1, j + 1);
        }
        else{
            return false;
        }
    }
    //匹配0个 || 匹配1个 || 匹配多个
    else if(s1[i] == '*'){
        if((s2[j] >= 'a' && s2[j] <= 'z') || (s2[j] >= 'A' && s2[j] <= 'Z') || (s2[j] >= '0' && s2[j] <= '9')){
            return MatchString(s1, s2, i + 1, j) || MatchString(s1, s2, i + 1, j + 1) || MatchString(s1, s2, i, j + 1);
        }
        else{
            return MatchString(s1, s2, i + 1, j);
        }
    }
    
    return false;
}


int main(){
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        bool ret = MatchString(s1, s2, 0, 0);
        if(ret){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
    
    return 0;
}
