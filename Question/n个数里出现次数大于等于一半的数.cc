#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    //创建unordered_map
    unordered_map<int, int> map;
    int n, num = 0;
    while(cin >> n){
        //对应数字++
        map[n]++;
        num++;
    }
    
    for(auto& it : map){
        if(it.second >= (num / 2)){
            cout << it.first << endl;
        }
    }
    
    return 0;
}

//修改版1.0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> num;
    int n;
    while(cin >> n){
        num.push_back(n);
    }
    
    sort(num.begin(), num.end());
    
    cout << num[num.size() / 2 - 1] << endl;
    
    return 0;
}


//修改版2.0
//存在问题：1 2 0 2 会输出0
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    while(cin >> n){
        v.push_back(n);
    }
    
    int count = 1, ret = v[0];
    for(int i = 1; i < v.size(); i++){
        if(count == 0){
            ret = v[i];
            count = 1;
        }
        else{
            if(v[i] == ret){
                count++;
            }
            else{
                count--;
            }
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
