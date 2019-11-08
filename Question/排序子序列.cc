#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        //输入
        vector<int> numbers(n, 0);
        for(int i = 0; i < n; i++){
            cin >> numbers[i];
        }
        
        int count = 1;
        //遍历
        for(int  i = 1; i < n - 1; i++){
            //寻找波峰/波谷
            if((numbers[i - 1] < numbers[i] && numbers[i] > numbers[i + 1])||
               (numbers[i - 1] > numbers[i] && numbers[i] < numbers[i + 1])
              ){
                count++;
                
                //越过波峰/波谷，避免其被计算两次（1212121）
                if(i != n - 3){
                    i++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
