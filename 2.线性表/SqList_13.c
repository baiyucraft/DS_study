#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqList.h"
/*������ ʱ��o(n)���ռ�o(n)
��ĿҪ��ʱ�����㹻��Ч���ʲ�ȡ�ռ任ʱ�������
������
1-����һ��n�������Temp���ֱ����1��2��3������n��������>��a[i]������i+1������������>��ÿһ���ֵ0
2-������ֻҪ��1��2��3������n�������ֹ�һ�Σ�Temp�ж�Ӧ���ֵ��Ϊ1
	����˼�����������Ԫ��С��1���ߴ���n������û�б�ʾ����
		����> ��Ϊ��Ŀ��ֻҪ����С�������� ����>��˳�����ǡ����1��2��3������n������СΪn+1��
									  ��˳�������һ���1-n�еģ������i��ǲ���ȱ��Ԫ����ɶ����С���������ǵ�i��
3-��������Temp��ȡ��СTemp[i]=0��ֵ��
*/
ElemtType FindMissMin(SqList* L) {
	int i;
	ElemtType* Temp;
	// ���������鶯̬����ռ�
	Temp = (ElemtType*)malloc(sizeof(ElemtType) * L->length);
	// ������ռ��е�ÿ���ֽڸ�ֵΪ0��������൱�ڸ�ֵΪ0
	memset(Temp, 0, sizeof(ElemtType) * L->length);
	// �������ҵ��Ƿ�����1-n����
	for (i = 0; i < L->length; i++) {
		if (L->data[i] > 0 && L->data[i] <= L->length) {
			Temp[L->data[i] - 1] = 1;
		}
	}
	// �ҵ���С������
	for (i = 0; i < L->length; i++) {
		if (Temp[i] == 0)
			break;
	}
	return i + 1;
}

void SolveSqlist_13() {
	ElemtType a[6] = { 1,2,3,4,5,6 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 6);
	printf("ԭ��");
	PrintSqList(&L);
	printf("��С������Ϊ��");
	printf("%d", FindMissMin(&L));
}