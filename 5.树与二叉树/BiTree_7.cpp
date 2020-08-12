#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeQueue.h"

// 7.检查是否为完全二叉树
bool IsComplete(BiTree T) {
	BiTNode* p;
	BiTNodeQueue Q;
	InitBiTNodeQueue(Q);
	if (!T)
		return true;
	EnBiTNodeQueue(Q, T);
	while (!EmptyBiTNodeQueue(Q)){
		p = DeBiTNodeQueue(Q);
		// 结点非空，左右子树进队
		if (p) {
			EnBiTNodeQueue(Q, p->lchild);
			EnBiTNodeQueue(Q, p->rchild);
		}
		// 结点为空，检查之后是否有非空结点
		else {
			while (!EmptyBiTNodeQueue(Q)) {
				p = DeBiTNodeQueue(Q);
				if (p)
					return false;
			}
		}
	}
	return true;
}
void SolveBiTree_7() {
	BiTree BT;
	CreateBiTree(BT);
	if (IsComplete(BT))
		printf("该二叉树为完全二叉树");
	else
		printf("该二叉树为非完全二叉树");
}