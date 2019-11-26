#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ret = 0;
        for(int i = 1; i <= n; i++){
            int sum = 0;
            //遍历约数
            for(int j = 1; j < i; j++){
                if(i % j == 0){
                    sum += j;
                }
            }
            
            //判断是否为完全数
            if(sum == i){
                ret++;
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
