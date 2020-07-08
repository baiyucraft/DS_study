#include <stdio.h>
#include "SqQueue.h"

// ��"tag"�����
bool EnSqQueueTag(SqQueueT& Q,ElemtType x) {
	if (Q.rear == Q.front && Q.tag == 1) {
		printf("�������");
		return false;
	}
	Q.data[Q.rear] = x;
	// ��βָ�����ֵ���С��maxsize��
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}
// ��"tag"�ĳ���
ElemtType DeSqQueueTag(SqQueueT& Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		printf("������û��Ԫ��");
		return NULL;
	}
	ElemtType x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return x;
}
// ��"tag"�ĳ�ʼ��
void InitSqQueueTag(SqQueueT& Q) {
	Q.front = Q.rear = 0;
}
// ��"tag"�Ĵ�ӡ
void PrintSqQueueTag(SqQueueT Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		printf("������û��Ԫ��");
		return;
	}
	printf("�Ӷ�(%d)-", Q.front);
	int j;
	// �����βָ��С�����βָ��+Maxsize
	j = Q.front > Q.rear ? Q.rear + MaxSize : Q.rear;
	for (int i = Q.front; i < j; i++) {
		printf("%d-", Q.data[i % MaxSize]);
	}
	printf("�ӵ�(%d)\n", Q.rear);
}

void SolveQueue_1() {
	SqQueueT Q;
	InitSqQueueTag(Q);
	ElemtType x;
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnSqQueueTag(Q, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳���Ϊ��");
	PrintSqQueueTag(Q);
	// ȡ���Ӷ�Ԫ��
	x = DeSqQueueTag(Q);
	printf("ȡ���Ӷ�Ԫ��%d���˳��ջΪ��", x);
	PrintSqQueueTag(Q);
}