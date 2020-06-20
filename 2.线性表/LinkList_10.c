#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ������A��Ϊ��������A��ż������B
LinkList DisCreateLinkList1(LinkList* A) {
	// ������
	int i = 0;
	// ������ֵĵڶ�������
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	// AB��β���ָ��ָ��ͷ���
	LNode* ra = *A;
	LNode* rb = B;
	// ����A�Ĺ������p
	LNode* p = (*A)->next;
	// ����
	(*A)->next = NULL;
	// ����ԭ����
	while (p != NULL) {
		// ż����b
		if (++i % 2 == 0) {
			rb->next = p;
			rb = p;
		}
		// ������a
		else {
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}

void SolveLinkList10() {
	LinkList A;
	TailInsertLinkList(&A);
	printf("ԭ����Ϊ��");
	PrintLinkList(A);
	LinkList B = DisCreateLinkList1(&A);
	printf("��������Ϊ��");
	PrintLinkList(A);
	printf("ż������Ϊ��");
	PrintLinkList(B);
}