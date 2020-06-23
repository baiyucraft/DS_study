#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 合并两个递增有序的单链表L1、L2，合并成递减（采用头插法）
void MergeLinkList(LinkList& L1, LinkList& L2) {
	// 暂存插入结点的下一个结点
	LNode* r;
	// L1的工作结点p1
	LNode* p1 = L1->next;
	// L2的工作结点p2
	LNode* p2 = L2->next;
	// 给L1断链进而存储在L1的头结点上
	L1->next = NULL;
	// 遍历两个表，判断大小，头插
	while (p1 && p2) {
		if (p1->data <= p2->data) {
			r = p1->next;
			p1->next = L1->next;
			L1->next = p1;
			p1 = r;
		}
		else {
			r = p2->next;
			p2->next = L1->next;
			L1->next = p2;
			p2 = r;
		}
	}
	// 将未遍历完的链表给p2
	if (p1)
		p2 = p1;
	while (p2) {
		r = p2->next;
		p2->next = L1->next;
		L1->next = p2;
		p2 = r;
	}
	free(L2);
}

void SolveLinkList13() {
	LinkList L1, L2;
	printf("请输入链表L1：\n");
	TailInsertLinkList(L1);
	printf("请输入链表L2：\n");
	TailInsertLinkList(L2);
	printf("L1为：");
	PrintLinkList(L1);
	printf("L2为：");
	PrintLinkList(L2);
	MergeLinkList(L1, L2);
	printf("合并后为：");
	PrintLinkList(L1);
}