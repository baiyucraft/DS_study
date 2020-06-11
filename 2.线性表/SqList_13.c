#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqList.h"

ElemtType FindMissMin(SqList* L) {
	int i;
	ElemtType* Temp;
	Temp = (ElemtType*)malloc(sizeof(ElemtType) * L->length);
	memset(Temp, 0, sizeof(ElemtType) * L->length);
	for (i = 0; i < L->length; i++) {
		if (L->data[i] > 0 && L->data[i] <= L->length) {
			Temp[L->data[i] - 1] = 1;
		}
	}
	for (i = 0; i <= L->length; i++) {
		if (i == L->length) {
			break;
		}
		else if (Temp[i] == 0) {
			break;
		}
	}
	return i + 1;
}

void SolveSqlist_13() {
	ElemtType a[6] = { 1,2,3,4,5,6 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 6);
	printf("原表：");
	PrintList(&L);
	printf("最小正整数为：");
	printf("%d", FindMissMin(&L));
}