#include <stdio.h>
#include "LinkList.h"

// �ı���������
void ChangeLinkList(LinkList& L) {
	// p��qΪ������㣬�������r������ǰ��ν��s
	LNode* p, * q, * r, * s;
	p = q = L;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		// q������
		if (q->next != NULL)
			q = q->next;
	}
	// ����������pָ���м��㡢qָ�����������׽��
	// qָ����ν��ĵ�һ�����
	q = p->next;
	// ��p֮��ĺ������ã�����ͷ�巨
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	// ���������������������
	s = L->next;
	q = p->next;
	// p���������β���
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = s->next; 
		s->next = q;
		s = q->next;
		q = r;
	}
}

void SolveLinkList25() {
	LinkList L;
	TailInsertLinkList(L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	ChangeLinkList(L);
	printf("�ı�������Ϊ��");
	PrintLinkList(L);
}