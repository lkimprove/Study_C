#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    //输入
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        //遍历s2，循环寻找
        auto it = s2.begin();
        while(it != s2.end()){
            size_t pos = string::npos;
            
            pos = s1.find(*it);
            //没找到
            if(pos == string::npos){
                it++;
            }
            //找到
            else if(pos != string::npos){
                s1.erase(pos, 1);
            }
        }
        
        cout << s1 << endl;
    }
    
    return 0;
}
