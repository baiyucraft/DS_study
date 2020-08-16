#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

typedef struct {
	BiTNode* t;
	// tag=0��ʾ�����������ʣ�tag=1��ʾ������������
	int tag;
}stack;

// 12.��Ԫ��ֵΪx�Ľ������Ƚ��
void SearchXParent(BiTree T, ElemtType x) {
	stack S[255]; 
	int top = 0;
	BiTNode* p = T;
	// ��������������
	while (p != NULL || top > 0) {
		// ����㲻Ϊ�ղ������ݲ�Ϊxʱ��ջ
		while (p != NULL && p->data != x) {
			S[++top].t = p;
			S[top].tag = 0;
			// ����������
			p = p->lchild;
		}
		// ���ֵΪx���ҵ�x����ӡ    (��������ϼ��˸���������Ȼ�޷����У���NULL��)
		if (p != NULL && p->data == x) {
			printf("��������������Ƚ��Ϊ��");
			for (int i = 1; i <= top; i++)
				printf("%c", S[i].t->data);
			exit(1);
		}
		// ��ջ�����������ʹ����ˣ�
		while (top != 0 && S[top].tag == 1)
			top--;
		// ������������
		if (top != 0) {
			S[top].tag = 1;
			p = S[top].t->rchild;
		}
	}
}
void SolveBiTree_12() {
	BiTree BT;
	CreateBiTree(BT);
	printf("ԭ������Ϊ��");
	PreOrder(BT);
	printf("\nԭ������Ϊ��");
	InOrder(BT);
	printf("\nԭ������Ϊ��");
	PostOrder(BT);

	printf("\n\n��E��-");
	SearchXParent(BT, 'E');
}