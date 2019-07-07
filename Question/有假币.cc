#include <iostream>
using namespace std;

int FindFake(int x) {
    //特殊情况
    if(x == 1){
    return 0;
    }
    if(x <= 3){
        return 1;
    }
    //平均分成三堆称重的效率最高
    //大于3，则必有一次称重，则count从1开始
    int count = 1;
    while(x > 3){
        //每次都取最多的那一堆，满足最大这个条件
        if(x % 3 == 0) {
            x = x / 3;
        }
        else {
            x = x / 3 + 1;
        }
        count++;
    }
    return count;
}


int main(){
    int x;
    //输入
    while(cin >> x){
        //结束条件
        if(x == 0){
            break;
        }
        //输出
        cout << FindFake(x) << endl;
    }
    return 0;
}
