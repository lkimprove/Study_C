#include <iostream>
using namespace std;

int main(){
    int m, n;
    while(cin >> m >> n){
        int i = 2, ret = 1;
        if(m > n){
            int temp = m;
            m = n;
            n = temp;
        }
        
        
        while(i <= m){
            if(m % i == 0 && n % i == 0){
                ret *= i;
                m /= i;
                n /= i;
                
                i = 2;
            }
            else{
                i++;
            }
        }
        
        ret = ret * m * n;
        
        cout << ret << endl;
    }
    
    return 0;
}

#include <iostream>
using namespace std;

int gcb(int m, int n){
    int ret;
    while(ret = m % n){
        m = n;
        n = ret;
    }
    
    return n;
}

int main(){
    int m, n;
    while(cin >> m >> n){
        cout << m / gcb(m, n) * n << endl;
    }
    
    return 0;
}
