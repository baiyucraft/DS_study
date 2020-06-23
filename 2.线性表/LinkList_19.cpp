#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 遍历循环单链表，每次删除最小值结点并输出
void DelAllMinCriLinkList(LinkList& L) {
	// 工作结点p，工作结点前驱pre，最小值结点minp，最小值结点前驱minpre
	LNode* p, * pre, * minp, * minpre;
	// 循环直到链表为空
	while (L->next != L) {
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while (p != L) {
			// 比较数据
			if (p->data < minp->data) {
				minp = p;
				minpre = pre;
			}
			// 查找下一个结点
			pre = p;
			p = p->next;
		}
		// 删除结点
		printf("%d->", minp->data);
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}

void SolveLinkList19() {
	LinkList L;
	TailInsertCriLinkList(L);
	printf("原链表为：");
	PrintCriLinkList(L);
	printf("按最小值输出为：");
	DelAllMinCriLinkList(L);
}