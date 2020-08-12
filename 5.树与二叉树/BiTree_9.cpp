#include <stdio.h>
#include "BiTree.h"

// 9.˫��֧������
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
	printf("ԭ������Ϊ��");
	PreOrder(BT);
	printf("\nԭ������Ϊ��");
	InOrder(BT);
	printf("\nԭ������Ϊ��");
	PostOrder(BT);
	Swap(BT);
	printf("\n\n��������Ϊ��");
	PreOrder(BT);
	printf("\n��������Ϊ��");
	InOrder(BT);
	printf("\n���ں���Ϊ��");
	PostOrder(BT);
}