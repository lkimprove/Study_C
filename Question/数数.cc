#include <iostream>
#include <vector>
#include <map>
using namespace std;


//获取子集中的众数
int ZhongShu(vector<int>& array){
	map<int, int> m;

	for (int i = 0; i < array.size(); i++){
		m[array[i]]++;
	}

	int count = 0, ret = 0;
	for (auto it : m){
		if (it.second > count){
			ret = it.first;
			count = it.second;
		}
	}

	return ret;
}



int main(){
	int n, m;
	while (cin >> n >> m){
		vector<int> array(n, 0);
		for (int i = 0; i < n; i++){
			cin >> array[i];
		}

		vector<int> ret;
		int curr = 0;
		while (curr < array.size()){
			vector<int> temp;

			//获取子集
			int index = curr, count = m;
			while (index < array.size() && count > 0){
				temp.push_back(array[index]);

				index++;
				count--; 
			}

			//判断是否还可以获取新的子集
			//获取子集中的众数
			if (count == 0){
				ret.push_back(ZhongShu(temp));

				curr++;
			}
			else if(count > 0){
				break;
			}
		}

		cout << "每个子集的众数为：" << endl;
		for (int i = 0; i < ret.size(); i++){
			cout << ret[i] << endl;
		}
	}


	return 0;
}