#include <stdio.h>
#include "BiTree.h"

typedef struct LBiTNode {

}LBiTNode,*LBiTNodeList;

BiTNode* head;
BiTNode* pre = NULL;

// 16.���������Ҷ�ӽ��
BiTNode* InOrderLeave(BiTree T) {
	if (T) {
		InOrderLeave(T->lchild);
		if (T->lchild == NULL && T->rchild == NULL) {
			// ��һ���������
			if (pre == NULL) {
				head = T;
				pre = T;
			}
			else {
				pre->rchild = T;
				pre = T;
			}
		}
		InOrderLeave(T->rchild);
		pre->rchild = NULL;
	}
	return head;
}
void SolveBiTree_16() {
	BiTree BT;
	CreateBiTree(BT);
	printf("����Ϊ��");
	PreOrder(BT);
	printf("\n����Ϊ��");
	InOrder(BT);
	printf("\n����Ϊ��");
	PostOrder(BT);

	printf("\nҶ�ӽ��Ϊ��");
	BiTNode* p = InOrderLeave(BT);
	while (p) {
		printf("%c-", p->data);
		p = p->rchild;
	}
}