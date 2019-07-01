#include <iostream>
using namespace std;

int main(){
    //创建一个斐波那契数列
    //初始化这个数列，超过四位数，只保留后四位
    int Fib[10001];
    Fib[0] = 1;
    Fib[1] = 1;
    for(int i = 2; i < 10001; i++){
        Fib[i] = (Fib[i -1] % 10000 + Fib[i - 2] % 10000) %10000;
    }
    //数据组数
    int n;
    while(cin >> n){
        while(n--){
            //输入
            int x;
            cin >> x;
            //输出
            printf("%04d", Fib[x]);
        }
        cout << endl;
    }
    return 0;
}
