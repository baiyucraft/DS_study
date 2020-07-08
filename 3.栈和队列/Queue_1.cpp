#include <stdio.h>
#include "SqQueue.h"

// 设"tag"的入队
bool EnSqQueueTag(SqQueueT& Q,ElemtType x) {
	if (Q.rear == Q.front && Q.tag == 1) {
		printf("队列溢出");
		return false;
	}
	Q.data[Q.rear] = x;
	// 将尾指针的数值变成小于maxsize的
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}
// 设"tag"的出队
ElemtType DeSqQueueTag(SqQueueT& Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		printf("队列中没有元素");
		return NULL;
	}
	ElemtType x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return x;
}
// 设"tag"的初始化
void InitSqQueueTag(SqQueueT& Q) {
	Q.front = Q.rear = 0;
}
// 设"tag"的打印
void PrintSqQueueTag(SqQueueT Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		printf("队列中没有元素");
		return;
	}
	printf("队顶(%d)-", Q.front);
	int j;
	// 如果队尾指针小，则队尾指针+Maxsize
	j = Q.front > Q.rear ? Q.rear + MaxSize : Q.rear;
	for (int i = Q.front; i < j; i++) {
		printf("%d-", Q.data[i % MaxSize]);
	}
	printf("队底(%d)\n", Q.rear);
}

void SolveQueue_1() {
	SqQueueT Q;
	InitSqQueueTag(Q);
	ElemtType x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		EnSqQueueTag(Q, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原顺序队为：");
	PrintSqQueueTag(Q);
	// 取出队顶元素
	x = DeSqQueueTag(Q);
	printf("取出队顶元素%d后的顺序栈为：", x);
	PrintSqQueueTag(Q);
}