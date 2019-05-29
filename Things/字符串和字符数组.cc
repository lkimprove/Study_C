#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//字符数组赋初值
	char cArr[] = { 'I', 'L', 'O', 'V', 'E', 'C' };
	//字符串赋初值
	char sArr[] = "ILOVEC";

	printf("字符数组：%d\n", sizeof(cArr) / sizeof(cArr[0]));    //6 
	printf("字符串：%d\n", sizeof(sArr));                        //7 (算上了 '\0')

	printf("字符数组：%d\n", strlen(cArr));  // strlen 需要识别出‘\0’，而字符数组没有‘\0’,则输出随机值
	printf("字符串：%d\n", strlen(sArr));    // 6 strlen 识别 '\0'前的字符个数，不包括 '\0'

	system("pause");
	return 0;
}
