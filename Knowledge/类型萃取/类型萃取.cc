#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
using namespace std;

//创建两个类型，实现分流
struct TrueType{};
struct FalseType{};

//基础类模板 ==> 处理自定义类型
template <class T>
struct TypeTraits{
	typedef FalseType IsPODType;
};

//特化 ==> 处理内置类型
//int
template <>
struct TypeTraits<int>{
	typedef TrueType IsPODType;
};
//float
template <>
struct TypeTraits<float>{
	typedef TrueType IsPODType;
};
//char
template <>
struct TypeTraits<char>{
	typedef TrueType IsPODType;
};

//通过参数类型不同，实现重载
//内置类型
template <class T>
void _Copy(T* dest, T* src, size_t size, TrueType){
	//浅拷贝
	memcpy(dest, src, sizeof(T) * size);
}
//自定义类型
template <class T>
void _Copy(T* dest, T* src, size_t size, FalseType){
	//深拷贝
	for (size_t i = 0; i < size; i++){
		dest[i] = src[i];
	}
}

//拷贝
template <class T>
void Copy(T* dest, T* src, size_t size){
	_Copy(dest, src, size, TypeTraits<T>::IsPODType());
}

//测试
//内置类型
template <class T>
void Test(){
	T src[10];
	T dest[20];
	size_t size = 5;
	cout << "请输入" << size <<"个" << typeid(T).name() << "类型的值" << endl;
	for (int i = 0; i < size; i++){
		cin >> src[i];
	}
	Copy(dest, src, size);
	cout << "dest：";
	for (int i = 0; i < size; i++){
		cout << dest[i] << " ";
	}
	cout << endl << endl;
}
//自定义类型
void Test_Shelf(){
	//string
	string src_string = "hello";
	string dest_string;
	size_t size_string = src_string.size();
	dest_string.resize(size_string * 2);
	Copy(&dest_string[0], &src_string[0], size_string);
	cout << "src_string：" << src_string << endl;
	cout << "dest_string：" << dest_string << endl << endl;
	
	//vector
	vector<int> src_vector = { 1, 2, 3, 4, 5 };
	vector<int> dest_vector;
	size_t size_vector = src_vector.size();
	dest_vector.resize(size_vector * 2);
	Copy(&dest_vector[0], &src_vector[0], size_vector);
	//输出
	cout << "src_vector：";
	for (size_t i = 0; i < size_vector; i++){
		cout << src_vector[i] << " ";
	}
	cout << endl;
	cout << "dest_vector：";
	for (size_t i = 0; i < size_vector; i++){
		cout << dest_vector[i] << " ";
	}
}

int main(){
	//内置类型
	Test<int>();
	Test<float>();
	Test<char>();

	//自定义类型
	Test_Shelf();

	return 0;
}
