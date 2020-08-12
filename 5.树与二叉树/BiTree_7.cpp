#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeQueue.h"

// 7.����Ƿ�Ϊ��ȫ������
bool IsComplete(BiTree T) {
	BiTNode* p;
	BiTNodeQueue Q;
	InitBiTNodeQueue(Q);
	if (!T)
		return true;
	EnBiTNodeQueue(Q, T);
	while (!EmptyBiTNodeQueue(Q)){
		p = DeBiTNodeQueue(Q);
		// ���ǿգ�������������
		if (p) {
			EnBiTNodeQueue(Q, p->lchild);
			EnBiTNodeQueue(Q, p->rchild);
		}
		// ���Ϊ�գ����֮���Ƿ��зǿս��
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
		printf("�ö�����Ϊ��ȫ������");
	else
		printf("�ö�����Ϊ����ȫ������");
}