#include <iostream>
#include <stdlib.h>
using namespace std;

// 0 是由 2 和 5 构成的，则 0 的个数为 min{ num(2), num(5) }
// n! 中 5 的个数肯定比 2 少，所以只用求 5 的个数即可
// 1 到 n 中有 （n / 5）个 5，
// 但 25 中有两个 5 ，其中一个已经在 （n / 5 ）中计算
// 所以只用求 1 到 n 中有多少个 25，即 （n / 25） 
// 125 中三个 5 ，第一个 5 在 （n / 5）中计算， 第二个 5 在 （n / 25）中计算
// 所以只用求 1 到 n 中有多少个 125，即 （n / 125）
//以此类推即可求出 n! 后面有多少个 0 

int Number_0(int n){
	int count = 0;
	while (n > 0){
		count += n / 5;
		n /= 5;
	}
	return count;
}

int main(){
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		cout << Number_0(n) << endl;
	}
	system("pause");
	return 0;
}
