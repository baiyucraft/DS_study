#include <stdio.h>
#include "SqList.h"

/*������ʱ��o(n);�ռ�o(1)
1-ѡ����һ��Ԫ��Ϊ��ѡԪ��this����������this�ģ�count++����֮count--��
2-��count = 0ʱ����ʱ���ѱ�����k���е�k/2Ϊthis����ǰk���е�����Ԫ�س��ִ���<=k/2����������������ζ�ţ�ǰk���У�ĳһԪ�س��ֵĴ������ֻ��k/2��
3-ѡ��k+1��Ԫ��Ϊthis�����������ֱ�����l��Ԫ�أ�����������k+1��ʼ��l���У�ĳһԪ�س��ֵĴ������ֻ��l/2��
����������
�������������������
	��count=0����֪n���У�ĳһԪ��������n/2�Σ���������Ԫ��
	��count>0���������һ��ѡ��thisʱ��this���ֵĴ���>���һ�α���Ԫ����a/2��������������һ��ѡ��this֮ǰ����Ԫ�س��ִ�������ǰ(n-a)/2
		��ʱ��Ԫ�ؿ��ܴ��ڣ�����֤�Ƿ���ִ�������n/2
*/
// �ο���
ElemtType Majarity(SqList* L) {
	// count����
	int i, count = 1;
	// this��ʾ��ѡ��Ԫ��
	int this = L->data[0];
	// ����˳���
	for (i = 1; i < L->length; i++) {
		// �����i+1��Ԫ�ص���this��++
		if (L->data[i] == this)
			count++;
		// ������
		else {
			// ��֮ --
			if (count > 0) {
				count--;
			}
			// ����ѡ����ѡ��Ԫ��
			else {
				this = L->data[i];
				count = 1;
			}
		}
	}
	// ���count��Ϊ0���жϺ�ѡ��Ԫ���Ƿ�Ϊ��������Ԫ��
	if (count > 0) {
		count = 0;
		for (i = 0; i < L->length; i++) {
			if (L->data[i] == this) {
				count++;
			}
		}
	}
	return count > L->length / 2 ? this : -1;
}

void SolveSqlist_12() {
	ElemtType a[6] = { 1,5,5,3,5,2 };
	SqList L;
	InitSqList(&L);
	CreateSqList(&L, a, 6);
	printf("ԭ��");
	PrintSqList(&L);
	printf("��Ԫ�أ�");
	printf("%d", Majarity(&L));
}