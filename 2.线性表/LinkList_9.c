#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ���������ɾ��
void LinkListDelMinP(LinkList* L) {
	// ��Сֵ����ǰ�����pre
	LNode* pre;
	// �����Ĺ������p
	LNode* p;
	// Ҫɾ���Ľ��
	LNode* q;
	while ((*L)->next != NULL) {
		pre = *L;
		p = pre->next;
		while (p->next != NULL) {
			if (p->next->data < pre->next->data) {
				pre = p;
			}
			p = p->next;
		}
		// ��ӡ��Сֵ���
		printf("%d->", pre->next->data);
		// ����ɾ�����
		q = pre->next;
		pre->next = q->next;
		free(q);
	}
	free(*L);
	printf("NULL\n�����ͷųɹ�");
}

void SolveLinkList9() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	printf("�����");
	LinkListDelMinP(&L);
}
