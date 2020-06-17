#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ɾ����Сֵ
void DelMinLinkList(LinkList* L) {
	// ����ʱ��ǰ�����pre�͵�ǰ���p
	LNode* pre = *L;
	LNode* p = (*L)->next;
	// ������Сֵ��ǰ�����minpre����Сֵ���p
	LNode* minpre = pre;
	LNode* minp = p;
	while (p != NULL) {
		if (p->data < minp->data) {
			minpre = pre;
			minp = p;
		}
		p = p->next;
		pre = pre->next;
	}
	minpre->next = minp->next;
	free(minp);
}

void SolveLinkList4() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	DelMinLinkList(&L);
	printf("ɾ����Сֵ�������Ϊ��");
	PrintLinkList(L);
}