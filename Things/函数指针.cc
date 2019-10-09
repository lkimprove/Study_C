#include <iostream>
using namespace std;

typedef int (*handler_t)(int, int);

int Max(int a, int b){
    return a > b ? a : b;
}


int main(){
    handler_t p = Max;

    int a = 1, b = 7, c = 5;
    
    cout << "最大值为: " << p(a, p(b, c)) << endl;

    return 0;
}
