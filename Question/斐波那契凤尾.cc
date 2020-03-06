// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> F(1000000, 0);
    F[0] = 1;
    F[1] = 2;
    for(int i = 2; i < 1000000; i++){
        F[i] = F[i - 1] + F[i - 2];
        F[i] %= 1000000;
    }
    
    int n;
    while(cin >> n){
        if(n < 29){
            cout << F[n - 1] << endl;
        }
        else{
            printf("%06d\n", F[n - 1]);
        }
    }
    
    return 0;
}
