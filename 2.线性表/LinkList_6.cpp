#include <stdio.h>
#include "LinkList.h"

// 用直接插入排序，遍历结点并插入
void SortLinkList(LinkList& L) {
	// 取头结点与第一个结点构成新链表
	LNode* p = L->next;
	// 保存p的后继结点，防止断链
	LNode* r = p->next;
	// 寻找新链表中要插入的前驱解=结点pre
	LNode* pre;
	// 成新链表
	p->next = NULL;
	// p指向第二个结点开始遍历
	p = r;
	while (p != NULL) {
		// 保存p的后继结点
		r = p->next;
		pre = L;
		// 用pre开始遍历新链表，pre的下一个结点为空，或pre的下一个结点的数据域 ≥ p的数据域时停止循环
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		// 插入结点在pre之后
		p->next = pre->next;
		pre->next = p;
		// 继续下一个结点开始遍历
		p = r;
	}
}

void SolveLinkList6() {
	LinkList L;
	TailInsertLinkList(L);
	printf("原链表为：");
	PrintLinkList(L);
	SortLinkList(L);
	printf("排序后的链表为：");
	PrintLinkList(L);
}