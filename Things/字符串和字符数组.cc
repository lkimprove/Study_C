#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	/*�ַ����鸳��ֵ*/
	char cArr[] = { 'I', 'L', 'O', 'V', 'E', 'C' };
	char cArr2[] = { 'I', 'L', 'O', 'V', 'E', 'C' };
	/*�ַ�������ֵ*/
	char sArr[] = "ILOVEC";

	printf("%d\n", sizeof(cArr) / sizeof(cArr[0]));
	printf("%d\n", sizeof(sArr));

	printf("%d\n", strlen(cArr));  // strlen ��Ҫʶ�����\0�������ַ�����û�С�\0��,��������ֵ
	printf("%d\n", strlen(cArr2));
	printf("%d\n", strlen(sArr));

	system("pause");
	return 0;
}