#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int k;
    while(cin >> k){
        if(k == 0){
            break;
        }
        
        vector<int> array(k, 0);
        for(int i = 0; i < k; i++){
            cin >> array[i];
        }
        
        vector<int> dp(k, 0);
        dp[0] = array[0];
        int ret = array[0], first = 0, second = 0, sign = 0;
        
        for(int i = 1; i < k; i++){
            dp[i] = max(dp[i - 1] + array[i], array[i]);
            if(ret < dp[i]){
                ret = dp[i];
                second = array[i];
                sign = i;
            }
        }
        
        for(int i = sign; i >= 0; i--){
            if(array[i] == dp[i]){
                first = array[i];
                break;
            }
        }
        cout << ret << " " << first << " " << second << endl;
    }
    
    return 0;
}
