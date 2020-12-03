#include <iostream>
#include <string>
using namespace std;

int StringSize(string& str){
    int ret = 0;
    if(str.size() <= 4){
        ret = 5;
    }
    else if(str.size() >= 5 && str.size() <= 7){
        ret = 10;
    }
    else if(str.size() >= 8){
        ret = 25;
    }
    
    return ret;
}

int Words(string& str){
    int small = 0, big = 0;
    for(size_t i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            small++;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            big++;
        }
    }
    
    if(small && big){
        return 20;
    }
    else if(small || big){
        return 10;
    }
    else{
        return 0;
    }
}

int Numbers(string& str){
    int number = 0;
    for(size_t i = 0; i < str.size(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            number++;
        }
    }
    
    if(number > 1){
        return 20;
    }
    else if(number == 1){
        return 10;
    }
    else{
        return 0;
    }
}

int Marks(string& str){
    int mark = 0;
    for(size_t i = 0; i < str.size(); i++){
        if(str[i] >= 0x21 && str[i] <= 0x2F){
            mark++;
        }
        else if(str[i] >= 0x3A && str[i] <= 0x40){
            mark++;
        }
        else if(str[i] >= 0x5B && str[i] <= 0x60){
            mark++;
        }
        else if(str[i] >= 0x7B && str[i] <= 0x7E){
            mark++;
        }
    }
    
    if(mark > 1){
        return 25;
    }
    else if(mark == 1){
        return 10;
    }
    else{
        return 0;
    }
}


int main(){
    string str;
    while(cin >> str){
        int ret = StringSize(str) + Words(str) + Numbers(str) + Marks(str);
        
        if(Words(str) == 20 && Numbers(str) && Marks(str)){
            ret += 5;
        }
        else if(Words(str) && Numbers(str) && Marks(str)){
            ret += 3;
        }
        else if(Words(str) && Numbers(str)){
            ret += 2;
        }
        
        
        if(ret >= 90){
            cout << "VERY_SECURE" << endl;
        }
        else if(ret >= 80){
            cout << "SECURE" << endl;
        }
        else if(ret >= 70){
            cout << "VERY_STRONG" << endl;
        }
        else if(ret >= 60){
            cout << "STRONG" << endl;
        }
        else if(ret >= 50){
            cout << "AVERAGE" << endl;
        }
        else if(ret >= 25){
            cout << "WEAK" << endl;
        }
        else if(ret >= 0){
            cout << "VERY_WEAK" << endl;
        }
    }
    
    return 0;
}
