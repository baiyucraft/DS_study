#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 从头至尾扫描单链表，pre指向当前结点p的前驱结点
void LinkList_DelX3(LinkList& L, ElemtType x) {
	// 当前结点p
	LNode* p = L->next;
	// p的前驱结点pre
	LNode* pre = L;
	// 用来存放要删除的结点
	LNode* q;
	while (p != NULL){
		// 如果当前结点p的数据为x
		if (p->data == x) {
			// 要删除结点q
			q = p;
			// 使当前结点p变成下一个结点
			p = p->next;
			// 要删除结点的前驱指针pre指向要删除结点的下一个结点，也就是现在的p
			pre->next = p;
			free(q);
		}
		else {
			// p的数据不等于x，就将前驱结点和当前结点都往后移一个结点
			pre = p;
			p = p->next;
		}
	}
}
// 用p指针扫描所有结点，将值等于x的释放，不等于x的链接到L之后
void LinkList_DelX4(LinkList& L, ElemtType x) {
	// 当前结点p
	LNode* p = L->next;
	// L的尾结点r，初值为头结点
	LNode* r = L;
	// 要删除结点q
	LNode* q;
	while (p != NULL) {
		// 如果p的数据不等于x
		if (p->data != x) {
			// 尾结点r的下一个结点为当前结点p
			r->next = p;
			// 尾结点r变成新的尾结点
			r = p;
			// 使当前结点p变成下一个结点
			p = p->next;
		}
		else {
			// 要删除结点q
			q = p;
			// 使当前结点p变成下一个结点
			p = p->next; 
			free(q);
		}
	}
	// 尾结点r的下一个结点为NULL
	r->next = NULL;
}
void SolveLinkList2() {
	LinkList L;
	TailInsertLinkList(L);
	printf("原链表为：");
	PrintLinkList(L);
	ElemtType x;
	printf("请输入要删除的数：");
	scanf("%d", &x);
	LinkList_DelX3(L, x);
	printf("删除所有%d后的链表为：", x);
	PrintLinkList(L);
	printf("请输入要删除的数：");
	scanf("%d", &x);
	LinkList_DelX4(L, x);
	printf("删除所有%d后的链表为：", x);
	PrintLinkList(L);
}
