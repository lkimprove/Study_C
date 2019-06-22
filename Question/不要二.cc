#include <iostream>
#include <vector>
using namespace std;

int Ret(int H, int W){
	// 初始化一个 H 行 W 列的二维数组
	vector<vector<int>> vv;
	vv.resize(H);
	for (int i = 0; i < H; i++){
		//每一个位置都填 1 表示有蛋糕
		vv[i].resize(W, 1);
	}
	//遍历这个二维数组
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			//将每一个不符合的位置的蛋糕取出
			//两个蛋糕的欧几里得距离不等于2  ==> 行距离为 2 或 列距离为 2 的位置没有蛋糕
			if (vv[i][j] == 1){
				//防止越界
				if (i - 2 > 0){
					vv[i - 2][j] = 0;
				}
				if (i + 2 < H){
					vv[i + 2][j] = 0;
				}
				if (j - 2 > 0){
					vv[i][j - 2] = 0;
				}
				if (j + 2 < W){
					vv[i][j + 2] = 0;
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (vv[i][j] == 1){
				ret++;
			}
		}
	}
	return ret;
}

int main(){
	int H, W;
	//输入
	while (cin >> H >> W){
		int ret = Ret(H, W);
		//输出
		cout << ret << endl;
	}
	return 0;
}
