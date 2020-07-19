#include <stdio.h>
#include "ThisString.h"

int IndexSTrKMP(SString S, SString T, int next[]) {
	int i = 1;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
		if (j > T.length)
			return i - T.length;
		else
			return 0;
	}
}
void SolveindexKMP() {
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
	int index = IndexSTrKMP(S, T);
	if (index == 0)
		printf("����S��δ�ҵ���ģʽ��T��ͬ���Ӵ�\n");
	else
		printf("ģʽ��T������S�е�һ�γ����ڵ�%d���ַ�\n", index);
}