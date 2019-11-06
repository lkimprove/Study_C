
//暴力破解
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


//哈希映射
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //输入
    string s1;
    while(getline(cin, s1)){
        string s2;
        getline(cin, s2);
        
        //建立哈希映射
        vector<int> hashTable(256, 0);
        for(int i = 0; i < s2.size(); i++){
            hashTable[s2[i]]++;
        }
        
        //将s1中不是公共字符的添加到ret中
        string ret;
        for(int i = 0; i < s1.size(); i++){
            if(hashTable[s1[i]] == 0){
                ret += s1[i];
            }
        }
        
        cout << ret << endl;
    }
    return 0;
}

