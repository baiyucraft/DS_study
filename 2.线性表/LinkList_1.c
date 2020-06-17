#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 王道书上的题解，因为C中没有引用，书上的思想无法实现
// 原题解采用C++中的引用，通过同一个指针传参实现L->next->next的递归调用，所以不会断链
void LinkList_DelX1(LinkList* L, ElemtType x) {
	if ((*L) == NULL) {
		printf("删除成功");
		return;
	}	
	printf("%d\n", (*L)->data);
	if ((*L)->data == x) {
		LNode* p = *L;
		//printf("%d\n", p->data);
		*L = (*L)->next;
		free(p);
		LinkList_DelX1(L, x);
	}
	else {
		printf("this");
		(*L) = (*L)->next;
		LinkList_DelX1(L, x);
	}
}
// LeetCode上的递归想法
// 递归出口为L为空，传参L->next,若data为x删除去结点返回L->next,即下一个，否则返回L
LinkList LinkList_DelX2(LinkList L, ElemtType x){
	if (!L)
		return L;
	L->next = LinkList_DelX2(L->next, x);
	// 如果数据为x，删除结点返回下一个结点
	if (L->data == x) {
		LNode* p = L;
		L = L->next;
		free(p);
		return L;
	}
	// 反之不为x，返回当前结点
	return L;
}

void SolveLinkList1() {
	LinkList L;
	CreateUnLinkList(&L);
	PrintUnLinkList(L);
	ElemtType x;
	printf("请输入要删除的数：");
	scanf("%d", &x);
	//LinkList_DelX1(&L, x);
	L = LinkList_DelX2(L, x);
	printf("删除所有%d后的链表为：", x);
	PrintUnLinkList(L);
}