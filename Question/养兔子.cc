// write your code here cpp
#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        long long first = 1, second = 2;
        for(int i = 2; i <= n; i++){
            long long cur = first + second;
            first = second;
            second = cur;
        }
        
        cout << first << endl;
    }
    
    return 0;
}
