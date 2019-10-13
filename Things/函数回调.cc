//小明去超市买东西，但超市没货了，小明将自己的电话给了店员，过来几天，超市进货了，店员给小明打电话，然后小明去超市超市将货物买下来。
//电话号码 --- 回调函数
//小明将电话留给店员 --- 登记回调函数
//超市进货 --- 触发回调函数的事件
//店员给小明打电话 --- 回调函数调用
//小明去超市将货物买下来 --- 响应回调事件

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//回调函数
void GetArray(vector<int>& _array, int count, int(*Get_RandNumber)()){
	for (int i = 0; i < count; i++){
		_array[i] = Get_RandNumber();
	}
}

//获取随机值
int Get_RandNumber(){
	int ret = rand() % 100 ;
	return ret;
}


int main(){
	srand(time(NULL));
	vector<int> _array(10, 0);
	GetArray(_array, 10, Get_RandNumber);
	
	for (auto e : _array){
		cout << e << " ";
	}

	cout << endl;
	return 0;
}
