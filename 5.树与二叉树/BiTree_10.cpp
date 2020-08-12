#include <stdio.h>
#include "BiTree.h"

// 初始从第一个开始找
int i = 1;

// 10.先序遍历第k个的值
ElemtType PreNode(BiTree T, int k) {
	if (T == NULL)
		return '#';
	if (i == k)
		return T->data;
	// 下一个结点
	i++;
	// 左子树递归寻找
	char ch = PreNode(T->lchild, k);
	if (ch != '#')
		return ch;
	// 在右子树中递归寻找
	ch = PreNode(T->rchild, k);
	return ch;
}
void SolveBiTree_10() {
	BiTree BT;
	CreateBiTree(BT);
	printf("先序遍历为：");
	PreOrder(BT);
	printf("先序遍历下第5个结点的值为：%c", PreNode(BT, 5));
}