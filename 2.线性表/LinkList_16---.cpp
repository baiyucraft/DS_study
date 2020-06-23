#include <stdio.h>
#include "LinkList.h"

// 字符串模式匹配的链表形式，这是最基本的算法，匹配L1中含L2
bool PatternLinkList1(LinkList L1, LinkList L2) {
	// L1、L2的比较指针p1，p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	//存储开始遍历的结点
	LNode* pre = p1;
	while (p1 && p2) {
		// 若p1的值与p2的值相等，开始继续匹配
		if (p1->data == p2->data) {
			p1 = p1->next;
			p2 = p2->next;
		}
		// 若遇到不相等的值，p1回到上次开始匹配的结点的下一个结点，p2从头开始，重新比较
		else {
			pre = pre->next;
			p1 = pre;
			p2 = L2->next;
		}
	}
	// 如果p2比较完成，则说明成功
	if (p2 == NULL)
		return true;
	else
		return false;
}

void SolveLinkList16() {
	LinkList L1, L2;
	printf("请输入链表L1：\n");
	TailInsertLinkList(L1);
	printf("请输入链表L2：\n");
	TailInsertLinkList(L2);
	printf("L1为：");
	PrintLinkList(L1);
	printf("L2为：");
	PrintLinkList(L2);
	if(PatternLinkList1(L1,L2))
		printf("匹配成功");
	else
		printf("匹配失败");
}