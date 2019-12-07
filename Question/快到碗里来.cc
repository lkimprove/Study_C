#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//大数相乘
void StringOperator(string& s){
    reverse(s.begin(), s.end());
    
    int sign = 0;
    for(int i = 0; i < s.size(); i++){
        int cur = (s[i] - '0') * 2 * 314 + sign;
        
        s[i] = (cur % 10 + '0');
        sign = cur / 10;
    }
    
    while(sign){
        s += (sign % 10 + '0');
        sign /= 10;
    }
    
    reverse(s.begin(), s.end());
}

bool Cat(string& n, string& r){
    //n * 100 与 r * 314 * 2 进行比较
    n += "00";
    
    StringOperator(r);
    
    if(n.size() > r.size()){
        return false;
    }
    else if(n.size() < r.size()){
        return true;
    }
    
    for(int i = 0; i < n.size(); i++){
        if(n[i] < r[i]){
            return true;
        }
        else if(n[i] > r[i]){
            return false;
        }
    }
    
    return true;
}


int main(){
    string n, r;
    while(cin >> n >> r){
        bool ret = Cat(n, r);
        
        if(ret){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    
    return 0;
}
