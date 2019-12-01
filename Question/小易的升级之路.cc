#include <iostream>
#include <vector>
using namespace std;

//公约数
int Gcd(int a, int b){
    while(a % b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    return b;
}

int main(){
    int n, a;
    //输入怪兽数量和小易的初始值
    while(cin >> n >> a){
        vector<int> monster(n, 0);
        //输入怪兽的防御
        for(int i = 0; i < n; i++){
            cin >> monster[i];
        }
        
        //遍历怪物
        for(int i = 0; i < monster.size(); i++){
            if(a >= monster[i]){
                a += monster[i];
            }
            else {
                a += Gcd(a, monster[i]);
            }
        }
        
        //输出
        cout << a << endl;
    }
    return 0;
}
