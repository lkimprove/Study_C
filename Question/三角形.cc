#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//大数相加
string AddString(string& x, string& y){
    string ret;
    int i = x.size() - 1;
    int j = y.size() - 1;
    
    int sign = 0;
    while(i >= 0 || j >= 0){
        if(i >= 0){
            sign += (x[i] - '0');
        }
        if(j >= 0){
            sign += (y[j] - '0');
        }
        
        ret += (sign % 10 + '0');
        sign /= 10;
        i--;
        j--;
    }
    
    if(sign){
        ret += '1';
    }
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}

//大数比较
bool Compare(string& x, string& y){
    if(x.size() > y.size()){
        return true;
    }
    else if(x.size() < y.size()){
        return false;
    }
    
    for(int i = 0; i < x.size(); i++){
        if(x[i] > y[i]){
            return true;
        }
        else if(x[i] < y[i]){
            return false;
        }
    }
    
    return false;
}

//三角形判断
//任意两条边大于第三条边
bool Triangle(string& a, string& b, string& c){
    string sum1 = AddString(a, b);
    string sum2 = AddString(a, c);
    string sum3 = AddString(b, c);
    
    if(Compare(sum1, c) && Compare(sum2, b) && Compare(sum3, a)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string a, b, c;
    while(cin >> a >> b >> c){
        bool ret = Triangle(a, b, c);
        
        if(ret){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        
    }
    
    return 0;
}
