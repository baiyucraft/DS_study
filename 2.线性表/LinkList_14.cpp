#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 将递增的L1、L2链表的公共结点放入L3
LinkList GetLinkListCom(LinkList L1, LinkList L2) {
	// L1、L2的工作指针p1，p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	// 新的链表L3
	LinkList L3 = (LinkList)malloc(sizeof(LNode));
	// L3的尾指针r
	LNode* r = L3;
	// L3的新结点s
	LNode* s;
	// 遍历两个链表，p1>p2，p1下一个结点；p1<p2，p2下一个结点；p1=p2，放入L3
	while (p1 && p2) {
		if (p1->data < p2->data)
			p1 = p1->next;
		else if (p1->data > p2->data)
			p2 = p2->next;
		else {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	r->next = NULL;
	return L3;
}

void SolveLinkList14() {
	LinkList L1, L2;
	printf("请输入链表L1：\n");
	TailInsertLinkList(L1);
	printf("请输入链表L2：\n");
	TailInsertLinkList(L2);
	printf("L1为：");
	PrintLinkList(L1);
	printf("L2为：");
	PrintLinkList(L2);
	LinkList L3 = GetLinkListCom(L1, L2);
	printf("公共结点为：");
	PrintLinkList(L3);	
}