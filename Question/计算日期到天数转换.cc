#include <iostream>
#include <vector>
using namespace std;

bool IsLeapYear(int year){
    if(year % 4 == 0 && year % 100 != 0){
        return true;
    }
    else if(year % 400 == 0){
        return true;
    }
    
    return false;
}


int main(){
    vector<int> monthDay = {0, 31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};
    int year, month, day;
    while(cin >> year >> month >> day){
        int ret = 0;
        
        for(int i = 1; i < month; i++){
            if(i == 2 && IsLeapYear(year)){
                ret += 1;
            }
            
            ret += monthDay[i];
        }
        
        ret += day;
        cout << ret << endl;
    }
    
    return 0;
}
