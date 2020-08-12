#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

// 6.ͨ���������������������l1��l2Ϊ����ĵ�һ�����һ������±꣬h1��h2Ϊ�����һ�����һ�������±꣩
BiTree PreInCreate(ElemtType A[], ElemtType B[], int l1, int h1, int l2, int h2){
	// ��ʼ����ʱl1=l2=1��h1=h2=n
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTNode));
	root->data = A[l1];
	int i;
	// �ҵ�B�и�����λ��
	for (i = l2; B[i] != root->data; i++);
	// �������ĳ���
	int llen = i - l2;
	// �������ĳ���
	int rlen = h2 - i;
	// �����������Ϊ�գ��ݹ�������
	if (llen)
		root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
	else
		root->lchild = NULL;
	// �����������Ϊ�գ��ݹ�������
	if (rlen)
		root->rchild = PreInCreate(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
	else
		root->rchild = NULL;
	return root;
}
void SolveBiTree_6() {
	char Pre[] = "0ABCDEFGHI";
	char In[] = "0BCAEDGHFI";
	BiTree BT = PreInCreate(Pre, In, 1, 9, 1, 9);
	printf("����Ϊ��");
	PreOrder(BT);
	printf("\n����Ϊ��");
	InOrder(BT);
	printf("\n����Ϊ��");
	PostOrder(BT);
}