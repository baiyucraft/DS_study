#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 从头至尾扫描单链表，pre指向当前结点p的前驱结点
void LinkListDelMinMax(LinkList* L, ElemtType min,ElemtType max) {
	// 当前结点p
	LNode* p = (*L)->next;
	// p的前驱结点pre
	LNode* pre = (*L);
	// 用来存放要删除的结点
	LNode* q;
	while (p != NULL) {
		// 如果当前结点p的数据符合条件
		if (p->data > min && p->data < max) {
			// 要删除结点q
			q = p;
			// 使当前结点p变成下一个结点
			p = p->next;
			// 要删除结点的前驱指针pre指向要删除结点的下一个结点，也就是现在的p
			pre->next = p;
			free(q);
		}
		else {
			// p的数据不符合，就将前驱结点和当前结点都往后移一个结点
			pre = p;
			p = p->next;
		}
	}
}

void SolveLinkList7() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("原链表为：");
	PrintLinkList(L);
	ElemtType min = 2;
	ElemtType max = 5;
	LinkListDelMinMax(&L, min, max);
	printf("删除%d与%d之间的数后的链表为：", min, max);
	PrintLinkList(L);
}