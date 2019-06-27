#include <stdio.h>
#include <string.h>

void LoopMove(char* str, int steps){
	//字符串长度
	int len = strlen(str);
	char temp[10];
	strcpy(temp, str + len - steps);
	strcpy(temp + steps, str);
	*(temp + len) = '\0';
	strcpy(str, temp);
}

int main(){
	char str[10];
	int steps;
	while (scanf("%s %d", str, &steps) != 0){
		LoopMove(str, steps);
		printf("字符串右移%d个位置后的结果为：%s\n", steps, str);
	}
	return 0;
}
