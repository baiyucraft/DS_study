#include <stdint.h>
#include "SqList.h"

void SearchX(SqList* L, ElemtType x) {
	int i = 0;
	// ˳�����ʱ�䲻������
	//for (; i < L->length && L->data[i] < x; i++);
	// �۰���ң�ʱ�����٣�
	int low = 0, high = L->length - 1;
	while (low < high) {
		i = (low + high) / 2;
		if (L->data[i] == x) break;
		else if (L->data[i] < x)
			low = i + 1;
		else high = i - 1;
	}
	// �ҵ�����λ��
	if (L->data[i] == x && i != L->length - 1) {
		int temp = L->data[i];
		L->data[i] = L->data[i + 1];
		L->data[i + 1] = temp;
	}
	// ��֮����
	else {
		InsertList(L, i + 1, x);
	}
}

void Solve9() {
	ElemtType a[13] = { 1,2,3,5,6,7,9,12,46,50,57,59,65 };
	SqList L;
	InitSqList(&L);
	CreateList(&L, a, 13);
	printf("ԭ��");
	PrintList(&L);
	SearchX(&L, 59);
	printf("���Һ�");
	PrintList(&L);
}