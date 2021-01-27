// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<string> vs(n);
        for(int i = 0; i < n; i++){
            cin >> vs[i];
        }
        vector<bool> flag(n, true);
        sort(vs.begin(), vs.end());
        
        for(int i = 0; i < n - 1; i++){
            if(vs[i] == vs[i + 1]){
                flag[i] = false;
            }
            else if(vs[i].size() < vs[i + 1].size() &&
                   vs[i + 1].substr(0, vs[i].size()) == vs[i] &&
                   vs[i + 1][vs[i].size()] == '/'){
                flag[i] = false;
            }
        }
        
        
        for(int i = 0; i < n; i++){
            if(flag[i]){
                cout << "mkdir -p " << vs[i] << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}
