#include <stdio.h>
#include "SqList.h"

SqList Merge(SqList& L1, SqList& L2) {
	SqList L;
	InitSqList(L);
	if (L1.length + L2.length > MaxSize) {
		printf("超出长度");
		return L;
	}
	int i = 0, j = 0;
	while (i < L1.length && j < L2.length) {
		if (L1.data[i] <= L2.data[j]) {
			InsertSqList(L, L.length + 1, L1.data[i++]);
		}
		else {
			InsertSqList(L, L.length + 1, L2.data[j++]);
		}
	}
	while (i < L1.length)
		InsertSqList(L, L.length + 1, L1.data[i++]);
	while (j < L2.length)
		InsertSqList(L, L.length + 1, L2.data[j++]);
	return L;
}

void SolveSqlist_7() {
	ElemtType a[5] = { 1,2,5,7,9 };
	SqList L1;
	InitSqList(L1);
	CreateSqList(L1, a, 5);
	ElemtType b[5] = { 1,3,6,7,8 };
	SqList L2;
	InitSqList(L2);
	CreateSqList(L2, b, 5);
	printf("表1：");
	PrintSqList(L1);
	printf("表2：");
	PrintSqList(L2);
	SqList L = Merge(L1, L2);
	printf("合并后：");
	PrintSqList(L);
}