#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "BiTNodeQueue.h"

// 11.ɾ��ֵ��Ԫ��ֵx��������
// ɾ����
void DeleteXTree(BiTree T) {
	if (T) {
		// ɾ����������
		DeleteXTree(T->lchild);
		DeleteXTree(T->rchild);
		// �ͷŽ��
		free(T);
	}
}
// ���Ҳ�ɾ��x
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
	printf("ԭ������Ϊ��");
	PreOrder(BT);
	printf("\nԭ������Ϊ��");
	InOrder(BT);
	printf("\nԭ������Ϊ��");
	PostOrder(BT);

	SeachXBiTree(BT, 'E');

	printf("\n\nɾ����E��������Ϊ��");
	PreOrder(BT);
	printf("\nɾ����E��������Ϊ��");
	InOrder(BT);
	printf("\nɾ����E�������Ϊ��");
	PostOrder(BT);
}