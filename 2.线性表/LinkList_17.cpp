#include <stdio.h>
#include "DLinkList.h"

// 判别循环双链表是否对称
bool SymmertryCirDLinkList(DLinkList L) {
	// 头遍历指针p
	DNode* p = L->next;
	// 尾遍历指针q
	DNode* q = L->prior;
	// 奇数时p=q，偶数时q->next=p，(不能p->next=q，因为这样就没有比较最后两个结点直接停止了)
	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
			return false;
	}
	return true;
}

void SolveDLinkList17() {
	DLinkList L;
	TailInsertCirDLinkList(L);
	printf("循环双链表为：");
	PrintCirDLinkList(L);
	if (SymmertryCirDLinkList(L))
		printf("对称");
	else
		printf("不对称");
}