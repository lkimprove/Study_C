#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    //输入数据组数
    cin >> T;
    while(T--){
        //输入牌数和洗牌次数
        int n, k;
        cin >> n >> k;
        //牌
        int sum = 2 * n;
        vector<int> table(sum);
        for(int i = 0; i <sum; i++){
            cin >> table[i];
        }
        
        //洗牌
        //1.寻找规律法
        while(k--){
            vector<int> cur(table.begin(), table.end());
            for(int i = 0; i < n; i++){
                //左手
                table[2 * i] = cur[i];
                //右手
                table[2 * i + 1] = cur[i + n]; 
            }
        }
        //2.暴力破解法
        while(k--){
            vector<int> cur(table.begin(), table.end());
            int j = 2 * n - 1;
            for(int i = n - 1; i >= 0; i--){
                //右手n - (2n - 1)
                //(0 - (n - 1)) + n
                table[j--] = cur[i + n];
                //左手0 - (n-1)
                table[j--] = cur[i];
            }
        }
        
        //输出结果
        for(int i = 0; i < sum - 1; i++){
            cout << table[i] << " ";
        }
        cout << table[sum - 1] << endl;
    }
    return 0;
}
