#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int FindMinimum(int n, vector<int> left, vector<int> right) {
	int ret = 0;
	int left_min = INT_MAX, right_min = INT_MAX;
	int left_sum = 0, right_sum = 0;
	
	for (int i = 0; i < n; i++){
		//如果该颜色的手套只有左手或右手，则必须取,以保证覆盖每一种颜色
		if (left[i] * right[i] == 0){
			ret += (left[i] + right[i]);
		}
		else{
			//分别计算成对的手套左右的数量和
			right_sum += right[i];
			left_sum += left[i];
			//分别记录左右的最小数量
			right_min = min(right_min, right[i]);
			left_min = min(left_min, left[i]);
		}
	}
	
	//right_ret = 右边数量和 -右边的最小值 + 1
	//left_ret = 左边数量和 - 左边最小值 + 1
	int right_ret = right_sum - right_min + 1;
	int left_ret = left_sum - left_min + 1;
	
	//取左右结果的最小值 + 1，就可以保证了
	ret += min(right_ret, left_ret) + 1;
	return ret;
}

int main(){
	int n;
	while (cin >> n){
		vector<int> left(n, 0);
		vector<int> right(n, 0);
		//输入
		for (int i = 0; i < n; i++){
			cin >> left[i];
		}
		for (int i = 0; i < n; i++){
			cin >> right[i];
		}
		//输出
		int ret = FindMinimum(n, left, right);
		cout << ret << endl;
	}
	return 0;
}
