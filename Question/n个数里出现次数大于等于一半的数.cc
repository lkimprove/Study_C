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
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> num;
    int n;
    while(cin >> n){
        num.push_back(n);
    }
    
    int count = 1, ret = 0;
    for(int i = 0; i < num.size(); i++){
        if(count == 0){
            ret = num[i];
            count++;
        }
        else{
            if(ret == num[i]){
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
