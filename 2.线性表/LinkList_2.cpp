#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ��ͷ��βɨ�赥����preָ��ǰ���p��ǰ�����
void LinkList_DelX3(LinkList& L, ElemtType x) {
	// ��ǰ���p
	LNode* p = L->next;
	// p��ǰ�����pre
	LNode* pre = L;
	// �������Ҫɾ���Ľ��
	LNode* q;
	while (p != NULL){
		// �����ǰ���p������Ϊx
		if (p->data == x) {
			// Ҫɾ�����q
			q = p;
			// ʹ��ǰ���p�����һ�����
			p = p->next;
			// Ҫɾ������ǰ��ָ��preָ��Ҫɾ��������һ����㣬Ҳ�������ڵ�p
			pre->next = p;
			free(q);
		}
		else {
			// p�����ݲ�����x���ͽ�ǰ�����͵�ǰ��㶼������һ�����
			pre = p;
			p = p->next;
		}
	}
}
// ��pָ��ɨ�����н�㣬��ֵ����x���ͷţ�������x�����ӵ�L֮��
void LinkList_DelX4(LinkList& L, ElemtType x) {
	// ��ǰ���p
	LNode* p = L->next;
	// L��β���r����ֵΪͷ���
	LNode* r = L;
	// Ҫɾ�����q
	LNode* q;
	while (p != NULL) {
		// ���p�����ݲ�����x
		if (p->data != x) {
			// β���r����һ�����Ϊ��ǰ���p
			r->next = p;
			// β���r����µ�β���
			r = p;
			// ʹ��ǰ���p�����һ�����
			p = p->next;
		}
		else {
			// Ҫɾ�����q
			q = p;
			// ʹ��ǰ���p�����һ�����
			p = p->next; 
			free(q);
		}
	}
	// β���r����һ�����ΪNULL
	r->next = NULL;
}
void SolveLinkList2() {
	LinkList L;
	TailInsertLinkList(L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	ElemtType x;
	printf("������Ҫɾ��������");
	scanf("%d", &x);
	LinkList_DelX3(L, x);
	printf("ɾ������%d�������Ϊ��", x);
	PrintLinkList(L);
	printf("������Ҫɾ��������");
	scanf("%d", &x);
	LinkList_DelX4(L, x);
	printf("ɾ������%d�������Ϊ��", x);
	PrintLinkList(L);
}
