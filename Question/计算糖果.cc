#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> array(4, 0);
    for(int i = 0; i < 4; i++){
        cin >> array[i];
    }
    
    int A = (array[0] + array[2]) / 2;
    int B = (array[1] + array[3]) / 2;
    int C = (array[3] - array[1]) / 2;
    
    if(A - B == array[0] && B - C == array[1] && A + B == array[2] && B + C == array[3]){
        cout << A << " " << B << " " << C << endl;
    }
    else{
        cout << "No" << endl;
    }
    
    return 0;
}
