#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	/*字符数组赋初值*/
	char cArr[] = { 'I', 'L', 'O', 'V', 'E', 'C' };
	char cArr2[] = { 'I', 'L', 'O', 'V', 'E', 'C' };
	/*字符串赋初值*/
	char sArr[] = "ILOVEC";

	printf("%d\n", sizeof(cArr) / sizeof(cArr[0]));
	printf("%d\n", sizeof(sArr));

	printf("%d\n", strlen(cArr));  // strlen 需要识别出‘\0’，而字符数组没有‘\0’,则输出随机值
	printf("%d\n", strlen(cArr2));
	printf("%d\n", strlen(sArr));

	system("pause");
	return 0;
}