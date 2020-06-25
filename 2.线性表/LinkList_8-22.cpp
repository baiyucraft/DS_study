#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// �ȼ�ȥ���ĳ���dist���ٷֱ�����ҵ��������
LinkList SearchLinkList1st(LinkList L1, LinkList L2) {
	// ��ȡ��������ĳ���
	int len1 = LengthLinkList(L1);
	int len2 = LengthLinkList(L2);
	// ��¼��֮��
	int dist;
	LinkList LongList, ShortList;
	if (len1 > len2) {
		LongList = L1->next;
		ShortList = L2->next;
		dist = len1 - len2;
	}
	else {
		LongList = L2->next;
		ShortList = L1->next;
		dist = len2 - len1;
	}
	// ����������ǰ���ȥ������֮�ʹ������ʣ�³������
	while (dist--) {
		LongList = LongList->next;
	}
	// ��������ʣ�µ�����
	while (LongList != NULL) {
		// ����������㷵�أ�������ϸ�ͷ��㷽�����
		if(LongList==ShortList){
			LinkList L = (LinkList)malloc(sizeof(LNode));
			L->next = LongList;
			return L;
		}
		// ��֮�ж���һ��
		else {
			LongList = LongList->next;
			ShortList = ShortList->next;
		}
	}
	return NULL;
}

// ���������й�����������
void CreateComLinkList(LinkList& L1, LinkList& L2) {
	ElemtType x;
	// �������
	LNode* s;
	// βָ��r1��r2ָ��������ı�β���
	LNode* r1 = L1->next;
	while (r1->next != NULL)
		r1 = r1->next;
	LNode* r2 = L2->next;
	while (r2->next != NULL)
		r2 = r2->next;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r1->next = s;
		r2->next = s;
		r1 = s;
		r2 = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r1->next = NULL;
	r2->next = NULL;
}

void SolveLinkList8() {
	LinkList L1, L2;
	printf("�������һ������Ĳ��������:\n");
	HeadInsertLinkList(L1);
	printf("������ڶ�������Ĳ��������:\n");
	HeadInsertLinkList(L2);
	printf("��������������Ĺ������:\n");
	CreateComLinkList(L1, L2);
	printf("L1��");
	PrintLinkList(L1);
	printf("L2��");
	PrintLinkList(L2);
	LinkList L = SearchLinkList1st(L1, L2);
	printf("��������Ĺ������Ϊ��");
	PrintLinkList(L);
}