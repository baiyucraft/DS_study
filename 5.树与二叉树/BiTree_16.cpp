#include <stdio.h>
#include "BiTree.h"

typedef struct LBiTNode {

}LBiTNode,*LBiTNodeList;

BiTNode* head;
BiTNode* pre = NULL;

// 16.从左到右输出叶子结点
BiTNode* InOrderLeave(BiTree T) {
	if (T) {
		InOrderLeave(T->lchild);
		if (T->lchild == NULL && T->rchild == NULL) {
			// 第一个结点的情况
			if (pre == NULL) {
				head = T;
				pre = T;
			}
			else {
				pre->rchild = T;
				pre = T;
			}
		}
		InOrderLeave(T->rchild);
		pre->rchild = NULL;
	}
	return head;
}
void SolveBiTree_16() {
	BiTree BT;
	CreateBiTree(BT);
	printf("先序为：");
	PreOrder(BT);
	printf("\n中序为：");
	InOrder(BT);
	printf("\n后序为：");
	PostOrder(BT);

	printf("\n叶子结点为：");
	BiTNode* p = InOrderLeave(BT);
	while (p) {
		printf("%c-", p->data);
		p = p->rchild;
	}
}