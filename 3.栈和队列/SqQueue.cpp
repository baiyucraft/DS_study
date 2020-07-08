#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

// 1.初始化队
void InitSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.入队
bool EnSqQueue(SqQueue& Q, ElemtType x) {
	if (Q.rear == MaxSize) {
		printf("队列假溢出");
		return false;
	}
	Q.data[Q.rear++] = x;
	return true;
}
// 3.出队
ElemtType DeSqQueue(SqQueue& Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素");
		return NULL;
	}
	return Q.data[Q.front++];
}
// 4.判队空
bool EmptySqQueue(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.读队顶元素
ElemtType GetHeadSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素");
		return NULL;
	}
	return Q.data[Q.front];
}
// 6.打印当前队
void PrintSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素\n");
		return;
	}
	printf("队顶(%d)-", Q.front);
	for (int i = Q.front; i < Q.rear; i++) {
		printf("%d-", Q.data[i]);
	}
	printf("队底(%d)\n", Q.rear);
}

// 1.初始化循环队
void InitCriSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.入循环队
bool EnCriSqQueue(SqQueue& Q, ElemtType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		printf("队列溢出");
		return false;
	}
	Q.data[Q.rear] = x;
	// 将尾指针的数值变成小于maxsize的
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
// 3.出循环队
ElemtType DeCriSqQueue(SqQueue& Q) {
	if (Q.rear == Q.front) {
		printf("队列中没有元素");
		return NULL;
	}
	ElemtType x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return x;
}
// 4.判循环队空
bool EmptyCriSqQueue(SqQueue Q) {
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}
// 5.读循环队顶元素
ElemtType GetHeadCriSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素");
		return NULL;
	}
	return Q.data[Q.front];
}
// 6.打印当前循环队
void PrintCriSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
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

void MainSqQueue() {
	SqQueue Q;
	InitSqQueue(Q);
	ElemtType x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		EnSqQueue(Q, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原顺序队为：");
	PrintSqQueue(Q);
	// 取出队顶元素
	x = DeSqQueue(Q);
	printf("取出队顶元素%d后的顺序栈为：", x);
	PrintSqQueue(Q);
	// 读队顶元素
	printf("此时的队顶元素为：%d\n", GetHeadSqQueue(Q));
	// 队判空
	if (EmptySqQueue(Q))
		printf("队为空");
	else
		printf("队不为空");
}

void MainCriSqQueue() {
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
	// 取出队顶元素
	x = DeCriSqQueue(Q);
	printf("取出队顶元素%d后的顺序栈为：", x);
	PrintCriSqQueue(Q);
	// 读队顶元素
	printf("此时的队顶元素为：%d\n", GetHeadSqQueue(Q));
	// 队判空
	if (EmptyCriSqQueue(Q))
		printf("队为空");
	else
		printf("队不为空");
}