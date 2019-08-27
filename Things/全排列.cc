//全排列
//使用算法的全排列函数时必须先排序
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> v = { 1, 2, 3 };
  
	//排序
	sort(v.begin(), v.begin() + v.size());

	//全排列
	do{
		//打印
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}
