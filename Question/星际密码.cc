#include <iostream>
#include <vector>
using namespace std;

int main(){
    //创建一个斐波那契数组
    vector<int> Fib(10001, 0);
    Fib[0] = 1;
    Fib[1] = 1;
    for(int i = 2; i < Fib.size(); i++){
        Fib[i] = (Fib[i - 1] % 10000 + Fib[i - 2] % 10000) % 10000;
    }
    //输入数据组数
    int n;
    while(cin >> n){
        while(n--){
            //输入数据
            int x;
            cin >> x;
            //输出
            printf("%04d", Fib[x]);
        }
        cout << endl;
    }
    return 0;
}
