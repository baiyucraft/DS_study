#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1.创建带环的单链表
void CreateRingLinkList(LinkList& L) {
	ElemtType x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// 新增结点
	LNode* s;
	// 初始化单链表，创建头结点
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// 尾指针r指向表尾结点
	LNode* r = L;
	for (int i = 0; i < 10; i++) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x[i];
		r->next = s;
		r = s;
	}
	// 环入口在第四个结点
	r->next = L->next->next->next->next;
}

// 2.打印带环的单链表
void PrintRingLinkList(LinkList L) {
	printf("头结点->");
	LNode* p = L->next;
	for (int i = 0; i < 10; i++) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

// 检测是否有环，如果有
LNode* FindLoopStart(LinkList L) {
	// 设置快fast慢slow两个指针
	LNode* fast = L->next;
	LNode* slow = L->next;
	// 遍历结点，直到slow或者fast到头或者slow=fast(即存在环所以相遇)
	while (slow != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow == NULL || fast->next == NULL)
		return NULL;
	// 分别指向开始点与相遇点,当两个结点相遇时，即为入口点
	LNode* p1 = L->next;
	LNode* p2 = slow;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void SolveLinkList24() {
	LinkList L1, L2;
	CreateRingLinkList(L1);
	TailInsertLinkList(L2);
	printf("L1链表为：");
	PrintRingLinkList(L1);
	if (FindLoopStart(L1)) {
		printf("L1带环，起点为：%d\n", FindLoopStart(L1)->data);
	}
	else
		printf("L1不带环\n");
	printf("L2链表为：");
	PrintLinkList(L2);
	if (FindLoopStart(L2)) {
		printf("L2带环，起点为：%d\n", FindLoopStart(L2)->data);
	}
	else
		printf("L2不带环\n");
}