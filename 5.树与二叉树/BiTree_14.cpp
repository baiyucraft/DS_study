#include <stdio.h>
#include "BiTree.h"

typedef struct {
	BiTree data[255];
	int level[255];
	int front, rear;
}Queue;

// 14.��������Ŀ��
int BiTreeWidth(BiTree T) {
	BiTNode* p;
	Queue Q;
	int k;
	// ���г�ʼ��Ϊ��
	Q.front = Q.rear = -1;
	Q.rear++;
	// �����
	Q.data[Q.rear] = T;
	// ��һ��
	Q.level[Q.rear] = 1;
	while (Q.front < Q.rear) {
		// ����
		p = Q.data[++Q.front];
		k = Q.level[Q.front];
		// ���ӽ���
		if (p->lchild != NULL) {
			// ����
			Q.data[++Q.rear] = p->lchild;
			Q.level[Q.rear] = k + 1;
		}
		// �Һ��ӽ���
		if (p->rchild != NULL) {
			// ����
			Q.data[++Q.rear] = p->rchild;
			Q.level[Q.rear] = k + 1;
		}
	}
	// max��¼һ�����������i������nͳ��
	int max = 0, i = 0, n;
	k = 1;
	while (i <= Q.rear) {
		n = 0;
		while(i<=Q.rear&&Q.level[i]==k){
			n++;
			i++;
		}
		k = Q.level[i];
		// ��¼���
		if (n > max)
			max = n;
	}
	return max;
}
void SolveBiTree_14() {
	BiTree BT;
	CreateBiTree(BT);
	printf("����Ϊ��");
	PreOrder(BT);
	printf("\n����Ϊ��");
	InOrder(BT);
	printf("\n����Ϊ��");
	PostOrder(BT);

	printf("\n���Ϊ��%d", BiTreeWidth(BT));
}