#include <stdio.h>
#include "SqList.h"

// 将顺序表L的第left元素开始到第right元素逆置
void Reverse(SqList* L, int left, int right) {
	if (left<1 || right>L->length || left >= right)
		return;
	int mid = (left + right) / 2;
	ElemtType temp;
	// 将第left+i个元素与第right-i个元素互换
	for (int i = 0; i < mid - left; i++) {
		temp = L->data[left + i - 1];
		L->data[left + i - 1] = L->data[right - i - 1];
		L->data[right - i - 1] = temp;
	}
}
// 将前m项和后n项分别逆置
void ReverseMN(SqList* L, int m, int n) {
	Reverse(L, 1, L->length);
	Reverse(L, 1, n);
	Reverse(L, n+1, m+n);
}

void SolveSqlist_8() {
	ElemtType a[13] = { 1,2,3,5,6,7,9,12,46,50,57,59,65 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 13);
	printf("原表：");
	PrintSqList(&L);
	ReverseMN(&L, 5, 8);
	printf("逆置后：");
	PrintSqList(&L);
}