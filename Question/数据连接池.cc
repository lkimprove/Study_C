#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        set<string> pool;
        int max = 0;
        string key, value;
        
        for(int i = 0; i < n; i++){
            cin >> key >> value;
            
            //是否建立连接
            if(value == "connect"){
                pool.insert(key);
            }
            else if(value == "disconnect"){
                pool.erase(key);
            }
            
            //判断当前连接数量
            if(pool.size() > max){
                max = pool.size();
            }
        }
        
        cout << max << endl;
    }
    
    return 0;
}
