#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//这个题目的关键在于想清楚先对所有队员排序，
//再取后面的2n个数，每次取相邻的两个数，取小的那个，即第一个数
//这些数相加就可以保证最后的结果最大
//证明：如果保证每个组的中值尽可能大，拿结果就肯定是最大的
//先将最小的n个数舍弃，作为每个组的最小值
//从拥有最大值的那个组考虑，那个组的最大值为所有队员水平值的最大值
//中值要保证最大，则这个组的中值只能取所有队员水平值的第二大值
//根据合理类推，就可得出要想保证每个组的中值最大
//要取后面2n个数中（从下标为n开始），相邻两个数中较小的那个数

int main(){
    int n;
    while(cin >> n){
        //结果
        long long ret = 0;
        //创建一个数组储存队员的水平值
        vector<long long> v;
        int sum = n * 3;
        v.resize(sum);
        //输入
        for(int i = 0; i <  3 * n; i++){
            cin >> v[i];
        }
        //排序
        sort(v.begin(), v.end());
        //从第 （n- 1） 开始拿数字
        //每次跳过一个数
        for(int i = n; i < 3 * n; i += 2){
            ret += v[i];
        }
        cout << ret << endl;
    }
    return 0;
}
