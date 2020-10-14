#include <iostream>
#include <string>
using namespace std;


int main(){
	string array;
	while (getline(cin, array)){
		string ret;

		for (int i = 0; i < array.size();){
			int count = 0;
			for (int j = i; j < array.size(); j++){
				if (array[i] == array[j]){
					count++;
				}
				else{
					break;
				}
			}

			if (count > 1){
				ret += to_string(count);
			}
			ret += array[i];
			
			i += count;
		}

		cout << ret << endl;

	}


	return 0;
}
