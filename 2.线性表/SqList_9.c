#include <stdio.h>
#include "SqList.h"

void SearchX(SqList* L, ElemtType x) {
	int i = 0;
	// 顺序查找时间不是最少
	// for (; i < L->length && L->data[i] < x; i++);
	// 折半查找（时间最少）
	int low = 0, high = L->length - 1;
	while (low < high) {
		i = (low + high) / 2;
		if (L->data[i] == x) break;
		else if (L->data[i] < x)
			low = i + 1;
		else high = i - 1;
	}
	// 找到交换位置
	if (L->data[i] == x && i != L->length - 1) {
		int temp = L->data[i];
		L->data[i] = L->data[i + 1];
		L->data[i + 1] = temp;
	}
	// 反之加入
	else {
		InsertSqList(L, i + 1, x);
	}
}

void SolveSqlist_9() {
	ElemtType a[13] = { 1,2,3,5,6,7,9,12,46,50,57,59,65 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 13);
	printf("原表：");
	PrintSqList(&L);
	SearchX(&L, 59);
	printf("查找后：");
	PrintSqList(&L);
}