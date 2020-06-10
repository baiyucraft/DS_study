#include <stdio.h>
#include "SqList.h"

void DelX1(SqList* L, ElemtType x) {
	int k = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] != x) {
			L->data[k++] = L->data[i];
		}
	}
	L->length = k;
}

void DelX2(SqList* L, ElemtType x) {
	int k = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == x){
			k++;
		}
		else {
			L->data[i - k] = L->data[i];
		}
	}
	L->length = L->length - k;
}

void Solve3() {
	ElemtType a[10] = { 1,2,1,2,3,5,6,4,2,1 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 10);
	printf("原表：");
	PrintList(&L);
	printf("现表1：");
	DelX1(&L, 1);
	PrintList(&L);
	printf("现表2：");
	DelX2(&L, 2);
	PrintList(&L);
}