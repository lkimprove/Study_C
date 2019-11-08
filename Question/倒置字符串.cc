#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        //逆置整个s
        reverse(s.begin(), s.end());
        
        //逆置每一个单词
        auto start = s.begin();
        while(start != s.end()){
            auto end = start;
            while(end != s.end() && *end != ' '){
                end++;
            }
            
            reverse(start, end);
            
            if(end != s.end()){
                start = end + 1;
            }
            else {
                break;
            }
        }
        
        cout << s << endl;
        
    }
    
    return 0;
}
