#include <iostream>
#include <vector>
using namespace std;

int main(){
    int year, month, day;
    while(cin >> year >> month >> day){
        vector<int> monthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        //判断平闰年
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
            monthDay[2] = 29;
        }
        
        //判断输入合法性
        if(month < 1 || month > 12 || day < 1 || day > monthDay[month]){
            cout << -1 << endl;
        }
        
        int ret = 0;
        //前几个月的天数
        for(int i = 1; i < month; i++){
            ret += monthDay[i];
        }
        //本月天数
        ret += day;
        
        cout << ret << endl;
    }
    
    return 0;
}
