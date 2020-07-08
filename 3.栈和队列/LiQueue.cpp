#include <stdio.h>
#include <stdlib.h>
#include "LiQueue.h"

// 1.初始化队
void InitLiQueue(LiQueue& Q) {
	// 建立头结点
	Q.front = Q.rear = (LiQueueNode*)malloc(sizeof(LiQueueNode));
	Q.rear->next = NULL;
}
// 2.入队
bool EnLiQueue(LiQueue& Q, ElemtType x) {
	// 新建结点
	LiQueueNode* s = (LiQueueNode*)malloc(sizeof(LiQueueNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}
// 3.出队
ElemtType DeLiQueue(LiQueue& Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素\n");
		return NULL;
	}
	// 存储出队的结点
	LiQueueNode* p = Q.front->next;
	ElemtType x = p->data;
	Q.front->next = p->next;
	// 如果只有一个结点，删除后变空
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return x;
}
// 4.判队空
bool EmptyLiQueue(LiQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.读队顶元素
ElemtType GetHeadLiQueue(LiQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素\n");
		return NULL;
	}
	return Q.front->next->data;
}
// 6.打印当前队
void PrintLiQueue(LiQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素\n");
		return;
	}
	printf("队顶-");
	LiQueueNode* p = Q.front->next;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("队底\n");
}
// 7.销毁队
bool DestroyLiQueue(LiQueue& Q) {
	if (Q.rear != Q.front) {
		LiQueueNode* p = Q.front->next, * q;
		while (p != NULL) {
			q = p;
			p = p->next;
			free(q);
		}
	}
	// 暂时没有想到为啥rear不能free，否则就报错了
	//free(Q.rear);
	free(Q.front);
	return true;
}

// 功能测试
void MainLiQueue() {
	LiQueue Q;
	InitLiQueue(Q);
	ElemtType x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		EnLiQueue(Q, x);
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	printf("原顺序队为：");
	PrintLiQueue(Q);
	// 取出队顶元素
	x = DeLiQueue(Q);
	printf("取出队顶元素%d后的顺序栈为：", x);
	PrintLiQueue(Q);
	// 读队顶元素
	printf("此时的队顶元素为：%d\n", GetHeadLiQueue(Q));
	// 队判空
	if (EmptyLiQueue(Q))
		printf("队为空");
	else
		printf("队不为空");
	// 队判空
	if (DestroyLiQueue(Q))
		printf("已经销毁");
	else
		printf("未销毁");
}