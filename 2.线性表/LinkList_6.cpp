#include <stdio.h>
#include "LinkList.h"

// ��ֱ�Ӳ������򣬱�����㲢����
void SortLinkList(LinkList& L) {
	// ȡͷ������һ����㹹��������
	LNode* p = L->next;
	// ����p�ĺ�̽�㣬��ֹ����
	LNode* r = p->next;
	// Ѱ����������Ҫ�����ǰ����=���pre
	LNode* pre;
	// ��������
	p->next = NULL;
	// pָ��ڶ�����㿪ʼ����
	p = r;
	while (p != NULL) {
		// ����p�ĺ�̽��
		r = p->next;
		pre = L;
		// ��pre��ʼ����������pre����һ�����Ϊ�գ���pre����һ������������ �� p��������ʱֹͣѭ��
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		// ��������pre֮��
		p->next = pre->next;
		pre->next = p;
		// ������һ����㿪ʼ����
		p = r;
	}
}

void SolveLinkList6() {
	LinkList L;
	TailInsertLinkList(L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	SortLinkList(L);
	printf("����������Ϊ��");
	PrintLinkList(L);
}