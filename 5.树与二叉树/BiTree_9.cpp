#include <stdio.h>
#include "BiTree.h"

// 9.双分支结点个数
void Swap(BiTree T) {
	if (T) {
		Swap(T->lchild);
		Swap(T->rchild);
		BiTNode* Temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = Temp;
	}
}
void SolveBiTree_9() {
	BiTree BT;
	CreateBiTree(BT);
	printf("原来先序为：");
	PreOrder(BT);
	printf("\n原来中序为：");
	InOrder(BT);
	printf("\n原来后序为：");
	PostOrder(BT);
	Swap(BT);
	printf("\n\n现在先序为：");
	PreOrder(BT);
	printf("\n现在中序为：");
	InOrder(BT);
	printf("\n现在后序为：");
	PostOrder(BT);
}