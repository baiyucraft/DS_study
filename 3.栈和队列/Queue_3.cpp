#include <stdio.h>
#include "SqStack.h"
#include "SqQueue.h"

// 判断栈满
bool OverflowSqStack(SqStack S) {
	if (S.top == MaxSize - 1) 
		return true;
	return false;
}
// 入队
bool EnQueue(SqStack& S1, SqStack& S2, ElemtType e) {
	// 如果S1不满，入栈
	if (!OverflowSqStack(S1)) {
		PushSqStack(S1, e);
		return true;
	}
	// 如果S1满了，S2不空，则队列满
	if (OverflowSqStack(S1) && !EmptySqStack(S2)) {
		printf("队列满");
		return false;
	}
	// 如果S1满了，S2空，将S1置于S2
	if (OverflowSqStack(S1) && EmptySqStack(S2)) {
		while (!EmptySqStack(S1))
			PushSqStack(S2, PopSqStack(S1));
	}
	// 放置S1
	PushSqStack(S1, e);
	return true;
}
// 出队
ElemtType DeQueue(SqStack& S1, SqStack& S2) {
	ElemtType x;
	if (!EmptySqStack(S2))
		x = PopSqStack(S2);
	else if (EmptySqStack(S1)) {
		printf("队列为空");
		return NULL;
	}
	else {
		while (!EmptySqStack(S1)) 
			PushSqStack(S2, PopSqStack(S1));
		x = PopSqStack(S2);
	}
	return x;
}
bool EmptyQueue(SqStack S1, SqStack S2) {
	if (EmptySqStack(S1) && EmptySqStack(S2))
		return true;
	else
		return false;
}

void SolveQueue_3() {
	SqStack S1, S2;
	InitSqStack(S1);
	InitSqStack(S2);
	ElemtType x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		EnQueue(S1, S2, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原S1为：");
	PrintSqStack(S1); 
	printf("原S2为：");
	PrintSqStack(S2);
	// 取出队顶元素
	x = DeQueue(S1, S2);
	printf("取出队顶元素%d后的顺序栈为：", x);
	printf("现在S1为：");
	PrintSqStack(S1);
	printf("现在S2为：");
	PrintSqStack(S2);
	if (EmptyQueue(S1, S2))
		printf("队为空");
	else
		printf("队不为空");
}