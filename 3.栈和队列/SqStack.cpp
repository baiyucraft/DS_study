#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// 1.��ʼ��ջ
void InitSqStack(SqStack& S) {
	S.top = -1;
}
// 2.��ջ
bool PushSqStack(SqStack& S, ElemtType x) {
	if (S.top == MaxSize - 1) {
		printf("ջ����");
		return false;
	}
	S.data[++S.top] = x;
	return true;
}
// 3.��ջ
ElemtType PopSqStack(SqStack& S) {
	if (S.top == -1) {
		printf("ջ�ѿ�");
		return NULL;
	}
	return S.data[S.top--];
}
// 4.��ջ��
bool EmptySqStack(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.��ջ��Ԫ��
ElemtType GetTopSqStack(SqStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return NULL;
	}
	return S.data[S.top];
}
// 6.��ӡ��ǰջ
void PrintSqStack(SqStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return;
	}
	printf("ջ��-");
	for (int i = S.top; i >= 0; i--) {
		printf("%d-", S.data[i]);
	}
	printf("ջ��\n");
}
// 7.����ջ��û��̬����ռ䣬���У�
bool DestroySqStack(SqStack& S) {
	free(&S);
	return true;
}

void MainSqStack() {
	SqStack S;
	// ��ʼ��ջ
	InitSqStack(S);
	ElemtType x;
	// ��ջ�����Ԫ��
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		PushSqStack(S, x);
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	printf("ԭ˳��ջΪ��");
	PrintSqStack(S);
	// ȡ��ջ��Ԫ��
	x = PopSqStack(S);
	printf("ȡ��ջ��Ԫ��%d���˳��ջΪ��", x);
	PrintSqStack(S);
	// ��ջ��Ԫ��
	printf("��ʱ��ջ��Ԫ��Ϊ��%d\n", GetTopSqStack(S));
	// ջ�п�
	if (EmptySqStack(S))
		printf("ջΪ��");
	else
		printf("ջ��Ϊ��");
}
