#include <iostream>
#include <string>
using namespace std;

//因为输入地数可能过于长，所以要用字符串接受
int NumRoot(string num){
    int cur = 0;
    for(auto it : num){
        cur += (it - '0');
    }
    num = to_string(cur);
    //若数字大于两位数，继续循环
    while(num.size() > 1){
        cur = 0;
        for(auto it : num){
            cur += (it - '0');
        }
        num = to_string(cur);
    }
    return cur;
}

int main(){
    string num;
    //输入
    while(cin >> num){
        ///输出
        cout << NumRoot(num) << endl;
    }
    return 0;
}
