#include <iostream>
#include <string>
using namespace std;

class Student{
private:
	string _name;
	//int _age;
	mutable int _age;	//将需要修改的成员变量设置成mutable属性
public:
	Student(string name = "李明", int age = 18) :
		_name(name), _age(age){

	}

	void ChageAge()const{
		_age = 20;
	}

	void Print() const{
		cout << _name << "---" << _age << endl;
	}
};

int main(){
	const Student s;
	s.Print();
	s.ChageAge();
	s.Print();

	return 0;
}
