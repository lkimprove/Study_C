#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string PublicString(string& s1, string& s2){
	//让s1为短的字符串
	if (s1.size() > s2.size()){
		swap(s1, s2);
	}
	//计算长度，记录字符串位置
	int count = 0;
	int sign = 0;
	//开始遍历
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			//如果有字符相等，则开始计算
			if (s1[i] == s2[j]){
				//该字符串的长度
				int cur = 0;
				//记录此时的位置，不破坏外部循环
				int a = i;
				int b = j;
				while (s1[a] == s2[b] && a < s1.size() && b < s2.size()){
					cur++;
					a++;
					b++;
				}
				//判断该字符串的长度
				if (cur > count){
					count = cur;
					sign = i;
				}
				if (cur == count && sign > i){
					sign = i;
				}
			}
		}
	}
	string ret;
	ret.resize(count);
	int i = 0;
	while (count--){
		ret[i++] = s1[sign++];
	}
	return ret;
}

int main(){
	string s1, s2;
	while (cin >> s1 >> s2){
		string ret = PublicString(s1, s2);
		cout << ret << endl;
	}
	return 0;
}
