//恶心0.0
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	string str;
	//3 4 5 6 7 8 9 10 J Q K A 2 
	map<string, int> m;
	m["3"] = 1;
	m["4"] = 2;
	m["5"] = 3;
	m["6"] = 4;
	m["7"] = 5;
	m["8"] = 6;
	m["9"] = 7;
	m["10"] = 8;
	m["J"] = 9;
	m["Q"] = 10;
	m["K"] = 11;
	m["A"] = 12;
	m["2"] = 13;
	while (getline(cin, str)){

		//通过空格判断牌的数量
		int s1 = 1, s2 = 1, flag = 0, i = 0;
		for (; i < str.size(); i++){
			if (str[i] == 'j'){
				int j = i;
				while (str[j] != 'J' && j < str.size()){
					j++;
				}
				if (str[j] == 'J'){
					cout << "joker JOKER" << endl;
					break;
				}
			}
			else if (str[i] == '-'){
				flag = i;
			}
			else if (str[i] == ' '){
				if (flag){
					s2++;
				}
				else{
					s1++;
				}
			}
		}

		if (i != str.size()){
			continue;
		}

		if (s1 != s2){
			//判断是否有炸弹
			if (s1 == 4){
				for (int i = 0; i < flag; i++){
					cout << str[i];
				}
				cout << endl;
			}
			else if (s2 == 4){
				for (int i = flag + 1; i < str.size(); i++){
					cout << str[i];
				}
				cout << endl;
			}
			else{
				cout << "ERROR" << endl;
			}
		}
		else{
			int curr = 0;
			string s1, s2;
			while (curr < str.size() && str[curr] != ' ' && str[curr] != '-'){
				s1 += str[curr];
				curr++;
			}
			curr = flag + 1;
			while (curr < str.size() && str[curr] != ' ' && str[curr] != '-'){
				s2 += str[curr];
				curr++;
			}

			if (m[s1] < m[s2]){
				for (int i = flag + 1; i < str.size(); i++){
					cout << str[i];
				}
				cout << endl;
			}
			else{
				for (int i = 0; i < flag; i++){
					cout << str[i];
				}
				cout << endl;
			}
		}

	}

	return 0;
}


//优化
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        //判断是否有双王
        if(str.find("joker JOKER") != string::npos){
            cout << "joker JOKER" << endl;
            continue;
        }
        
        //获取两幅手牌
        size_t pos = str.find('-');
        string s1 = str.substr(0, pos);
        string s2 = str.substr(pos + 1);
        
        //获取两副牌的数量
        int size1 = count(s1.begin(), s1.end(), ' ') + 1;
        int size2 = count(s2.begin(), s2.end(), ' ') + 1;
        
        string temp = "3 4 5 6 7 8 9 10 J Q K A 2";
        //如果牌的数量不相等，判断是否有炸弹
        if(size1 != size2){
            if(size1 == 4){
                cout << s1 << endl;
            }
            else if(size2 == 4){
                cout << s2 << endl;
            }
            else{
                cout << "ERROR" << endl;
            }
        }
        else{
            string first1 = s1.substr(0, s1.find(' '));
            string first2 = s2.substr(0, s2.find(' '));
            
            if(temp.find(first1) < temp.find(first2)){
                cout << s2 << endl;
            }
            else{
                cout << s1 << endl;
            }
        }
        
    }
    
    return 0;
}
