#include <stdio.h>
#include "SqList.h"

// 思考如何去除无序表中重复元素（hash）
bool DelSame(SqList& L) {
	if (L.length == 0)
		return false;
	// i存储第一个不相同的元素，j遍历表
	int i = 0, j = 1;
	for (; j < L.length; j++) {
		if (L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	}
	L.length = i + 1;
	return 1;
}

void SolveSqlist_6() {
	ElemtType a[11] = { 1,2,2,2,2,3,3,3,4,4,5 };
	SqList L;
	InitSqList(L);
	CreateSqList(L, a, 11);
	printf("原表：");
	PrintSqList(L);
	DelSame(L);
	printf("现表1：");
	PrintSqList(L);
}