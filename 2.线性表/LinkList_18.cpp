#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ������ѭ��������h2���ӵ�h1����
void LinkCriLinkList(LinkList& h1, LinkList& h2) {
	// �ֱ��ҵ�h1��h2��β���
	LNode* r1 = h1;
	while (r1->next != h1)
		r1 = r1->next;
	LNode* r2 = h2;
	while (r2->next != h2)
		r2 = r2->next;
	r1->next = h2->next;
	r2->next = h1;
	free(h2);
}

void SolveLinkList18() {
	LinkList L1, L2;
	printf("����������L1��\n");
	TailInsertCriLinkList(L1);
	printf("����������L2��\n");
	TailInsertCriLinkList(L2);
	printf("L1Ϊ��");
	PrintCriLinkList(L1);
	printf("L2Ϊ��");
	PrintCriLinkList(L2);
	LinkCriLinkList(L1, L2);
	printf("�ϲ���Ϊ��");
	PrintCriLinkList(L1);
}