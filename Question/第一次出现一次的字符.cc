#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    //输入
    while(cin >> str){
        //创建一个26字符的数组
        //第一个位置记录该字符的出现次数
        //第二个位置记录该字符在字符串中出现的位置
        vector<vector<int>> words(26, vector<int>(2, 0));
        //遍历字符串
        for(int i = 0; i < str.size(); i++){
            words[str[i] - 'a'][0]++;
            words[str[i] - 'a'][1] = i; 
        }
        //标记第一次出现一次字符的位置
        int sign = str.size();
        //遍历组字母数组
        for(int i = 0; i < words.size(); i++){
            if(words[i][0] == 1 && words[i][1] < sign){
                sign = words[i][1];
            }
        }
        //输出
        if(sign == str.size()){
            cout << -1 << endl;
        }
        else {
            cout << str[sign] << endl;
        }
    }
    return 0;
}
