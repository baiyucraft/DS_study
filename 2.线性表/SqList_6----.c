#include <stdio.h>
#include "SqList.h"

// ˼�����ȥ����������ظ�Ԫ�أ�hash��
int DelSame(SqList* L) {
	if (L->length == 0)
		return 0;
	// i�洢��һ������ͬ��Ԫ�أ�j������
	int i = 0, j = 1;
	for (; j < L->length; j++) {
		if (L->data[i] != L->data[j])
			L->data[++i] = L->data[j];
	}
	L->length = i + 1;
	return 1;
}

void SolveSqlist_6() {
	ElemtType a[11] = { 1,2,2,2,2,3,3,3,4,4,5 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 11);
	printf("ԭ��");
	PrintSqList(&L);
	DelSame(&L);
	printf("�ֱ�1��");
	PrintSqList(&L);
}