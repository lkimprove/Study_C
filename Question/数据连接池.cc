#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        //创建数据连接池
        set<string> pool;
        string key, val;
        
        //获取最大连接数
        int max = 0;
        for(int i = 0; i < n; i++){
            cin >> key >> val;
            if(val == "connect"){
                pool.insert(key);
            }
            else if(val == "disconnect"){
                pool.erase(key);
            }
            
            //获取当前连接数
            int size = pool.size();
            //得出历史最大连接数
            if(size > max){
                max = size;
            }
        }
        
        cout << max << endl;
    }
    
    return 0;
}
