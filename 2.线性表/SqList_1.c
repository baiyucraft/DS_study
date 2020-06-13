#include <stdio.h>
#include "SqList.h"
//
int DelMin(SqList* L, ElemtType* e) {
	if (L->length == 0) {
		printf("表为空");
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

void SolveSqlist_1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 5);
	ElemtType x;
	DelMin(&L, &x);
	PrintSqList(&L);
	printf("最小是%d；", x);
	PrintSqList(&L);
}
