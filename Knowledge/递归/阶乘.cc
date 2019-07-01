#include <iostream>
using namespace std;

int Fact(int n){
	//结束条件
	if (n <= 1){
		return 1;
	}
	//递归式
	return n * Fact(n - 1);
}


int main(){
	int n;
	while (cin >> n){
		//输出
		cout << Fact(n) << endl;
	}
	return 0;
}
