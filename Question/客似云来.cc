// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<long long> F(80, 0);
    F[0] = 1;
    F[1] = 1;
    for(int i = 2; i < 80; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
    
    int n, m;
    while(cin >> n >> m){
        long long ret = 0;
        for(int i = n- 1; i < m; i++){
            ret += F[i];
        }
        cout << ret << endl;
    }
    
    return 0;
}
