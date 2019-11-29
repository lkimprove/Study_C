#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ret = 0;
        for(int i = 2; i <= n; i++){
            int sum = 1;
            
            //求约数
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    sum += j;
                    if(j != sqrt(i)){
                        sum += (i / j);
                    }
                }
            }
            
            if(sum == i){
                ret++;
            }
        }
        cout << ret << endl;
        
    }
    
    return 0;
}
