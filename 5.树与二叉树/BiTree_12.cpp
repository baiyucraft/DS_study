#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

typedef struct {
	BiTNode* t;
	// tag=0表示左子树被访问，tag=1表示右子树被访问
	int tag;
}stack;

// 12.求元素值为x的结点的祖先结点
void SearchXParent(BiTree T, ElemtType x) {
	stack S[255]; 
	int top = 0;
	BiTNode* p = T;
	// 后续遍历二叉树
	while (p != NULL || top > 0) {
		// 若结点不为空并且数据不为x时入栈
		while (p != NULL && p->data != x) {
			S[++top].t = p;
			S[top].tag = 0;
			// 左子树向下
			p = p->lchild;
		}
		// 如果值为x，找到x，打印    (相对于书上加了个条件，不然无法运行（有NULL）)
		if (p != NULL && p->data == x) {
			printf("所查结点的所有祖先结点为：");
			for (int i = 1; i <= top; i++)
				printf("%c", S[i].t->data);
			exit(1);
		}
		// 退栈（右子树访问过的退）
		while (top != 0 && S[top].tag == 1)
			top--;
		// 向右子树遍历
		if (top != 0) {
			S[top].tag = 1;
			p = S[top].t->rchild;
		}
	}
}
void SolveBiTree_12() {
	BiTree BT;
	CreateBiTree(BT);
	printf("原来先序为：");
	PreOrder(BT);
	printf("\n原来中序为：");
	InOrder(BT);
	printf("\n原来后序为：");
	PostOrder(BT);

	printf("\n\n‘E’-");
	SearchXParent(BT, 'E');
}