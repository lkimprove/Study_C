#include "Date.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

void Test(){
	//Date d1;
	//Date d2;

	//d2++;
	//d2 -= 2;

	//d1.Print();
	//d2.Print();
	//if (d1 >= d2){
	//	cout << "d1 >= d2" << endl;
	//}
	//else{
	//	cout << "d1 (!)>= d2" << endl;
	//}


	//Date d1(2010, 1, 2);
	//
	//d1 += 2000;
	//d1.Print();

	//d1 -= 2000;
	//d1.Print();


	//Date d2 = d1 + 2000;
	//cout << d2 - d1 << endl;
	//cout << d1 - d2 << endl;


	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2 << endl;



}

int main(){
	Test();

	system("pause");
	return 0;
}