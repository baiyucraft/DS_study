#include <stdio.h>
#include "SqList.h"

// ��˳���L�ĵ�leftԪ�ؿ�ʼ����rightԪ������
void Reverse(SqList* L, int left, int right) {
	if (left<1 || right>L->length || left >= right)
		return;
	int mid = (left + right) / 2;
	ElemtType temp;
	// ����left+i��Ԫ�����right-i��Ԫ�ػ���
	for (int i = 0; i < mid - left; i++) {
		temp = L->data[left + i - 1];
		L->data[left + i - 1] = L->data[right - i - 1];
		L->data[right - i - 1] = temp;
	}
}
// ��ǰm��ͺ�n��ֱ�����
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
	printf("ԭ��");
	PrintSqList(&L);
	ReverseMN(&L, 5, 8);
	printf("���ú�");
	PrintSqList(&L);
}