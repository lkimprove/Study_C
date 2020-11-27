#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> array(n, 0);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        
        vector<int> dp(n + 1, 0);
        int ret = array[1];
        for(int i = 1; i <= n; i++){
            dp[i] = max(array[i - 1], dp[i - 1] + array[i - 1]);
            
            if(ret < dp[i]){
                ret = dp[i];
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
