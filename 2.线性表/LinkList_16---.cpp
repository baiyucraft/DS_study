#include <stdio.h>
#include "LinkList.h"

// �ַ���ģʽƥ���������ʽ��������������㷨��ƥ��L1�к�L2
bool PatternLinkList1(LinkList L1, LinkList L2) {
	// L1��L2�ıȽ�ָ��p1��p2
	LNode* p1 = L1->next;
	LNode* p2 = L2->next;
	//�洢��ʼ�����Ľ��
	LNode* pre = p1;
	while (p1 && p2) {
		// ��p1��ֵ��p2��ֵ��ȣ���ʼ����ƥ��
		if (p1->data == p2->data) {
			p1 = p1->next;
			p2 = p2->next;
		}
		// ����������ȵ�ֵ��p1�ص��ϴο�ʼƥ��Ľ�����һ����㣬p2��ͷ��ʼ�����±Ƚ�
		else {
			pre = pre->next;
			p1 = pre;
			p2 = L2->next;
		}
	}
	// ���p2�Ƚ���ɣ���˵���ɹ�
	if (p2 == NULL)
		return true;
	else
		return false;
}

void SolveLinkList16() {
	LinkList L1, L2;
	printf("����������L1��\n");
	TailInsertLinkList(L1);
	printf("����������L2��\n");
	TailInsertLinkList(L2);
	printf("L1Ϊ��");
	PrintLinkList(L1);
	printf("L2Ϊ��");
	PrintLinkList(L2);
	if(PatternLinkList1(L1,L2))
		printf("ƥ��ɹ�");
	else
		printf("ƥ��ʧ��");
}