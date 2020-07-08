#include <stdio.h>
#include "SqStack.h"

// 入栈，i代表栈号
bool PushSTK(STK& S, int i, ElemtType x) {
	if (i < 0 || i > 1) {
		printf("栈号不对\n");
		return false;
	}
	if (S.top[1] - S.top[0] == 1) {
		printf("栈已满\n");
		return false;
	}
	switch (i) {
	case 0:S.stack[++S.top[0]] = x; return true;
	case 1:S.stack[--S.top[1]] = x; return true;
	}
}
// 出栈，i代表栈号
ElemtType PopSTK(STK& S, int i) {
	if (i < 0 || i > 1) {
		printf("栈号不对\n");
		return false;
	}
	switch (i) {
	case 0:
		if (S.top[0] == -1) {
			printf("栈空\n");
			return NULL;
		}
		else
			return S.stack[S.top[0]--];
	case 1:
		if (S.top[1] == MaxS) {
			printf("栈空\n");
			return NULL;
		}
		else 
			return S.stack[S.top[1]++];
	}
	return true;
}
// 打印
void PrintSqStack(STK S) {
	int i;
	printf("左边-");
	if (S.top[0] == -1) {
		printf("第一个栈为空");
	}
	else {
		for (i = 0; i <= S.top[0]; i++) {
			printf("%d-", S.stack[i]);
		}
	}
	if (S.top[1] == MaxS) {
		printf("第二个栈为空");
		printf("右边\n");
	}
	else {
		printf("中间-");
		for (i = S.top[1]; i < MaxS; i++) {
			printf("%d-", S.stack[i]);
		}
		printf("右边\n");
	}
}

void SolveStack_5() {
	STK S;
	S.top[0] = -1;
	S.top[1] = MaxS;
	ElemtType x;
	int i;
	printf("请输入数(输入9999结束)：");
	scanf("%d %d", &i, &x);
	//printf("%d %d", i, x);
	while (x != 9999) {
		PushSTK(S, i, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d %d", &i, &x);
	}
	printf("表为：");
	PrintSqStack(S);
	PopSTK(S, 0);
	printf("第一个栈出栈一个后为：");
	PrintSqStack(S);
	PopSTK(S, 1);
	printf("第二个栈出栈一个后为：");
	PrintSqStack(S);
}