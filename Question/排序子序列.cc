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
                //不能越过n-3，如果越过，则n-2位置会被跳过
                if(i != n - 3){
                    i++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    while(cin >> n){
        vector<int> array(n, 0);
        for(int i = 0; i < n; i++){
            cin >> array[i];
        }
        
        //flag: 1代表升序，2代表降序，到转折点时为0
        int flag = 0, ret = 1;
        for(int i = 0; i < n - 1; i++){
            if(array[i] == array[i + 1]){
                continue;
            }
            else if(array[i] < array[i + 1]){
                if(flag == 2){
                    ret++;
                    flag = 0;
                }
                else{
                    flag = 1;
                }
            }
            else if(array[i] > array[i + 1]){
                if(flag == 1){
                    ret++;
                    flag = 0;
                }
                else{
                    flag = 2;
                }
            }
        }
        
        cout << ret << endl;
        
    }
    
    return 0;
}
