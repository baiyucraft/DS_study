#include <stdio.h>
#include "SqList.h"

// 思考如何去除无序表中重复元素（hash）
int DelSame(SqList* L) {
	if (L->length == 0)
		return 0;
	// i存储第一个不相同的元素，j遍历表
	int i = 0, j = 1;
	for (; j < L->length; j++) {
		if (L->data[i] != L->data[j])
			L->data[++i] = L->data[j];
	}
	L->length = i + 1;
	return 1;
}

void Solve6() {
	ElemtType a[11] = { 1,2,2,2,2,3,3,3,4,4,5 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 11);
	printf("原表：");
	PrintList(&L);
	DelSame(&L);
	printf("现表1：");
	PrintList(&L);
}