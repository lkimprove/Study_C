#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int M, N;
    while(cin >> M >> N){
        int flag = 0;
        if(M < 0){
            flag = 1;
            M = -M;
        }
        
        string ret;
        while(M){
            int temp = M % N;
            if(temp > 9){
                ret += (temp - 10 + 'A');
            }
            else{
                ret += (temp + '0');
            }
            
            M /= N;
        }
        if(flag){
            ret += '-';
        }
        
        reverse(ret.begin(), ret.end());
        
        cout << ret << endl;
    }
    
    return 0;
}
