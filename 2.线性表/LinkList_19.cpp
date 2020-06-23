#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// ����ѭ��������ÿ��ɾ����Сֵ��㲢���
void DelAllMinCriLinkList(LinkList& L) {
	// �������p���������ǰ��pre����Сֵ���minp����Сֵ���ǰ��minpre
	LNode* p, * pre, * minp, * minpre;
	// ѭ��ֱ������Ϊ��
	while (L->next != L) {
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while (p != L) {
			// �Ƚ�����
			if (p->data < minp->data) {
				minp = p;
				minpre = pre;
			}
			// ������һ�����
			pre = p;
			p = p->next;
		}
		// ɾ�����
		printf("%d->", minp->data);
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}

void SolveLinkList19() {
	LinkList L;
	TailInsertCriLinkList(L);
	printf("ԭ����Ϊ��");
	PrintCriLinkList(L);
	printf("����Сֵ���Ϊ��");
	DelAllMinCriLinkList(L);
}