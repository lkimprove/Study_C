#include <iostream>
using namespace std;

int main(){
    //斐波那契的前两个数
    int f0 = 0;
    int f1 = 1;
    
    int n;
    while(cin >> n){
        //获取邻近的两个斐波那契数
        while(f1 < n){
            int f = f0 + f1;
            f0 = f1;
            f1 = f;
        }
        
        // f0 < n < f1
        int ret1 = f1 - n;
        int ret2 = n - f0;
        if(ret1 < ret2){
            cout << ret1 << endl;
        }
        else{
            cout << ret2 << endl;
        }
        
    }
    
    
    return 0;
}
