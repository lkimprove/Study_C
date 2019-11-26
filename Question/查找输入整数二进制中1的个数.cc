#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ret = 0;
        while(n){
            if((n & 1) == 1){
                ret++;
            }
            
            //右移
            n = n >> 1;
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
