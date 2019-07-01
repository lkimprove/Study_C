#include <iostream>
#include <string>
using namespace std;

int main(){
    int sum;
    string order;
    while(cin >> sum >> order){
        //当前页面第一首歌
        int first = 1;
        //当前光标位置
        int sign = 1;
        if(sum <= 4){
            //读命令
            for(int i = 0; i < order.size(); i++){
                //first不用变，只用改变光标位置
                //特殊情况
                if(sign == 1 && order[i] == 'U'){
                   sign = sum;
                }
                else if(sign == sum && order[i] == 'D'){
                    sign = 1;
                }
                //其他情况
                else if(order[i] == 'U'){
                    sign--;
                }
                else if(order[i] == 'D'){
                    sign++;
                }
            }
            //输出
            for(int i = 1; i < sum; i++){
                cout << i << ' ';
            }
            cout << sum << endl;
            cout << sign << endl;
        }
        else {
            //读命令
            for(int i = 0; i < order.size(); i++){
                //特殊翻页
                if(sign == 1 && order[i] == 'U'){
                    sign = sum;
                    first = sum - 3;
                }
                else if(sign == sum && order[i] == 'D'){
                    sign = 1;
                    first = 1;
                }
                //一般翻页
                else if(sign != 1 && first == sign && order[i] == 'U'){
                    sign--;
                    first--;
                }
                else if(sign != sum && first == (sign - 3) && order[i] == 'D'){
                    sign++;
                    first++;
                }
                //其他情况
                else if(order[i] == 'U'){
                    sign--;
                }
                else if(order[i] == 'D'){
                    sign++;
                }
            }
            //输出
            for(int i = first; i < first + 3; i++){
                cout << i << ' ';
            }
            cout << first + 3 << endl;
            cout << sign << endl;
        }
    }
    return 0;
}
