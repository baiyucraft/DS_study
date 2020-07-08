#include <stdio.h>
#include "SqQueue.h"
#include "SqStack.h"

// 用栈将队列中的元素逆置
void InverserSqQueue(SqQueue& Q) {
	SqStack S;
	InitSqStack(S);
	while (!EmptyCriSqQueue(Q)) 
		PushSqStack(S, DeCriSqQueue(Q));
	while (!EmptySqStack(S))
		EnCriSqQueue(Q, PopSqStack(S));
}

void SolveQueue_2() {
	SqQueue Q;
	InitCriSqQueue(Q);
	ElemtType x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		EnCriSqQueue(Q, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原顺序队为：");
	PrintCriSqQueue(Q);
	InverserSqQueue(Q);
	printf("逆置后的顺序队为：");
	PrintCriSqQueue(Q);
}