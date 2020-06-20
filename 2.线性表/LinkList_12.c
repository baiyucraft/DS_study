#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ɾ������������������ͬ��Ԫ��
void LinkListDelSame(LinkList* L) {
	// �������p
	LNode* p = (*L)->next;
	// Ҫɾ�����q
	LNode* q;
	// ��������
	if (p == NULL)
		return;
	// �������
	while (p->next != NULL) {
		q = p->next;
		// �Ƚ�p��p����һ���������ݣ�������ɾȥ��������һ�����
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

void SolveLinkList12() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	LinkListDelSame(&L);
	printf("ɾ���ظ��������Ϊ��");
	PrintLinkList(L);
}