#include <stdio.h>
#include <stdlib.h>
#include "SqQueue.h"

// 1.��ʼ����
void InitSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.���
bool EnSqQueue(SqQueue& Q, ElemtType x) {
	if (Q.rear == MaxSize) {
		printf("���м����");
		return false;
	}
	Q.data[Q.rear++] = x;
	return true;
}
// 3.����
ElemtType DeSqQueue(SqQueue& Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��");
		return NULL;
	}
	return Q.data[Q.front++];
}
// 4.�жӿ�
bool EmptySqQueue(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.���Ӷ�Ԫ��
ElemtType GetHeadSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��");
		return NULL;
	}
	return Q.data[Q.front];
}
// 6.��ӡ��ǰ��
void PrintSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��\n");
		return;
	}
	printf("�Ӷ�(%d)-", Q.front);
	for (int i = Q.front; i < Q.rear; i++) {
		printf("%d-", Q.data[i]);
	}
	printf("�ӵ�(%d)\n", Q.rear);
}

// 1.��ʼ��ѭ����
void InitCriSqQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.��ѭ����
bool EnCriSqQueue(SqQueue& Q, ElemtType x) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		printf("�������");
		return false;
	}
	Q.data[Q.rear] = x;
	// ��βָ�����ֵ���С��maxsize��
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}
// 3.��ѭ����
ElemtType DeCriSqQueue(SqQueue& Q) {
	if (Q.rear == Q.front) {
		printf("������û��Ԫ��");
		return NULL;
	}
	ElemtType x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return x;
}
// 4.��ѭ���ӿ�
bool EmptyCriSqQueue(SqQueue Q) {
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}
// 5.��ѭ���Ӷ�Ԫ��
ElemtType GetHeadCriSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��");
		return NULL;
	}
	return Q.data[Q.front];
}
// 6.��ӡ��ǰѭ����
void PrintCriSqQueue(SqQueue Q) {
	if (Q.front == Q.rear) {
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

void MainSqQueue() {
	SqQueue Q;
	InitSqQueue(Q);
	ElemtType x;
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnSqQueue(Q, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳���Ϊ��");
	PrintSqQueue(Q);
	// ȡ���Ӷ�Ԫ��
	x = DeSqQueue(Q);
	printf("ȡ���Ӷ�Ԫ��%d���˳��ջΪ��", x);
	PrintSqQueue(Q);
	// ���Ӷ�Ԫ��
	printf("��ʱ�ĶӶ�Ԫ��Ϊ��%d\n", GetHeadSqQueue(Q));
	// ���п�
	if (EmptySqQueue(Q))
		printf("��Ϊ��");
	else
		printf("�Ӳ�Ϊ��");
}

void MainCriSqQueue() {
	SqQueue Q;
	InitCriSqQueue(Q);
	ElemtType x;
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnCriSqQueue(Q, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳���Ϊ��");
	PrintCriSqQueue(Q);
	// ȡ���Ӷ�Ԫ��
	x = DeCriSqQueue(Q);
	printf("ȡ���Ӷ�Ԫ��%d���˳��ջΪ��", x);
	PrintCriSqQueue(Q);
	// ���Ӷ�Ԫ��
	printf("��ʱ�ĶӶ�Ԫ��Ϊ��%d\n", GetHeadSqQueue(Q));
	// ���п�
	if (EmptyCriSqQueue(Q))
		printf("��Ϊ��");
	else
		printf("�Ӳ�Ϊ��");
}