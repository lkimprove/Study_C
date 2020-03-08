// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        cin.get();    //处理回车；get()函数是cin对象的内置函数，可读取单个字符，包括空格，回车等
        
        for(int i = 0; i < n; i++){
            string cur;
            getline(cin, cur);
            
            if(cur.find(' ') != string::npos || cur.find(',') != string::npos){
                cout << '"' << cur << '"';
            }
            else{
                cout << cur;
            }
            
            if(i != n - 1){
                cout << ", ";
            }
        }
        
        cout << endl;
    }
    
    
    return 0;
}
