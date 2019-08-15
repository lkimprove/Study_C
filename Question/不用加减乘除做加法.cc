#include <iostream>
using namespace std;

int Add(int num1, int num2){
	while (num2 != 0){
		//本位相加结果
		int sum = num1 ^ num2;
		//进位
		int carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}
	return num1;
}

int main(){
	int num1, num2;
	//输入
	while (cin >> num1 >> num2){
		int ret = Add(num1, num2);
		//输出
		cout << ret << endl;
	}
	return 0;
}
