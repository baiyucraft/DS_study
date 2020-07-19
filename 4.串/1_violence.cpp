#include <stdio.h>
#include "ThisString.h"

int IndexSTrVio(SString S, SString T) {
	int i = 1;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i + j - 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}

void SolveindexVio() {
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
	int index = IndexSTr(S, T);
	if (index == 0)
		printf("����S��δ�ҵ���ģʽ��T��ͬ���Ӵ�\n");
	else
		printf("ģʽ��T������S�е�һ�γ����ڵ�%d���ַ�\n", index);
}