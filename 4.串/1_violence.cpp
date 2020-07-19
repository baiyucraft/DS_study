#include <stdio.h>
#include "ThisString.h"

int IndexSTrVio(SString S, SString T) {
	int i = 1;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i + j - 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}

void SolveindexVio() {
	char stemp[255];
	// S
	SString S;
	printf("请输入主串S：");
	InitTemp(stemp);
	AssignSTr(S, stemp);
	// T
	SString T;
	printf("请输入模式串T：");
	InitTemp(stemp);
	AssignSTr(T, stemp);
	printf("主串S为：");
	PrintSTr(S);
	printf("模式串T为：");
	PrintSTr(T);
	// 定位
	int index = IndexSTr(S, T);
	if (index == 0)
		printf("主串S中未找到与模式串T相同的子串\n");
	else
		printf("模式串T在主串S中第一次出现在第%d个字符\n", index);
}