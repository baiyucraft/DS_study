#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1.���㷨��������ָ��p��q������pָ���ƶ�k����㣬��ʱ��p��q֮�����k�����
// 2.֮��p��qͬ���˶������Ե�p�˶�����βʱ��p��q֮����Ȼ���k����㣬��ʱq���Ϊ�����ҽ��
// ���ҵ�����k������
int SearchLinkListK(LinkList L, int k) {
	LNode* p = L->next;
	LNode* q = L->next;
	int count = 0;
	while (p != NULL) {
		// cout<k��ִ�е�һ��
		if (count < k)
			count++;
		// ��֮ͬ���ƶ�
		else
			q = q->next;
		p = p->next;
	}
	// ����˵��������k��������ʧ��
	if (count < k)
		return 0;
	else {
		printf("���ҵ��Ľ��Ϊ��%d", q->data);
		return 1;
	}
}

void SolveLinkList21() {
	LinkList L;
	TailInsertLinkList(L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	SearchLinkListK(L, 2);
}