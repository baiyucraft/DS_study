#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

// 5.非递归求二叉树高度
int BiTreeDepth(BiTree T) {
	// 树空，高度为0
	if (!T)
		return 0;
	// 前后指针
	int front = -1, rear = -1;
	// last指向当前层的最右结点
	int last = 0;
	// level表示高度
	int level = 0;
	BiTree Q[MaxSize];
	// 根结点入队
	Q[++rear] = T;
	BiTNode* p = NULL;
	while (front < rear) {
		// 出队（正在访问的结点）
		p = Q[++front];
		// 左孩子不为空，左孩子入队
		if (p->lchild)
			Q[++rear] = p->lchild;
		// 右孩子不为空，右孩子入队
		if (p->rchild)
			Q[++rear] = p->rchild;
		// 如果为该层最右结点
		if (front == last) {
			// 层数加1
			level++;
			// last指向下层
			last = rear;
		}
	}
	return level;
}
// 5..递归求二叉树高度
int BiTreeDepth2(BiTree T) {
	// 树空，高度为0
	if (!T)
		return 0;
	int ldept, rdept;
	// 左子树高度
	ldept = BiTreeDepth2(T->lchild);
	// 右子树高度
	rdept = BiTreeDepth2(T->rchild);
	// 返回高的
	if (ldept > rdept)
		return ldept + 1;
	else
		return rdept + 1;
}
void SolveBiTree_5() {
	BiTree BT;
	CreateBiTree(BT);
	printf("该二叉树有%d层\n", BiTreeDepth(BT));
	printf("该二叉树有%d层\n", BiTreeDepth2(BT));
}