#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LuckyBag(vector<int>& bag, int n, int index = 0, int sum = 0, int multi = 1){
    int count = 0;
    
    while(index < n){
        //当前sum和multi
        sum += bag[index];
        multi *= bag[index];
        
        //满足条件，往下走
        if(sum > multi){
            count += 1 + LuckyBag(bag, n, index + 1, sum, multi);
        }
        //不满足条件，但当前为1，往下走可能会满足条件
        else if(bag[index] == 1){
            count += LuckyBag(bag, n, index + 1, sum, multi);
        }
        else{
            break;
        }
        
        //恢复sum和multi
        sum -= bag[index];
        multi /= bag[index];
        
        //避免重复数字
        while(index + 1 < n && bag[index] == bag[index + 1]){
            index++;
        }
        
        index++;
    }
    
    return count;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> bag(n, 0);
        for(int i = 0; i< n; i++){
            cin >> bag[i];
        }
        
        sort(bag.begin(), bag.end());
        
        cout << LuckyBag(bag, n) << endl;
    }
    
    return 0;
}
