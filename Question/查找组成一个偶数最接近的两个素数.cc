#include <iostream>
#include <algorithm>
using namespace std;

//判断一个数是否为素数
bool IsPrimeNumber(int x){
    //只需查到sqrt(x)即可
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    
    return true;
}


int main(){
    int n;
    while(cin >> n){
        //从中间位置开始寻找，遇到的第一对素数即为结果
        for(int i = n / 2; i > 0; i--){
            if(IsPrimeNumber(i) && IsPrimeNumber(n - i)){
                cout << i << endl;
                cout << n - i << endl;
                break;
            }
        }
    }
    
    return 0;
}
