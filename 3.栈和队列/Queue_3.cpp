#include <stdio.h>
#include "SqStack.h"
#include "SqQueue.h"

// �ж�ջ��
bool OverflowSqStack(SqStack S) {
	if (S.top == MaxSize - 1) 
		return true;
	return false;
}
// ���
bool EnQueue(SqStack& S1, SqStack& S2, ElemtType e) {
	// ���S1��������ջ
	if (!OverflowSqStack(S1)) {
		PushSqStack(S1, e);
		return true;
	}
	// ���S1���ˣ�S2���գ��������
	if (OverflowSqStack(S1) && !EmptySqStack(S2)) {
		printf("������");
		return false;
	}
	// ���S1���ˣ�S2�գ���S1����S2
	if (OverflowSqStack(S1) && EmptySqStack(S2)) {
		while (!EmptySqStack(S1))
			PushSqStack(S2, PopSqStack(S1));
	}
	// ����S1
	PushSqStack(S1, e);
	return true;
}
// ����
ElemtType DeQueue(SqStack& S1, SqStack& S2) {
	ElemtType x;
	if (!EmptySqStack(S2))
		x = PopSqStack(S2);
	else if (EmptySqStack(S1)) {
		printf("����Ϊ��");
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
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnQueue(S1, S2, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭS1Ϊ��");
	PrintSqStack(S1); 
	printf("ԭS2Ϊ��");
	PrintSqStack(S2);
	// ȡ���Ӷ�Ԫ��
	x = DeQueue(S1, S2);
	printf("ȡ���Ӷ�Ԫ��%d���˳��ջΪ��", x);
	printf("����S1Ϊ��");
	PrintSqStack(S1);
	printf("����S2Ϊ��");
	PrintSqStack(S2);
	if (EmptyQueue(S1, S2))
		printf("��Ϊ��");
	else
		printf("�Ӳ�Ϊ��");
}