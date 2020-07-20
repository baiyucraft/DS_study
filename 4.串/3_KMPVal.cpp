#include <stdio.h>
#include <stdlib.h>
#include "ThisString.h"

void GetNextVal(SString T, int* nextval) {
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
	// ��ӡ
	i = 1;
	printf("nextval����Ϊ��");
	while (i <= T.length)
		printf("%d ", nextval[i++]);
	printf("\n");
}

int IndexSTrKMPVal(SString S, SString T) {
	int i = 1;
	int j = 1;
	// int next[T.length + 1];
	int* nextval;
	nextval = (int*)malloc(sizeof(int) * (T.length + 1));
	GetNextVal(T, nextval);
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else
			j = nextval[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}
void SolveindexKMPVal() {
	char stemp[255];
	// S
	SString S;
	printf("����������S��");
	InitTemp(stemp);
	AssignSTr(S, stemp);
	// T
	SString T;
	printf("������ģʽ��T��");
	InitTemp(stemp);
	AssignSTr(T, stemp);
	printf("����SΪ��");
	PrintSTr(S);
	printf("ģʽ��TΪ��");
	PrintSTr(T);
	// ��λ
	int index = IndexSTrKMPVal(S, T);
	if (index == 0)
		printf("����S��δ�ҵ���ģʽ��T��ͬ���Ӵ�\n");
	else
		printf("ģʽ��T������S�е�һ�γ����ڵ�%d���ַ�\n", index);
}