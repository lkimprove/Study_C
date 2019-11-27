#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LuckyPacket(vector<int>& v, int size, int index, int sum, int product){
    int ret = 0;
    for(int i = index; i < size; i++){
        //计算取当前数后的和与积
        sum += v[i];
        product *= v[i];
        
        //满足条件
        if(sum > product){
            ret += (1 + LuckyPacket(v, size, i + 1, sum, product));
        }
        //1 + 1 > 1 * 1
        else if(v[i] == 1){
            ret += LuckyPacket(v, size, i + 1, sum, product);
        }
        //再去取值也不可能满足条件
        else{
            break;
        }
        
        //回复当前的和与积
        sum -= v[i];
        product /= v[i];
        
        //相同号码的球不用取两遍，只能算一种组合
        while(i < size - 1 && v[i] == v[i + 1]){
            i++;
        }
    }
    
    return ret;
}



int main(){
    int n;
    while(cin >> n){
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        
        cout << LuckyPacket(v, n, 0, 0, 1) << endl;
    }
    
    return 0;
}
