#include <iostream>
#include <string>
using namespace std;

bool IsCircleString(string& str){
    int begin = 0, end = str.size() - 1;
    while(begin < end){
        if(str[begin] != str[end]){
            return false;
        }
        
        begin++;
        end--;
    }
    
    return true;
}


int main(){
    string A, B;
    while(getline(cin, A)){
        getline(cin, B);
        
        int ret = 0;
        for(int i = 0; i <= A.size(); i++){
            string temp = A;
            temp.insert(i, B);
            
            if(IsCircleString(temp)){
                ret++;
            }
        }
        
        cout << ret << endl;
    }
    
    return 0;
}
