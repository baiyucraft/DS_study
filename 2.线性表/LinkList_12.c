#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 删除递增有序单链表中相同的元素
void LinkListDelSame(LinkList* L) {
	// 工作结点p
	LNode* p = (*L)->next;
	// 要删除结点q
	LNode* q;
	// 空链表返回
	if (p == NULL)
		return;
	// 遍历结点
	while (p->next != NULL) {
		q = p->next;
		// 比较p与p的下一个结点的数据，如果相等删去，否则换下一个结点
		if (p->data == q->data) {
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
}

void SolveLinkList12() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("原链表为：");
	PrintLinkList(L);
	LinkListDelSame(&L);
	printf("删除重复后的链表为：");
	PrintLinkList(L);
}