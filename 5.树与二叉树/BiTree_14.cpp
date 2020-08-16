#include <stdio.h>
#include "BiTree.h"

typedef struct {
	BiTree data[255];
	int level[255];
	int front, rear;
}Queue;

// 14.求二叉树的宽度
int BiTreeWidth(BiTree T) {
	BiTNode* p;
	Queue Q;
	int k;
	// 队列初始化为空
	Q.front = Q.rear = -1;
	Q.rear++;
	// 根结点
	Q.data[Q.rear] = T;
	// 第一层
	Q.level[Q.rear] = 1;
	while (Q.front < Q.rear) {
		// 出队
		p = Q.data[++Q.front];
		k = Q.level[Q.front];
		// 左孩子进队
		if (p->lchild != NULL) {
			// 进队
			Q.data[++Q.rear] = p->lchild;
			Q.level[Q.rear] = k + 1;
		}
		// 右孩子进队
		if (p->rchild != NULL) {
			// 进队
			Q.data[++Q.rear] = p->rchild;
			Q.level[Q.rear] = k + 1;
		}
	}
	// max记录一层最多结点数，i遍历，n统计
	int max = 0, i = 0, n;
	k = 1;
	while (i <= Q.rear) {
		n = 0;
		while(i<=Q.rear&&Q.level[i]==k){
			n++;
			i++;
		}
		k = Q.level[i];
		// 记录最大
		if (n > max)
			max = n;
	}
	return max;
}
void SolveBiTree_14() {
	BiTree BT;
	CreateBiTree(BT);
	printf("先序为：");
	PreOrder(BT);
	printf("\n中序为：");
	InOrder(BT);
	printf("\n后序为：");
	PostOrder(BT);

	printf("\n宽度为：%d", BiTreeWidth(BT));
}