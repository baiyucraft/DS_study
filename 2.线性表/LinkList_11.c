#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ������A��Ϊ��������A�����ú��ż������B
LinkList DisCreateLinkList2(LinkList* A) {
	// ������
	//int i = 0;
	// ������ֵĵڶ�������
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	// B��β���ָ��ָ��ͷ���
	LNode* ra = *A;
	// ����A�Ĺ������p
	LNode* p = (*A)->next;
	// ����
	(*A)->next = NULL;
	// q�洢ż�����
	LNode* q;
	// ����ԭ����
	while (p != NULL) {
		// ��������㴦��
		ra->next = p;
		ra = p;
		p = p->next;
		// ��ż�����Ĵ���
		if (p != NULL) {
			// q��ż����㹤��
			q = p;
			p = p->next;
		}
		// ǰ��
		q->next = B->next;
		B->next = q;
	}
	ra->next = NULL;
	return B;
}

void SolveLinkList11() {
	LinkList A;
	TailInsertLinkList(&A);
	printf("ԭ����Ϊ��");
	PrintLinkList(A);
	LinkList B = DisCreateLinkList2(&A);
	printf("��������Ϊ��");
	PrintLinkList(A);
	printf("ż������Ϊ��");
	PrintLinkList(B);
}