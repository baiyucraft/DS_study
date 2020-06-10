#include <stdio.h>
#include "SqList.h"

int DelMin(SqList* L, ElemtType* e) {
	if (L->length == 0) {
		printf("��Ϊ��");
		return 0;
	}
	*e = L->data[0];
	int pos = 0;
	for (int i = 1; i < L->length; i++) {
		if (L->data[i] < *e) {
			pos = i;
			*e = L->data[i];
		}
	}
	L->data[pos] = L->data[L->length - 1];
	L->length--;
	return 1;
}

void Solve1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 5);
	ElemtType x;
	DelMin(&L, &x);
	PrintList(&L);
	printf("��С��%d��", x);
	PrintList(&L);
}
