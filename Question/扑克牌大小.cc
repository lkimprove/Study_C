#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        //双王最大
        if(str.find("joker JOKER") != string::npos){
            cout << "joker JOKER" << endl;
        }
        else{
            //获取两副手牌
            size_t npos = str.find('-');
            string s1 = str.substr(0, npos);
            string s2 = str.substr(npos + 1);
            
            //计算两副手牌的数量
            int num1 = count(s1.begin(), s1.end(), ' ') + 1;
            int num2 = count(s2.begin(), s2.end(), ' ') + 1;
            
            //获取每副牌的第一张牌
            string first1 = s1.substr(0, s1.find(' '));
            string first2 = s2.substr(0, s2.find(' '));
            
            string tmp = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
            //牌数相同，同类型的牌比大小
            if(num1 == num2){
                if(tmp.find(first1) > tmp.find(first2)){
                    cout << s1 << endl;
                }
                else{
                    cout << s2 << endl;
                }
            }
            //牌数不同，只剩炸弹可以比较
            else{
                if(num1 == 4){
                    cout << s1 << endl;
                }
                else if(num2 == 4){
                    cout << s2 << endl;
                }
                else{
                    cout << "ERROR" << endl;
                }
            }
        }
    }
    
    return 0;
}
