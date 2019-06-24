#include <iostream>
#include <algorithm>
using namespace std;

void Reverse(string& s){
    //设置起点和终点
    int begin = 0;
    int end = s.size() - 1;
    //交换
    while(begin < end){
        swap(s[begin], s[end]);
        begin++;
        end--;
    }
}

int main(){
    string s;
    //输入
    while(cin >> s){
        //逆置
        Reverse(s);
        //输出
        cout << s << endl;
    }
    return 0;
}
