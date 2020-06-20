#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 将链表A分为奇数链表A和偶数链表B
LinkList DisCreateLinkList1(LinkList* A) {
	// 计数君
	int i = 0;
	// 创建拆分的第二个链表
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	// AB的尾结点指针指向头结点
	LNode* ra = *A;
	LNode* rb = B;
	// 遍历A的工作结点p
	LNode* p = (*A)->next;
	// 断链
	(*A)->next = NULL;
	// 遍历原链表
	while (p != NULL) {
		// 偶数放b
		if (++i % 2 == 0) {
			rb->next = p;
			rb = p;
		}
		// 奇数放a
		else {
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}

void SolveLinkList10() {
	LinkList A;
	TailInsertLinkList(&A);
	printf("原链表为：");
	PrintLinkList(A);
	LinkList B = DisCreateLinkList1(&A);
	printf("奇数链表为：");
	PrintLinkList(A);
	printf("偶数链表为：");
	PrintLinkList(B);
}