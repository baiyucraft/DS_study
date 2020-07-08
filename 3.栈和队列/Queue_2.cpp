#include <stdio.h>
#include "SqQueue.h"
#include "SqStack.h"

// ��ջ�������е�Ԫ������
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
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		EnCriSqQueue(Q, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳���Ϊ��");
	PrintCriSqQueue(Q);
	InverserSqQueue(Q);
	printf("���ú��˳���Ϊ��");
	PrintCriSqQueue(Q);
}