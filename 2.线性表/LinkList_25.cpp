#include <stdio.h>
#include "LinkList.h"

// 改变链表数据
void ChangeLinkList(LinkList& L) {
	// p、q为遍历结点，辅助结点r，遍历前半段结点s
	LNode* p, * q, * r, * s;
	p = q = L;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		// q走两步
		if (q->next != NULL)
			q = q->next;
	}
	// 遍历结束后，p指向中间结点、q指向后半段链表的首结点
	// q指向后半段结点的第一个结点
	q = p->next;
	// 将p之后的后半段逆置，采用头插法
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	// 遍历两个处理结束的链表
	s = L->next;
	q = p->next;
	// p的新链表的尾结点
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = s->next; 
		s->next = q;
		s = q->next;
		q = r;
	}
}

void SolveLinkList25() {
	LinkList L;
	TailInsertLinkList(L);
	printf("原链表为：");
	PrintLinkList(L);
	ChangeLinkList(L);
	printf("改变后的链表为：");
	PrintLinkList(L);
}