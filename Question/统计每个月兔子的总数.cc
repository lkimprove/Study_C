#include <iostream>
#include <vector>
using namespace std;

int main(){
    int month;
    while(cin >> month){
        vector<int> Fib(month + 1, 1);
        
        //斐波那契数列
        for(int i = 3; i <= month; i++){
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        
        cout << Fib[month] << endl;
    }
    
    return 0;
}
