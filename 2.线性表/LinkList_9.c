#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 升序输出并删除
void LinkListDelMinP(LinkList* L) {
	// 最小值结点的前驱结点pre
	LNode* pre;
	// 遍历的工作结点p
	LNode* p;
	// 要删除的结点
	LNode* q;
	while ((*L)->next != NULL) {
		pre = *L;
		p = pre->next;
		while (p->next != NULL) {
			if (p->next->data < pre->next->data) {
				pre = p;
			}
			p = p->next;
		}
		// 打印最小值结点
		printf("%d->", pre->next->data);
		// 断链删除结点
		q = pre->next;
		pre->next = q->next;
		free(q);
	}
	free(*L);
	printf("NULL\n排序释放成功");
}

void SolveLinkList9() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("原链表为：");
	PrintLinkList(L);
	printf("输出：");
	LinkListDelMinP(&L);
}
