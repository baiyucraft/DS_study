#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

// 1.β�巨������Ƶ�ȵ�˫����
DFLinkList TailInsertDFLinkList(DFLinkList& L) {
	ElemtType x;
	// �������
	DFNode* s;
	// ��ʼ��˫��������ͷ���
	L = (DFLinkList)malloc(sizeof(DFNode));
	L->next = NULL;
	// βָ��rָ���β���
	DFNode* r = L;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DFNode*)malloc(sizeof(DFNode));
		// ������dataΪ��ǰ�����x
		s->data = x;
		// s��ǰ��ָ��ָ��β���r
		s->pred = r;
		// Ƶ��Ĭ��Ϊ0
		s->freq = 0;
		// β���r�ĺ��ָ��ָ���½��s
		r->next = s;
		r = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 2.��ӡ��Ƶ�ȵ�˫����
void PrintDFLinkList(DFLinkList L) {
	printf("ͷ���<->");
	DFNode* p = L->next;
	while (p != NULL) {
		printf("%d(%d)<->", p->data, p->freq);
		p = p->next;
	}
	printf("NULL\n");
}

// 3.��ֵ���Ҵ�Ƶ�ȵ�˫�����㷨��
DFNode* LocateDFLinkListElem(DFLinkList& L, ElemtType e) {
	// pΪ����ָ�룬ָ���һ����һ�����
	DFNode* p = L->next;
	// ���ڲ��ұ���������Ӧ�ò����λ��
	DFNode* q;
	// pΪ�ջ��ҵ�eʱֹͣѭ��
	while (p != NULL && p->data != e) 
		p = p->next;
	if (!p) {
		printf("������ֵΪ%d�Ľ��", e);
		return NULL;
	}
	else {
		p->freq++;
		// ���p�������һ����㣬��p�ĺ�̽���ǰ�����Ϊp��ǰ�����
		if (p->next != NULL)
			p->next->pred = p->pred;
		// ��p��ǰ�����ĺ�̽��Ϊp�ĺ�̽�㣬������
		p->pred->next = p->next;
		// ��Ϊ�ǵݼ�����ģ����Դ�p��ǰ�������ǰ��ʼ���Ҳ���λ��
		q = p->pred;
		// �������ң������ѭ��������֤����λ����ͬƵ�ȵ�һ��
		while (q != L && q->freq <= p->freq)
			q = q->pred;
		// ����
		p->next = q->next;
		q->next->pred = p;
		p->pred = q;
		q->next = p;
	}
	return p;
}

void SolveDLinkList20() {
	DFLinkList L;
	TailInsertDFLinkList(L);
	printf("����Ϊ��");
	PrintDFLinkList(L);
	ElemtType e;
	printf("��������ҵ���(����9999����)��");
	scanf("%d", &e);
	while (e != 9999) {
		LocateDFLinkListElem(L, e);
		printf("���Һ������");
		PrintDFLinkList(L);
		printf("��������ҵ���(����9999����)��");
		scanf("%d", &e);
	}
}