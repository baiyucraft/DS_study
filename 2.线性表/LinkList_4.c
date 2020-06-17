#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 删除最小值
void DelMinLinkList(LinkList* L) {
	// 遍历时的前驱结点pre和当前结点p
	LNode* pre = *L;
	LNode* p = (*L)->next;
	// 储存最小值的前驱结点minpre和最小值结点p
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
	printf("原链表为：");
	PrintLinkList(L);
	DelMinLinkList(&L);
	printf("删除最小值后的链表为：");
	PrintLinkList(L);
}