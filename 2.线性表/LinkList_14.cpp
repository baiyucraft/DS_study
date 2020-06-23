#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ��������L1��L2����Ĺ���������L3
LinkList GetLinkListCom(LinkList L1, LinkList L2) {
	// L1��L2�Ĺ���ָ��p1��p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	// �µ�����L3
	LinkList L3 = (LinkList)malloc(sizeof(LNode));
	// L3��βָ��r
	LNode* r = L3;
	// L3���½��s
	LNode* s;
	// ������������p1>p2��p1��һ����㣻p1<p2��p2��һ����㣻p1=p2������L3
	while (p1 && p2) {
		if (p1->data < p2->data)
			p1 = p1->next;
		else if (p1->data > p2->data)
			p2 = p2->next;
		else {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	r->next = NULL;
	return L3;
}

void SolveLinkList14() {
	LinkList L1, L2;
	printf("����������L1��\n");
	TailInsertLinkList(L1);
	printf("����������L2��\n");
	TailInsertLinkList(L2);
	printf("L1Ϊ��");
	PrintLinkList(L1);
	printf("L2Ϊ��");
	PrintLinkList(L2);
	LinkList L3 = GetLinkListCom(L1, L2);
	printf("�������Ϊ��");
	PrintLinkList(L3);	
}