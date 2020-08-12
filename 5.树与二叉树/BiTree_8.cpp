#include <stdio.h>
#include "BiTree.h"

// 8.˫��֧������
int DsonNodes(BiTree T) {
	if (T == NULL)
		return 0;
	// ˫��֧���
	else if (T->lchild != NULL && T->rchild != NULL)
		return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
	else
		return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}
void SolveBiTree_8() {
	BiTree BT;
	CreateBiTree(BT);
	printf("�ö�����˫��֧������Ϊ��%d", DsonNodes(BT));
}