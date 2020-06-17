#include <stdio.h>
#include "LinkList.h"

// 反向打印，通过递归
void RPrintLinkList(LinkList L){
	// 递归出口，如果下一个结点为空，则停止
	if (L->next != NULL) 
		RPrintLinkList(L->next);
	// 如果当前结点不为空，打印数据
	if (L != NULL)
		printf("<-%d", L->data);
}

void SolveLinkList3() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("链表正序为：");
	PrintLinkList(L);
	printf("链表反向为：");
	// 用next防止打印头结点
	RPrintLinkList(L->next);
}