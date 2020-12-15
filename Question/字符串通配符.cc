#include <iostream>
#include <string>
using namespace std;

bool Match(string& str1, string& str2, int i = 0, int j = 0){
    //同时走到末尾
    if(str1[i] == '\0' && str2[j] == '\0'){
        return true;
    }
    //str1/str2提前走到末尾
    else if(str1[i] == '\0' || str2[j] == '\0'){
        return false;
    }
    //当前位置字符相等/当前位置为'?',向前匹配一个字符
    else if(str1[i] == str2[j] || str1[i] == '?'){
        return Match(str1, str2, i + 1, j + 1);
    }
    //当前位置为'*'
    else if(str1[i] == '*'){
        //匹配0个字符/匹配1个字符/匹配若干个字符
        return Match(str1, str2, i + 1, j) || Match(str1, str2, i + 1, j + 1) || Match(str1, str2, i, j + 1);
    }
    
    //当前位置字符不想等
    return false;
}


int main(){
    string str1;
    while(getline(cin, str1)){
        string str2;
        getline(cin, str2);
        
        if(Match(str1, str2)){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
    
    return 0;
}
