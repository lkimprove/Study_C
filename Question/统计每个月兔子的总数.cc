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


//修改版
#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 1 || n == 2){
            cout << 1 << endl;
            continue;
        }
        
        int first = 1, second = 1;
        for(int i = 3; i <= n; i++){
            int temp = first + second;
            first = second;
            second = temp;
        }
        
        cout << second << endl;
    }
    
    return 0;
}
