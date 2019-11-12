//在C++11标准中规定，string是以'\0'结尾的

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	if (s[s.size()] == '\0'){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
