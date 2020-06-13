#include <stdio.h>
#include "SqList.h"

// �Լ�д��
int DelS_T1(SqList* L, ElemtType s, ElemtType t) {
	if (s >= t) {
		printf("�����s��t���Ϸ�");
		return 0;
	}
	if (L->length == 0) {
		printf("˳���Ϊ��");
		return 0;
	}
	int k = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] > s && L->data[i] < t) {
			k++;
		}
		else {
			L->data[i - k] = L->data[i];
		}
	}
	if (k == 0) {
		printf("δ�ҵ�");
		return 0;
	}
	L->length -= k;
	return 1;
}
// ��д��
int DelS_T2(SqList* L, ElemtType s, ElemtType t) {
	if (s >= t) {
		printf("�����s��t���Ϸ�");
		return 0;
	}
	if (L->length == 0) {
		printf("˳���Ϊ��");
		return 0;
	}
	int i = 0, j = 0;
	for (; i < L->length && L->data[i] < s; i++);
	if (i >= L->length) {
		printf("δ�ҵ�");
		return 0;
	}
	for (j = i; j < L->length && L->data[j] <= t; j++);
	for (; j < L->length; j++, i++) {
		L->data[i] = L->data[j];
	}
	L->length = i;
	return 1;
}

void SolveSqlist_4() {
	ElemtType a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 10);
	printf("ԭ��");
	PrintSqList(&L);
	DelS_T1(&L, 4, 6);
	printf("�ֱ�1��");
	PrintSqList(&L);
	DelS_T2(&L, 3, 7);
	printf("�ֱ�2��");
	PrintSqList(&L);
}