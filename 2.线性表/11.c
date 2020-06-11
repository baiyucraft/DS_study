#include <stdio.h>
#include "SqList.h"

// �ռ��ϲ���Ч���ϲ�Ȼ������λ����ʱ��o��n�����ռ�o��2n��
ElemtType MidNum(SqList* L1, SqList* L2) {
	SqList L = Merge(L1, L2);
	PrintList(&L);
	return L.data[(L.length / 2) - 1];
}
// �ֱ�ȡ��λ���Ƚϣ��ռ��Ч��--����� ʱ��o��log2 n�����ռ�o��1��
ElemtType MidNum2(SqList* L1, SqList* L2) {
	if (L1->length != L2->length) {
		printf("������һ����");
		return;
	}
	// �ֱ��ʾL1��L2�ĵ�һ��Ԫ�أ����һ��Ԫ�أ���λ��
	int first1 = 0, after1 = L1->length - 1, mid1;
	int first2 = 0, after2 = L2->length - 1, mid2;
	// ֱ����βԪ��ָ���Ϊͬһ����L1��L2��ֻʣһ��Ԫ�أ�����ֵȡ��С��Ԫ��
	while (first1 != after1 || first2 != after2) {
		mid1 = (first1 + after1) / 2;
		mid2 = (first2 + after2) / 2;
		// ���L1����λ����L2����λ����ȣ����ظ�ֵ
		if (L1->data[mid1] == L2->data[mid2]) {
			return L1->data[mid1];
		}
		// ���L1����λ�� < L2����λ��������L1��ǰ�벿�֣�L2�ĺ�벿�֣�����Ҫ��֤����������ȣ�
		if (L1->data[mid1] < L2->data[mid2]) {
			// ������Ϊ��������λ������Ԫ����ȣ�����ǰ�󼴿�
			if ((first1 + after1) % 2 == 0) {
				first1 = mid1;
				after2 = mid2;
			}
			// ������Ϊż������λ�����Ԫ�ر��ұ�Ԫ����һ������L1��������һ��
			else {
				first1 = mid1 + 1;
				after2 = mid2;
			}
		}
		// ���L1����λ�� > L2����λ��������L1�ĺ�벿�֣�L2��ǰ�벿�֣�����Ҫ��֤����������ȣ�
		else {
			// ������Ϊ��������λ������Ԫ����ȣ�����ǰ�󼴿�
			if ((first1 + after1) % 2 == 0) {
				after1 = mid1;
				first2 = mid2;
			}
			// ������Ϊż������λ�����Ԫ�ر��ұ�Ԫ����һ������L2��������һ��
			else {
				after1 = mid1;
				first2 = mid2 + 1;
			}
		}
	}
	// ���ؽ�С�ģ���Ϊ����˳���ĺ�Ϊż������ȡС�ģ�
	return L1->data[first1] < L2->data[first2] ? L1->data[first1] : L2->data[first2];
}

/*
������
1���ֱ���L1��L2����λ��a��b�����Ƚϴ�С
	1-��a=b����a��bΪ������λ�����㷨����
	2-��a<b������L1��ǰ��Σ�L2�еĺ��Σ���Ҫ��֤��������������ȣ�����ΪL1��ǰ��α�aС��L2�к��α�b��
	3-��a>b������L1�к��Σ�L2�е�ǰ��Σ���Ҫ��֤��������������ȣ�����ΪL1�к��α�a��L2��ǰ��α�bС
2���ظ��������裬ֱ��L1��L2��ֻʣһ��Ԫ�أ���СΪ��λ������Ϊ����˳���ĺ�Ϊż������ȡС�ģ�

�ֽ⣺
1��L1��[1,2,5,7,9],L2��[1,3,6,7,8]��������first1=0��after1=4��first2=0��after2=4��������mid1��2��5����mid2��2��6����������Ϊ��λ����5<6
2��L1��[5,7,9],L2��[1,3,6]��������first1=2��after1=4��first2=0��after2=2��������mid1��3��7����mid2��1��3����������Ϊ��λ����7>3
3��L1��[5,7],L2��[3,6]��������first1=2��after1=3��first2=1��after2=2��������mid1��2��5����mid2��1��3����������Ϊ��λ����5>3
3��L1��[5],L2��[6]��������first1=2��after1=2��first2=2��after2=2������������ѭ��ֹͣ��5
*/




void Solve11() {
	ElemtType a[5] = { 1,2,5,7,9 };
	SqList L1;
	InitSqList(&L1);
	CreateList(&L1, a, 5);
	ElemtType b[5] = { 1,3,6,7,8 };
	SqList L2;
	InitSqList(&L2);
	CreateList(&L2, b, 5);
	printf("��1��");
	PrintList(&L1);
	printf("��2��");
	PrintList(&L2);
	printf("��λ����");
	printf("%d", MidNum2(&L1, &L2));
}