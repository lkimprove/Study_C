#include <iostream>
using namespace std;

int Fib(int n){
	//结束条件
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 2;
	}
	//递归式
	return Fib(n - 1) + Fib(n - 2);
}

int main(){
	int n;
	//输入
	while (cin >> n){
		//输出
		cout << Fib(n) << endl;
	}
	return 0;
}
