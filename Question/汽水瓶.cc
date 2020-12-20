#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        
        int ret = 0;
        while(n >= 3){
            ret += n / 3;
            n = n % 3 + n / 3;
        }
        
        if(n == 2){
            ret++;
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
