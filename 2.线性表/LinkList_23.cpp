#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// n为数组中数的绝对值的范围，保留第一个绝对值为那个值的数（空间换时间）空间：o(m)，时间o(n)
void DelAbsLinkList(LinkList& L, int n) {
	// 工作指针p
	LNode* p = L->next;
	// 要删除的结点de
	LNode* del;
	// temp表示辅助数组
	int* temp, m;
	temp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++)
		*(temp + i) = 0;
	// 遍历链表
	while (p->next != NULL) {
		// m=（判断数据的正负，正取正，负取反）
		m = p->next->data > 0 ? p->next->data : -p->next->data;
		if (*(temp + m) == 0) {
			*(temp + m) = 1;
			p = p->next;
		}
		else {
			del = p->next;
			p->next = del->next;
			free(del);
		}
	}
	free(temp);
}

void SolveLinkList23() {
	LinkList L;
	TailInsertLinkList(L);
	printf("原链表为：");
	PrintLinkList(L);
	DelAbsLinkList(L, 100);
	printf("删除后的链表为：");
	PrintLinkList(L);
}