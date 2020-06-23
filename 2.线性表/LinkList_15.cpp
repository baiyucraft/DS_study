#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 将L1、L2链表的相同项放L1中，其余结点释放
void UnionLinkList(LinkList& L1, LinkList& L2) {
	// L1、L2的工作指针p1，p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	// 断链以放相同结点
	L1->next = NULL;
	// 合并链表的尾指针
	LNode* r = L1;
	// 要删除结点q
	LNode* q;
	// 遍历两个链表，p1>p2，p1下一个结点；p1<p2，p2下一个结点；p1=p2，放入L3
	while (p1 && p2) {
		if (p1->data < p2->data) {
			q = p1;
			p1 = p1->next;
			free(q);
		}
		else if (p1->data > p2->data) {
			q = p2;
			p2 = p2->next;
			free(q);
		}
		else {
			// 放置结点
			r->next = p1;
			r = p1;
			p1 = p1->next;
			// 释放另一个结点
			q = p2;
			p2 = p2->next;
			free(q);
		}
	}
	// 清除剩下的
	while (p1) {
		q = p1;
		p1 = p1->next;
		free(q);
	}
	while (p2) {
		q = p2;
		p2 = p2->next;
		free(q);
	}
	r->next = NULL;
	free(L2);
}

void SolveLinkList15() {
	LinkList L1, L2;
	printf("请输入链表L1：\n");
	TailInsertLinkList(L1);
	printf("请输入链表L2：\n");
	TailInsertLinkList(L2);
	printf("L1为：");
	PrintLinkList(L1);
	printf("L2为：");
	PrintLinkList(L2);
	UnionLinkList(L1, L2);
	printf("公共结点为：");
	PrintLinkList(L1);
}