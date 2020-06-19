#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ��ͷ��βɨ�赥����preָ��ǰ���p��ǰ�����
void LinkListDelMinMax(LinkList* L, ElemtType min,ElemtType max) {
	// ��ǰ���p
	LNode* p = (*L)->next;
	// p��ǰ�����pre
	LNode* pre = (*L);
	// �������Ҫɾ���Ľ��
	LNode* q;
	while (p != NULL) {
		// �����ǰ���p�����ݷ�������
		if (p->data > min && p->data < max) {
			// Ҫɾ�����q
			q = p;
			// ʹ��ǰ���p�����һ�����
			p = p->next;
			// Ҫɾ������ǰ��ָ��preָ��Ҫɾ��������һ����㣬Ҳ�������ڵ�p
			pre->next = p;
			free(q);
		}
		else {
			// p�����ݲ����ϣ��ͽ�ǰ�����͵�ǰ��㶼������һ�����
			pre = p;
			p = p->next;
		}
	}
}

void SolveLinkList7() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	ElemtType min = 2;
	ElemtType max = 5;
	LinkListDelMinMax(&L, min, max);
	printf("ɾ��%d��%d֮������������Ϊ��", min, max);
	PrintLinkList(L);
}