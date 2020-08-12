#include <stdio.h>
#include "BiTree.h"

// ��ʼ�ӵ�һ����ʼ��
int i = 1;

// 10.���������k����ֵ
ElemtType PreNode(BiTree T, int k) {
	if (T == NULL)
		return '#';
	if (i == k)
		return T->data;
	// ��һ�����
	i++;
	// �������ݹ�Ѱ��
	char ch = PreNode(T->lchild, k);
	if (ch != '#')
		return ch;
	// ���������еݹ�Ѱ��
	ch = PreNode(T->rchild, k);
	return ch;
}
void SolveBiTree_10() {
	BiTree BT;
	CreateBiTree(BT);
	printf("�������Ϊ��");
	PreOrder(BT);
	printf("��������µ�5������ֵΪ��%c", PreNode(BT, 5));
}