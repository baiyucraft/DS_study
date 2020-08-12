#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

// 5.�ǵݹ���������߶�
int BiTreeDepth(BiTree T) {
	// ���գ��߶�Ϊ0
	if (!T)
		return 0;
	// ǰ��ָ��
	int front = -1, rear = -1;
	// lastָ��ǰ������ҽ��
	int last = 0;
	// level��ʾ�߶�
	int level = 0;
	BiTree Q[MaxSize];
	// ��������
	Q[++rear] = T;
	BiTNode* p = NULL;
	while (front < rear) {
		// ���ӣ����ڷ��ʵĽ�㣩
		p = Q[++front];
		// ���Ӳ�Ϊ�գ��������
		if (p->lchild)
			Q[++rear] = p->lchild;
		// �Һ��Ӳ�Ϊ�գ��Һ������
		if (p->rchild)
			Q[++rear] = p->rchild;
		// ���Ϊ�ò����ҽ��
		if (front == last) {
			// ������1
			level++;
			// lastָ���²�
			last = rear;
		}
	}
	return level;
}
// 5..�ݹ���������߶�
int BiTreeDepth2(BiTree T) {
	// ���գ��߶�Ϊ0
	if (!T)
		return 0;
	int ldept, rdept;
	// �������߶�
	ldept = BiTreeDepth2(T->lchild);
	// �������߶�
	rdept = BiTreeDepth2(T->rchild);
	// ���ظߵ�
	if (ldept > rdept)
		return ldept + 1;
	else
		return rdept + 1;
}
void SolveBiTree_5() {
	BiTree BT;
	CreateBiTree(BT);
	printf("�ö�������%d��\n", BiTreeDepth(BT));
	printf("�ö�������%d��\n", BiTreeDepth2(BT));
}