#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1.���������ĵ�����
void CreateRingLinkList(LinkList& L) {
	ElemtType x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// �������
	LNode* s;
	// ��ʼ������������ͷ���
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// βָ��rָ���β���
	LNode* r = L;
	for (int i = 0; i < 10; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x[i];
		r->next = s;
		r = s;
	}
	// ������ڵ��ĸ����
	r->next = L->next->next->next->next;
}

// 2.��ӡ�����ĵ�����
void PrintRingLinkList(LinkList L) {
	printf("ͷ���->");
	LNode* p = L->next;
	for (int i = 0; i < 10; i++) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

// ����Ƿ��л��������
LNode* FindLoopStart(LinkList L) {
	// ���ÿ�fast��slow����ָ��
	LNode* fast = L->next;
	LNode* slow = L->next;
	// ������㣬ֱ��slow����fast��ͷ����slow=fast(�����ڻ���������)
	while (slow != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow == NULL || fast->next == NULL)
		return NULL;
	// �ֱ�ָ��ʼ����������,�������������ʱ����Ϊ��ڵ�
	LNode* p1 = L->next;
	LNode* p2 = slow;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void SolveLinkList24() {
	LinkList L1, L2;
	CreateRingLinkList(L1);
	TailInsertLinkList(L2);
	printf("L1����Ϊ��");
	PrintRingLinkList(L1);
	if (FindLoopStart(L1)) {
		printf("L1���������Ϊ��%d\n", FindLoopStart(L1)->data);
	}
	else
		printf("L1������\n");
	printf("L2����Ϊ��");
	PrintLinkList(L2);
	if (FindLoopStart(L2)) {
		printf("L2���������Ϊ��%d\n", FindLoopStart(L2)->data);
	}
	else
		printf("L2������\n");
}