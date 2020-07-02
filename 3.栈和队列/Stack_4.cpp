#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// 尾插建立字符串链表
LinkList TailInsertLinkList(LinkList& L) {
	char x;
	// 新增结点
	LNode* s;
	// 初始化单链表，创建头结点
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// 尾指针r指向表尾结点
	LNode* r = L;
	// 输入数据，例如：abads!
	printf("请输入一串字符串(以!结尾)：");
	scanf("%c", &x);
	while (x != '!') {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%c", &x);
	}
	r->next = NULL;
	return L;
}
// 打印字符串链表
void PrintLinkList(LinkList L) {
	printf("头结点->");
	LNode* p = L->next;
	while (p != NULL) {
		printf("%c->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
// 获取字符串单链表长度
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

// 判断链表全部n个字符是否中心对称
bool dcStackLinkList(LinkList L, int n) {
	int i;
	// 辅助栈
	char* s = (char*)malloc(sizeof(char) * (n / 2));
	// 遍历的工作指针
	LNode *p = L->next;
	for (i = 0; i < n / 2; i++) {
		s[i] = p->data;
		p = p->next;
	}
	// 恢复之前的i值
	i--;
	// 判断是否为奇数，若为奇数，跳过中心结点
	if (n % 2 == 1)
		p = p->next;
	while (p != NULL && s[i] == p->data) {
		i--;
		p = p->next;
	}
	// 栈空代表对称
	if (i == -1)
		return true;
	else
		return false;
}

void SolveStack_4() {
	LinkList L;
	TailInsertLinkList(L);
	printf("字符串链表为：");
	PrintLinkList(L);
	int n = LengthLinkList(L);
	if (dcStackLinkList(L, n))
		printf("中心对称");
	else
		printf("不中心对称");

}