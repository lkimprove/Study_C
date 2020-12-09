#include <iostream>
#include <algorithm>
using namespace std;

bool IsPrime(int number){
    for(int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            return false;
        }
    }
    
    return true;
}


int main(){
    int number;
    while(cin >> number){
        for(int i = number / 2; i > 0; i--){
            if(IsPrime(i) && IsPrime(number - i)){
                cout << i << endl;
                cout << number - i << endl;
                break;
            }
        }
    }
    
    return 0;
}
