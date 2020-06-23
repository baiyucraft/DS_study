#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ��L1��L2�������ͬ���L1�У��������ͷ�
void UnionLinkList(LinkList& L1, LinkList& L2) {
	// L1��L2�Ĺ���ָ��p1��p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	// �����Է���ͬ���
	L1->next = NULL;
	// �ϲ������βָ��
	LNode* r = L1;
	// Ҫɾ�����q
	LNode* q;
	// ������������p1>p2��p1��һ����㣻p1<p2��p2��һ����㣻p1=p2������L3
	while (p1 && p2) {
		if (p1->data < p2->data) {
			q = p1;
			p1 = p1->next;
			free(q);
		}
		else if (p1->data > p2->data) {
			q = p2;
			p2 = p2->next;
			free(q);
		}
		else {
			// ���ý��
			r->next = p1;
			r = p1;
			p1 = p1->next;
			// �ͷ���һ�����
			q = p2;
			p2 = p2->next;
			free(q);
		}
	}
	// ���ʣ�µ�
	while (p1) {
		q = p1;
		p1 = p1->next;
		free(q);
	}
	while (p2) {
		q = p2;
		p2 = p2->next;
		free(q);
	}
	r->next = NULL;
	free(L2);
}

void SolveLinkList15() {
	LinkList L1, L2;
	printf("����������L1��\n");
	TailInsertLinkList(L1);
	printf("����������L2��\n");
	TailInsertLinkList(L2);
	printf("L1Ϊ��");
	PrintLinkList(L1);
	printf("L2Ϊ��");
	PrintLinkList(L2);
	UnionLinkList(L1, L2);
	printf("�������Ϊ��");
	PrintLinkList(L1);
}