#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int first = 0, second = 1, curr = first + second;
        
        while(curr < n){
            first = second;
            second = curr;
            curr = first + second;
        }
        
        int ret = curr - n < n - second ? curr - n : n - second;
        
        cout << ret << endl;
    }
    
    return 0;
}
