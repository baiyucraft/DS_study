#include <stdio.h>
#include <stdlib.h>
#include "LiQueue.h"

// 1.��ʼ����
void InitLiQueue(LiQueue& Q) {
	// ����ͷ���
	Q.front = Q.rear = (LiQueueNode*)malloc(sizeof(LiQueueNode));
	Q.rear->next = NULL;
}
// 2.���
bool EnLiQueue(LiQueue& Q, ElemtType x) {
	// �½����
	LiQueueNode* s = (LiQueueNode*)malloc(sizeof(LiQueueNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}
// 3.����
ElemtType DeLiQueue(LiQueue& Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��\n");
		return NULL;
	}
	// �洢���ӵĽ��
	LiQueueNode* p = Q.front->next;
	ElemtType x = p->data;
	Q.front->next = p->next;
	// ���ֻ��һ����㣬ɾ������
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return x;
}
// 4.�жӿ�
bool EmptyLiQueue(LiQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.���Ӷ�Ԫ��
ElemtType GetHeadLiQueue(LiQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��\n");
		return NULL;
	}
	return Q.front->next->data;
}
// 6.��ӡ��ǰ��
void PrintLiQueue(LiQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��\n");
		return;
	}
	printf("�Ӷ�-");
	LiQueueNode* p = Q.front->next;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("�ӵ�\n");
}
// 7.���ٶ�
bool DestroyLiQueue(LiQueue& Q) {
	if (Q.rear != Q.front) {
		LiQueueNode* p = Q.front->next, * q;
		while (p != NULL) {
			q = p;
			p = p->next;
			free(q);
		}
	}
	// ��ʱû���뵽Ϊɶrear����free������ͱ�����
	//free(Q.rear);
	free(Q.front);
	return true;
}

// ���ܲ���
void MainLiQueue() {
	LiQueue Q;
	InitLiQueue(Q);
	ElemtType x;
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnLiQueue(Q, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳���Ϊ��");
	PrintLiQueue(Q);
	// ȡ���Ӷ�Ԫ��
	x = DeLiQueue(Q);
	printf("ȡ���Ӷ�Ԫ��%d���˳��ջΪ��", x);
	PrintLiQueue(Q);
	// ���Ӷ�Ԫ��
	printf("��ʱ�ĶӶ�Ԫ��Ϊ��%d\n", GetHeadLiQueue(Q));
	// ���п�
	if (EmptyLiQueue(Q))
		printf("��Ϊ��");
	else
		printf("�Ӳ�Ϊ��");
	// ���п�
	if (DestroyLiQueue(Q))
		printf("�Ѿ�����");
	else
		printf("δ����");
}