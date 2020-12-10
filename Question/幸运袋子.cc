#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LuckyBag(vector<int>& array, int n, int sum, int multi, int index){
    int count = 0;
    for(int i = index; i < n; i++){
        sum += array[i];
        multi *= array[i];
        
        
        if(sum > multi){
            //当前满足条件，再增加一个数判断是否继续满足条件
            count += (1 + LuckyBag(array, n, sum, multi, i + 1));
        }
        else if(array[i] == 1){
            //不满足条件，但当前数为1，再增加一个数有可能满足条件
            count += LuckyBag(array, n, sum,  multi, i + 1);
        }
        else{
            //不满足条件，且当前数不为1，在增加数也无法满足条件
            break;
        }
        
        //不计算当前数，寻找更多的可能性
        sum -= array[i];
        multi /= array[i];
        
        //相同的数只能计算一次
        while(i + 1 < n && array[i] == array[i + 1]){
            i++;
        }
    }
    
    return count;
}


int main(){
    int n;
    while(cin >> n){
        vector<int> array(n, 0);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        
        sort(array.begin(), array.end());
        
        cout << LuckyBag(array, n, 0, 1, 0) << endl;
    }
    
    return 0;
}
