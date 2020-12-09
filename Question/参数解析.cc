#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        //储存每个参数
        vector<string> ss;
        
        bool sign = false;    //   标志
        string tmp;    //储存每一个参数
        
        for(int i = 0; i < str.size(); i++){
            //若找到"，则更新标志
            if(str[i] == '"'){
                sign = true;
                //跳过"
                continue;
            }
            
            //若标志为真，则开始处理双引号中的参数
            if(sign){
                //获取参数
                while(str[i] != '"'){
                    tmp += str[i];
                }
                
                ss.push_back(tmp);    //添加参数
                tmp.clear();    //清空tmp
                sign = false;    //更新标志
                
                //跳过"
                continue;
            }
            
            if(str[i] == ' '){
                ss.push_back(tmp);
                tmp.clear();
                continue;
            }
            
            tmp += str[i];
        }
        
        //最后一个参数
        if(tmp.size() > 0){
            ss.push_back(tmp);
        }
        
        //输出
        cout << ss.size() << endl;
        for(auto it : ss){
            cout << it << endl;
        }
    }
    
    return 0;
}


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        vector<string> vs;
        
        int i = 0;
        string temp;
        while(i < str.size()){
            if(str[i] == '"'){
                int j =  i + 1;
                while(str[j] != '"'){
                    temp += str[j];
                    j++;
                }
                
                i = j + 1;
            }
            else if(str[i] != ' '){
                temp += str[i];
                i++;
            }
            else if(str[i] == ' '){
                vs.push_back(temp);
                temp.clear();
                i++;
            }
        }
        
        vs.push_back(temp);
        cout << vs.size() << endl;
        for(int i = 0; i < vs.size(); i++){
            cout << vs[i] << endl;
        }
    }
    
    return 0;
}
