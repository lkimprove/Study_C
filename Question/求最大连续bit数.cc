//动态规划
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> dp(33, 0);
        
        int ret = 0;
        for(int i = 1; i <= 32; i++){
            if(n &(1 << (i - 1))){
                dp[i] = dp[i - 1] + 1;
                
                if(ret < dp[i]){
                    ret = dp[i];
                }
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}


//遍历
#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ret = 0, temp = 0;
        while(n){
            if(n & 1){
                temp++;
                ret = max(ret, temp);
            }
            else{
                temp = 0;
            }
            
            n >>= 1;
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
