#include <iostream>
using namespace std;

//辗转相除法计算最大公约数

int gcd(int x, int y){
	if (!y){
		return x;
	}
	return gcd(y, x % y);
}

int main(){
	int x, y;
	while (cin >> x >> y){
		int ret = gcd(x, y);
		cout << ret << endl;
	}
	return 0;
}
