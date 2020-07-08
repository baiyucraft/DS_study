#include <stdio.h>
#include "SqStack.h"

// ��ջ��i����ջ��
bool PushSTK(STK& S, int i, ElemtType x) {
	if (i < 0 || i > 1) {
		printf("ջ�Ų���\n");
		return false;
	}
	if (S.top[1] - S.top[0] == 1) {
		printf("ջ����\n");
		return false;
	}
	switch (i) {
	case 0:S.stack[++S.top[0]] = x; return true;
	case 1:S.stack[--S.top[1]] = x; return true;
	}
}
// ��ջ��i����ջ��
ElemtType PopSTK(STK& S, int i) {
	if (i < 0 || i > 1) {
		printf("ջ�Ų���\n");
		return false;
	}
	switch (i) {
	case 0:
		if (S.top[0] == -1) {
			printf("ջ��\n");
			return NULL;
		}
		else
			return S.stack[S.top[0]--];
	case 1:
		if (S.top[1] == MaxS) {
			printf("ջ��\n");
			return NULL;
		}
		else 
			return S.stack[S.top[1]++];
	}
	return true;
}
// ��ӡ
void PrintSqStack(STK S) {
	int i;
	printf("���-");
	if (S.top[0] == -1) {
		printf("��һ��ջΪ��");
	}
	else {
		for (i = 0; i <= S.top[0]; i++) {
			printf("%d-", S.stack[i]);
		}
	}
	if (S.top[1] == MaxS) {
		printf("�ڶ���ջΪ��");
		printf("�ұ�\n");
	}
	else {
		printf("�м�-");
		for (i = S.top[1]; i < MaxS; i++) {
			printf("%d-", S.stack[i]);
		}
		printf("�ұ�\n");
	}
}

void SolveStack_5() {
	STK S;
	S.top[0] = -1;
	S.top[1] = MaxS;
	ElemtType x;
	int i;
	printf("��������(����9999����)��");
	scanf("%d %d", &i, &x);
	//printf("%d %d", i, x);
	while (x != 9999) {
		PushSTK(S, i, x);
		printf("��������(����9999����)��");
		scanf("%d %d", &i, &x);
	}
	printf("��Ϊ��");
	PrintSqStack(S);
	PopSTK(S, 0);
	printf("��һ��ջ��ջһ����Ϊ��");
	PrintSqStack(S);
	PopSTK(S, 1);
	printf("�ڶ���ջ��ջһ����Ϊ��");
	PrintSqStack(S);
}