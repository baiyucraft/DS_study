#include <stdio.h>
#include <stdlib.h>
#include "ThisString.h"

void GetNextVal(SString T, int* nextval) {
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	// 打印
	i = 1;
	printf("nextval数组为：");
	while (i <= T.length)
		printf("%d ", nextval[i++]);
	printf("\n");
}

int IndexSTrKMPVal(SString S, SString T) {
	int i = 1;
	int j = 1;
	// int next[T.length + 1];
	int* nextval;
	nextval = (int*)malloc(sizeof(int) * (T.length + 1));
	GetNextVal(T, nextval);
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
void SolveindexKMPVal() {
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
	int index = IndexSTrKMPVal(S, T);
	if (index == 0)
		printf("主串S中未找到与模式串T相同的子串\n");
	else
		printf("模式串T在主串S中第一次出现在第%d个字符\n", index);
}