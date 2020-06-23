#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 将两个循环单链表h2连接到h1后面
void LinkCriLinkList(LinkList& h1, LinkList& h2) {
	// 分别找到h1、h2的尾结点
	LNode* r1 = h1;
	while (r1->next != h1)
		r1 = r1->next;
	LNode* r2 = h2;
	while (r2->next != h2)
		r2 = r2->next;
	r1->next = h2->next;
	r2->next = h1;
	free(h2);
}

void SolveLinkList18() {
	LinkList L1, L2;
	printf("请输入链表L1：\n");
	TailInsertCriLinkList(L1);
	printf("请输入链表L2：\n");
	TailInsertCriLinkList(L2);
	printf("L1为：");
	PrintCriLinkList(L1);
	printf("L2为：");
	PrintCriLinkList(L2);
	LinkCriLinkList(L1, L2);
	printf("合并后为：");
	PrintCriLinkList(L1);
}