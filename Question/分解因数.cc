// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> ret;
        int cur = n;
        
        for(int i = 2; i <= sqrt(cur); i++){
            while(1){
                if(cur % i == 0){
                    ret.push_back(i);
                    cur /= i;
                }
                else{
                    break;
                }
            }
        }
        if(cur != 1){
            ret.push_back(cur);
        }
        
        cout << n << " = ";
        int size = ret.size();
        for(auto it : ret){
            cout << it;
            if(size != 1){
                cout << " * ";
            }
            size--;
        }
        cout << endl;
    }
    
    return 0;
}

// write your code here cpp
#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << n << " = ";
        for(int i = 2; i < n; i++){
            while(n % i == 0 && n != i){
                cout << i << " * ";
                
                n /= i;
            }
        }
        
        cout << n << endl;
    }
    
    return 0;
}


