//利用联合体确定本机字节序

#include <iostream>
using namespace std;

union tmp{
	int a;
	char ai[4];
};


int main(){
	tmp t;
	t.a = 0x40302010;

	for (int i = 0; i < 4; i++){
		printf("%x\n", t.ai[i]);
	}

	return 0;
}

//输出结果为：
//		10
//		20
//		30
//		40
//低地址存低位，高地址存高位，本机为小端字节序
