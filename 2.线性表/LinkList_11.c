#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 将链表A分为奇数链表A和逆置后的偶数链表B
LinkList DisCreateLinkList2(LinkList* A) {
	// 计数君
	//int i = 0;
	// 创建拆分的第二个链表
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	// B的尾结点指针指向头结点
	LNode* ra = *A;
	// 遍历A的工作结点p
	LNode* p = (*A)->next;
	// 断链
	(*A)->next = NULL;
	// q存储偶数结点
	LNode* q;
	// 遍历原链表
	while (p != NULL) {
		// 对奇数结点处理
		ra->next = p;
		ra = p;
		p = p->next;
		// 对偶数结点的处理
		if (p != NULL) {
			// q对偶数结点工作
			q = p;
			p = p->next;
		}
		// 前插
		q->next = B->next;
		B->next = q;
	}
	ra->next = NULL;
	return B;
}

void SolveLinkList11() {
	LinkList A;
	TailInsertLinkList(&A);
	printf("原链表为：");
	PrintLinkList(A);
	LinkList B = DisCreateLinkList2(&A);
	printf("奇数链表为：");
	PrintLinkList(A);
	printf("偶数链表为：");
	PrintLinkList(B);
}