#include <iostream>
#include <string>
using namespace std;

bool Match(string& str1, string& str2, int i = 0, int j = 0){
    if(str1[i] == '\0' && str2[j] == '\0'){
        return true;
    }
    else if(str1[i] == '\0' || str2[j] == '\0'){
        return false;
    }
    else if(str1[i] == str2[j] || str1[i] == '?'){
        return Match(str1, str2, i + 1, j + 1);
    }
    else if(str1[i] == '*'){
        return Match(str1, str2, i + 1, j) || Match(str1, str2, i + 1, j + 1) || Match(str1, str2, i, j + 1);
    }
    
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
