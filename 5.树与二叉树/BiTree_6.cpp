#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

// 6.通过先序和中序建立二叉树（l1、l2为先序的第一和最后一个结点下标，h1、h2为中序第一和最后一个结点的下标）
BiTree PreInCreate(ElemtType A[], ElemtType B[], int l1, int h1, int l2, int h2){
	// 初始调用时l1=l2=1，h1=h2=n
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
	root->data = A[l1];
	int i;
	// 找到B中根结点的位置
	for (i = l2; B[i] != root->data; i++);
	// 左子树的长度
	int llen = i - l2;
	// 右子树的长度
	int rlen = h2 - i;
	// 如果左子树不为空，递归左子树
	if (llen)
		root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	// 如果右子树不为空，递归右子树
	if (rlen)
		root->rchild = PreInCreate(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}
void SolveBiTree_6() {
	char Pre[] = "0ABCDEFGHI";
	char In[] = "0BCAEDGHFI";
	BiTree BT = PreInCreate(Pre, In, 1, 9, 1, 9);
	printf("先序为：");
	PreOrder(BT);
	printf("\n中序为：");
	InOrder(BT);
	printf("\n后序为：");
	PostOrder(BT);
}