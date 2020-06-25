#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 先减去相差的长度dist，再分别遍历找到公共结点
LinkList SearchLinkList1st(LinkList L1, LinkList L2) {
	// 获取两个链表的长度
	int len1 = LengthLinkList(L1);
	int len2 = LengthLinkList(L2);
	// 记录表长之差
	int dist;
	LinkList LongList, ShortList;
	if (len1 > len2) {
		LongList = L1->next;
		ShortList = L2->next;
		dist = len1 - len2;
	}
	else {
		LongList = L2->next;
		ShortList = L1->next;
		dist = len2 - len1;
	}
	// 将长的链表前面减去两链表之差，使两链表剩下长度相等
	while (dist--) {
		LongList = LongList->next;
	}
	// 遍历两个剩下的链表
	while (LongList != NULL) {
		// 遇到公共结点返回，这里加上个头结点方便输出
		if(LongList==ShortList){
			LinkList L = (LinkList)malloc(sizeof(LNode));
			L->next = LongList;
			return L;
		}
		// 反之判断下一个
		else {
			LongList = LongList->next;
			ShortList = ShortList->next;
		}
	}
	return NULL;
}

// 创建两个有公共结点的链表
void CreateComLinkList(LinkList& L1, LinkList& L2) {
	ElemtType x;
	// 新增结点
	LNode* s;
	// 尾指针r1、r2指向两个表的表尾结点
	LNode* r1 = L1->next;
	while (r1->next != NULL)
		r1 = r1->next;
	LNode* r2 = L2->next;
	while (r2->next != NULL)
		r2 = r2->next;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r1->next = s;
		r2->next = s;
		r1 = s;
		r2 = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r1->next = NULL;
	r2->next = NULL;
}

void SolveLinkList8() {
	LinkList L1, L2;
	printf("请输入第一个链表的不公共结点:\n");
	HeadInsertLinkList(L1);
	printf("请输入第二个链表的不公共结点:\n");
	HeadInsertLinkList(L2);
	printf("请输入两个链表的公共结点:\n");
	CreateComLinkList(L1, L2);
	printf("L1：");
	PrintLinkList(L1);
	printf("L2：");
	PrintLinkList(L2);
	LinkList L = SearchLinkList1st(L1, L2);
	printf("两个链表的公共结点为：");
	PrintLinkList(L);
}