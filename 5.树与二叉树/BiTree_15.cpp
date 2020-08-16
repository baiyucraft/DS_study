#include <stdio.h>
#include "BiTree.h"

// 15.�����������������õ������ݹ�ֱ���������
void PreToPost(ElemtType Pre[], int l1, int h1, ElemtType Post[], int l2, int h2) {
	int half;
	if (h1 >= l1) {
		Post[h2] = Pre[l1];
		half = (h1 - l1) / 2;
		// ת��������
		PreToPost(Pre, l1 + 1, l1 + half, Post, l2, l2 + half - 1);
		// ת��������
		PreToPost(Pre, l1 + half + 1, h1, Post, l2 + half, h2 - 1);
	}
}
void SolveBiTree_15() {
	ElemtType Pre[8] = "ABCDEFG";
	ElemtType Post[8];
	PreToPost(Pre, 0, 6, Post, 0, 6);
	printf("��������Ϊ��");
	for (int i = 0; i <= 6; i++)
		printf("%c->", Post[i]);
}