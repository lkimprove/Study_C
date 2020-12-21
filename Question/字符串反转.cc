#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        int start = 0, end= str.size() - 1;
        while(start < end){
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            
            start++;
            end--;
        }
        
        cout << str << endl;
    }
    
    return 0;
}
