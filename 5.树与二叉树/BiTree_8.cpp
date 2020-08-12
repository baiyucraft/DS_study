#include <stdio.h>
#include "BiTree.h"

// 8.双分支结点个数
int DsonNodes(BiTree T) {
	if (T == NULL)
		return 0;
	// 双分支结点
	else if (T->lchild != NULL && T->rchild != NULL)
		return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
	else
		return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}
void SolveBiTree_8() {
	BiTree BT;
	CreateBiTree(BT);
	printf("该二叉树双分支结点个数为：%d", DsonNodes(BT));
}