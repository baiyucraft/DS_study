#include <stdio.h>
#include "SqList.h"
//
void Inversion(SqList* L){
	ElemtType temp;
	for (int i = 0; i < L->length / 2; i++) {
		temp = L->data[i];
		L->data[i] = L->data[L->length - 1 - i];
		L->data[L->length - 1 - i] = temp;
	}
}

void Solve2() {
	ElemtType a[5] = { 2,3,5,4,1 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 5);
	printf("ԭ��");
	PrintList(&L);
	Inversion(&L);
	printf("�ֱ�");
	PrintList(&L);
}