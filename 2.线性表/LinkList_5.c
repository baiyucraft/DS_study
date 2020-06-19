#include <stdio.h>
#include "LinkList.h"

// 摘下头结点，以第一个元素为起点，采用头插法重新插入建立链表
void ReverseLinkList1(LinkList* L) {
	// 定义工作结点p，用来遍历链表
	LNode* p = (*L)->next;
	// r用来存储p的后继结点
	LNode* r;
	// 断开头结点
	(*L)->next = NULL;
	// 遍历链表
	while (p != NULL) {
		// 储存p的后继结点r
		r = p->next;
		// p的后继结点为新建链表的第一个结点
		p->next = (*L)->next;
		// 头结点的下一个结点为p
		(*L)->next = p;
		// 继续遍历链表
		p = r;
	}
}
// 遍历链表，将每个结点的指针域反转，其中原第一个结点的指针域为NULL，头结点指向原表最后一个结点
void ReverseLinkList2(LinkList* L) {
	// 工作结点p
	LNode* p = (*L)->next;
	// p的前驱结点pre
	LNode* pre;
	// p的后继结点r
	LNode* r = p->next;
	// 处理第一个结点
	p->next = NULL;
	// p的后继结点不为空为条件
	while (r != NULL) {
		// 将p的后继结点r的指针域指向p
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	(*L)->next = p;
}
void SolveLinkList5() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("原链表为：");
	PrintLinkList(L);
	ReverseLinkList1(&L);
	printf("逆置后的链表为：");
	PrintLinkList(L);
	ReverseLinkList2(&L);
	printf("逆置后的链表为：");
	PrintLinkList(L);
}