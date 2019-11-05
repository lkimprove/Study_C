// write your code here cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        //储存要创建的路径
        vector<string> list(n);
        //每个路径的标志
        vector<bool> sign(n, true);
        //输入
        for(int i = 0; i < n; i++){
            cin >> list[i];
        }
        //排序，将相似的路径放在一起
        sort(list.begin(), list.end());
        
        for(int i = 0; i < n - 1; i++){
            //如果当前路径与其后路径相等
            if(list[i] == list[i + 1]){
                sign[i] = false;
            }
            //如果当前路径是其后路径的子串，且紧跟着为'/'
            else if(list[i].size() < list[i + 1].size() &&
                   list[i] == list[i + 1].substr(0, list[i].size()) &&
                   list[i + 1][list[i].size()] == '/'
                   ){
                sign[i] = false;
            }
        }
        
        //判断当前路径是否需要创建
        for(int i = 0; i < n; i++){
            if(sign[i]){
                cout << "mkdir -p " << list[i] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
