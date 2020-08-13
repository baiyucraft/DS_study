#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "BiTNodeQueue.h"

// 11.删除值以元素值x根的子树
// 删除树
void DeleteXTree(BiTree T) {
	if (T) {
		// 删除左右子树
		DeleteXTree(T->lchild);
		DeleteXTree(T->rchild);
		// 释放结点
		free(T);
	}
}
// 查找并删除x
void SeachXBiTree(BiTree T, ElemtType x) {
	BiTNode* p;
	BiTNodeQueue  Q;
	if (T) {
		if (T->data == x) {
			DeleteXTree(T);
			exit(0);
		}
		InitBiTNodeQueue(Q);
		EnBiTNodeQueue(Q, T);
		while (!EmptyBiTNodeQueue(Q)) {
			p = DeBiTNodeQueue(Q);
			if (p->lchild) {
				if (p->lchild->data == x) {
					DeleteXTree(p->lchild);
					p->lchild = NULL;
				}
				else
					EnBiTNodeQueue(Q, p->lchild);
			}
			if (p->rchild) {
				if (p->rchild->data == x) {
					DeleteXTree(p->rchild);
					p->rchild = NULL;
				}
				else
					EnBiTNodeQueue(Q, p->rchild);
			}
		}
	}
}
void SolveBiTree_11() {
	BiTree BT;
	CreateBiTree(BT);
	printf("原来先序为：");
	PreOrder(BT);
	printf("\n原来中序为：");
	InOrder(BT);
	printf("\n原来后序为：");
	PostOrder(BT);

	SeachXBiTree(BT, 'E');

	printf("\n\n删除‘E’后先序为：");
	PreOrder(BT);
	printf("\n删除‘E’后中序为：");
	InOrder(BT);
	printf("\n删除‘E’后后序为：");
	PostOrder(BT);
}