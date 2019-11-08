#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    //创建unordered_map
    unordered_map<int, int> map;
    int n, num = 0;
    while(cin >> n){
        //对应数字++
        map[n]++;
        num++;
    }
    
    for(auto& it : map){
        if(it.second >= (num / 2)){
            cout << it.first << endl;
        }
    }
    
    return 0;
}
