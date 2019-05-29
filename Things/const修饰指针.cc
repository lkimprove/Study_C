#include <iostream>
using namespace std;

int main(){
	{
		int i = 1;
		int j = 2;

		const int* a;  //const 修饰 *a, 即 *a 不可改变， a 可以改变 
		a = &i;
		printf("*a = %d\n", *a);  //*a = 1
		a = &j;
		printf("*a = %d\n\n", *a);  //*a = 2
		//*a = 3;     错误：*a必须是可以修改的左值
	}

	{
		int i = 1;
		int j = 2;

		int* const b = &i;  //const 修饰 b,即 b 不可改变，*b 可以改变 
		// int* const b;  错误：b 必须初始化
		//b = &j;   错误：b 必须是可以修改的左值
		printf("*b = %d\n", *b);
		*b = 2;
		printf("*b = %d\n\n", *b);
	}

	{
		int i = 1;
		int j = 2;

		int const *c;  //修饰 *c 与 const int* a 一致
		c = &i;
		printf("*c = %d\n", *c);
		c = &j;
		printf("*c = %d\n", *c);
		//*c = 3;   错误：*c 必须是可以修改的左值
	}


	system("pause");
	return 0;
}
