#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//字符串转换
int StringToInt(string& str){
	int curr = 0;
	while (curr < str.size() - 1 && str[curr] == '0'){
		curr++;
	}

	int ret = 0;
	while (curr < str.size()){
		ret = ret * 10 + (str[curr] - '0');
		curr++;
	}

	return ret;
}


int main(){
	string str;
	while (cin >> str){
		vector<int> ret;

		int curr = 0;
		while (curr < str.size()){
			string temp;
			
			//获取数字字符串
			while (curr < str.size() && str[curr] >= '0' && str[curr] <= '9'){
				temp += str[curr];
				curr++;
			}

			if (temp.size() != 0){
				ret.push_back(StringToInt(temp));
			}

			curr++;
		}


		sort(ret.begin(), ret.end());

		cout << "读取到的数字" << endl;
		for (int i = 0; i < ret.size(); i++){
			cout << ret[i] << endl;
		}
	}

	return 0;
}
