#include <iostream>
using namespace std;

int Bottle(int x){
	int ret = 0;
	while (x > 2){
		//可换的汽水数
		int cur = x / 3;
		//剩余的汽水瓶
		x = x % 3 + cur;
		ret += cur;
	}
	//如果剩余的汽水瓶数为 2，则可以多换一瓶
	if (x == 2){
		ret++;
	}
	return ret;
}

int main(){
	int x;
  //输入
	while (cin >> x){
		int ret = Bottle(x);
    //输出
		cout << ret << endl;
	}
	return 0;
}
