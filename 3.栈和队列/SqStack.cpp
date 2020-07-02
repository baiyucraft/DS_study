#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// 1.初始化栈
void InitSqStack(SqStack& S) {
	S.top = -1;
}
// 2.进栈
bool PushSqStack(SqStack& S, ElemtType x) {
	if (S.top == MaxSize - 1) {
		printf("栈已满");
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
// 3.出栈
ElemtType PopSqStack(SqStack& S) {
	if (S.top == -1) {
		printf("栈已空");
		return NULL;
	}
	return S.data[S.top--];
}
// 4.判栈空
bool EmptySqStack(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.读栈顶元素
ElemtType GetTopSqStack(SqStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return NULL;
	}
	return S.data[S.top];
}
// 6.打印当前栈
void PrintSqStack(SqStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return;
	}
	printf("栈顶-");
	for (int i = S.top; i >= 0; i--) {
		printf("%d-", S.data[i]);
	}
	printf("栈底\n");
}
// 7.销毁栈（没动态分配空间，不行）
bool DestroySqStack(SqStack& S) {
	free(&S);
	return true;
}

void MainSqStack() {
	SqStack S;
	// 初始化栈
	InitSqStack(S);
	ElemtType x;
	// 给栈中添加元素
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		PushSqStack(S, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原顺序栈为：");
	PrintSqStack(S);
	// 取出栈顶元素
	x = PopSqStack(S);
	printf("取出栈顶元素%d后的顺序栈为：", x);
	PrintSqStack(S);
	// 读栈顶元素
	printf("此时的栈顶元素为：%d\n", GetTopSqStack(S));
	// 栈判空
	if (EmptySqStack(S))
		printf("栈为空");
	else
		printf("栈不为空");
}
