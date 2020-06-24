#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1.此算法设置两个指针p、q，先让p指针移动k个结点，这时候p与q之间相差k个结点
// 2.之后p、q同步运动，所以当p运动到表尾时，p、q之间仍然相差k个结点，此时q结点为所查找结点
// 查找倒数第k个数，
int SearchLinkListK(LinkList L, int k) {
	LNode* p = L->next;
	LNode* q = L->next;
	int count = 0;
	while (p != NULL) {
		// cout<k，执行第一步
		if (count < k)
			count++;
		// 反之同步移动
		else
			q = q->next;
		p = p->next;
	}
	// 这里说明表长不足k，即查找失败
	if (count < k)
		return 0;
	else {
		printf("查找到的结点为：%d", q->data);
		return 1;
	}
}

void SolveLinkList21() {
	LinkList L;
	TailInsertLinkList(L);
	printf("原链表为：");
	PrintLinkList(L);
	SearchLinkListK(L, 2);
}