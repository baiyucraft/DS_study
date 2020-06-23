#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// �ϲ�������������ĵ�����L1��L2���ϲ��ɵݼ�������ͷ�巨��
void MergeLinkList(LinkList& L1, LinkList& L2) {
	// �ݴ���������һ�����
	LNode* r;
	// L1�Ĺ������p1
	LNode* p1 = L1->next;
	// L2�Ĺ������p2
	LNode* p2 = L2->next;
	// ��L1���������洢��L1��ͷ�����
	L1->next = NULL;
	// �����������жϴ�С��ͷ��
	while (p1 && p2) {
		if (p1->data <= p2->data) {
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}
		else {
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}
	// ��δ������������p2
	if (p1)
		p2 = p1;
	while (p2) {
		r = p2->next;
		p2->next = L1->next;
		L1->next = p2;
		p2 = r;
	}
	free(L2);
}

void SolveLinkList13() {
	LinkList L1, L2;
	printf("����������L1��\n");
	TailInsertLinkList(L1);
	printf("����������L2��\n");
	TailInsertLinkList(L2);
	printf("L1Ϊ��");
	PrintLinkList(L1);
	printf("L2Ϊ��");
	PrintLinkList(L2);
	MergeLinkList(L1, L2);
	printf("�ϲ���Ϊ��");
	PrintLinkList(L1);
}