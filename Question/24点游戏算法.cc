#include <iostream>
#include <vector>
using namespace std;

//涉及除法运算，将运算数的精度提高
bool Is24(vector<double>& array, double total, int ret){
    if(array.empty()){
        return total == ret;
    }
    
    for(int i = 0; i < array.size(); i++){
        vector<double> b(array);
        b.erase(b.begin() + i);	//移除一个元素
        
        if(Is24(b, total + array[i], ret) ||
          Is24(b, total - array[i], ret) ||
          Is24(b, total * array[i], ret) ||
          Is24(b, total / array[i], ret)){
            return true;
        }
    }
    
    return false;
}

int main(){
    vector<double> array(4, 0);
    while(cin >> array[0] >> array[1] >> array[2] >> array[3]){
        if(Is24(array, 0, 24)){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
    
    return 0;
}