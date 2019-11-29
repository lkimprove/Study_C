#include <iostream>
using namespace std;

//辗转相除法计算最大公约数

int gcb(int n, int m){
    while(n % m){
        int cur = m;
        m = n % m;
        n = cur;
    }
    
    return m;
}

int main(){
	int x, y;
	while (cin >> x >> y){
		int ret = gcd(x, y);
		cout << ret << endl;
	}
	return 0;
}
