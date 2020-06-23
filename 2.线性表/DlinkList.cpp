#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

/*
��ϸ�����Լ�������ָ�붨��
������ṹ�������������ֱ������ָ�ýṹ�壬һ����LNode��һ����LinkList
��������ʱ:Lnode s��ָ���Ǹýṹ�壻LNode *s��ָ��ýṹ���ָ�룻
		 LinkList L��ָ��ýṹ���ָ��=LNode *L��LinkList *L��ָ��ýṹ��ָ���ָ��
������L����*L��
	���������ı�ָ��L��ֵ,����ϣ�������������ú󱣴�L��ֵ,�����Ҫ��LinkList *L,����,�������ݵľ���ָ��ĵ�ַ,�������ú�,��Ȼ�Ϳ���ȥ�ı�ָ���ֵ;
	���������ֻ���޸�ָ����ָ�������,���������ָ���ֵ,��ô��LinkList L������;
*/

// 1.ͷ�巨����������ͷ������һ�����֮����룬��������Ԫ��˳��������˳���෴��ʱ�䣺o(n)
DLinkList HeadInsertDLinkList(DLinkList& L) {
	ElemtType x;
	DNode* s;
	// ��ʼ��˫��������ͷ���
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		// �������s
		s = (DNode*)malloc(sizeof(DNode));
		// ������dataΪ��ǰ�����x
		s->data = x;
		// s����ǰ��ָ��ָ��L
		s->prior = L;
		// s���ĺ���ָ��ָ��֮ǰL�ĵ�һ����㣬
		s->next = (L)->next;
		// ���֮ǰL�н�㣬L�ĵ�һ������ǰ��ָ��ָ��s���
		if (L->next != NULL)
			L->next->prior = s;
		// Lͷ���ĺ��ָ��ָ��մ����Ľ��s
		L->next = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	return L;
}
// 2.β�巨�������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r��������ʱ�䣺o(n)
DLinkList TailInsertDLinkList(DLinkList& L) {
	ElemtType x;
	// �������
	DNode* s;
	// ��ʼ��˫��������ͷ���
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// βָ��rָ���β���
	DNode* r = L;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		// ������dataΪ��ǰ�����x
		s->data = x;
		// s��ǰ��ָ��ָ��β���r
		s->prior = r;
		// β���r�ĺ��ָ��ָ���½��s
		r->next = s;
		r = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
DNode* GetDLinkListElem(DLinkList L, int i) {
	int j = 1;
	// pΪ����ָ�룬ָ���һ����һ�����
	DNode* p = L->next;
	// ��i<0�����ҷǷ�
	if (i < 0)
		return NULL;
	// ��iֵΪ0������ͷ���
	if (i == 0)
		return L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
// 4.��ֵ���ң�����ֵΪe��Ԫ��
DNode* LocateDLinkListElem(DLinkList L, ElemtType e) {
	// pΪ����ָ�룬ָ���һ����һ�����
	DNode* p = L->next;
	// pΪ�ջ��ҵ�eʱֹͣѭ��
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
// 5.�����㣬�ڵ�i������λ�ò���e�����ڵ�i-1��������루��壩
bool InsertDLinkList(DLinkList& L, int i, ElemtType e) {
	if (i < 1 || i > LengthDLinkList(L) + 1) {
		printf("����λ�ò��Ϸ�");
		return false;
	}
	// ��ȡ����λ�õ�ǰ�����p
	DNode* p = GetDLinkListElem(L, i - 1);
	 //����Ҫ����Ľ��s
	DNode* s = (DNode*)malloc(sizeof(DNode));
	s->data = e;
	// Ҫ������s�ĺ��ָ��ָ��p�ĺ�̽��
	s->next = p->next;
	// Ҫ������s��ǰ��ָ��ָ��p
	s->prior = p;
	// p�ĺ�������ǰ��ָ��ָ��Ҫ������s
	p->next->prior = s;
	// p�ĺ��ָ��ָ��Ҫ������s
	p->next = s;
	return true;
}
// 5.����������ڵ�i�����ǰ���루ǰ�壩
bool InsertDLinkListAfter(DLinkList& L, int i, ElemtType e) {
	if (i < 1 || i > LengthDLinkList(L)) {
		printf("����λ�ò��Ϸ�");
		return false;
	}
	// ��ȡ����λ�õĵ�i�����p
	DNode* p = GetDLinkListElem(L, i);
	// ����Ҫ����Ľ��s
	DNode* s = (DNode*)malloc(sizeof(DNode));
	s->data = e;
	// Ҫ������s�ĺ��ָ��ָ��p�ĺ�̽��
	s->next = p->next;
	// Ҫ������s��ǰ��ָ��ָ��p
	s->prior = p;
	// p�ĺ�������ǰ��ָ��ָ��Ҫ������s
	p->next->prior = s;
	// p�ĺ��ָ��ָ��Ҫ������s
	p->next = s;
	// ����p��s��������ʹ�����ϲ������i֮ǰ
	ElemtType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
}
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ�ص�ֵ
bool DeleteDLinkList(DLinkList& L, int i, ElemtType& e) {
	if (i<1 || i>LengthDLinkList(L)) {
		printf("Ҫɾ���Ľ�㲻����");
		return false;
	}
	// ��ȡҪɾ������ǰ�����p
	DNode* p = GetDLinkListElem(L, i - 1);
	// ��ȡҪɾ���Ľ��q
	DNode* q = p->next;
	// ��p�ĺ�̽���ΪҪɾ�����q�ĺ�̽�㣬��q���������жϿ�
	p->next = q->next;
	// Ҫɾ�����q�ĺ�̽���ǰ��ָ��ָ��p
	q->next->prior = p;
	e = q->data;
	// �ͷ�Ҫɾ�����q�Ĵ洢�ռ�
	free(q);
	return true;
}
// 7.��ȡ����ĳ���
int LengthDLinkList(DLinkList L) {
	DNode* p = L->next;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
// 8.�п�
int EmptyDLinkList(DLinkList L) {
	if (LengthDLinkList(L)) {
		return 1;
	}
	return 0;
}
// 9.��������
int DestroyDLinkList(DLinkList& L) {
	// ��ȡ��һ�����
	DNode* p = L->next;
	// ����Ҫ�ͷſռ�Ľ��Del
	DNode* Del = p;
	while (p != NULL) {
		// p�����һ�����
		p = p->next;
		// �ͷ�Del�Ŀռ�
		free(Del);
		// Del����ָ���µ�p
		Del = p;
	}
	// �ͷ�ͷ���
	free(L);
	return 1;
}
// 10.��ӡ����
void PrintDLinkList(DLinkList L) {
	printf("ͷ���<->");
	DNode* p = L->next;
	while (p != NULL) {
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// cir1.β�彨��ѭ��˫����
DLinkList TailInsertCirDLinkList(DLinkList& L) {
	ElemtType x;
	// �������
	DNode* s;
	// ��ʼ��˫��������ͷ���
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// βָ��rָ���β���
	DNode* r = L;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		// ������dataΪ��ǰ�����x
		s->data = x;
		// s��ǰ��ָ��ָ��β���r
		s->prior = r;
		// β���r�ĺ��ָ��ָ���½��s
		r->next = s;
		r = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r->next = L;
	L->prior = r;
	return L;
}

// cir2.��ӡѭ��˫����
void PrintCirDLinkList(DLinkList L) {
	printf("ͷ���<->");
	DNode* p = L->next;
	while (p != L) {
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("ͷ���\n");
}

// ����ʵ��
void MainDLinkList() {
	DLinkList L;
	// 1.ͷ�巨
	 //HeadInsertDLinkList(L);
	// 2.β�巨
	TailInsertDLinkList(L);
	printf("ԭ������Ϊ��");
	PrintDLinkList(L);
	// ���Խ���ǰ�����ָ���Ƿ�����
	//printf("%d<-%d->%d", L->next->next->prior->data, L->next->next->data, L->next->next->next->data);
	// 3.����Ų���
	DNode* p = GetDLinkListElem(L, 2);
	if (p != NULL)
		printf("���ҵڶ���Ԫ��Ϊ��%d\n", p->data);
	// 4.��ֵ����
	ElemtType e = 2;
	p = LocateDLinkListElem(L, e);
	if (p != NULL)
		printf("����ֵΪ2Ԫ��Ϊ��%d\n", p->data);
	// 5.����-���
	e = 5;
	InsertDLinkList(L, 2, e);
	printf("�ڵ�2��λ�ò���5���˫����");
	PrintDLinkList(L);
	// 5.����-ǰ��
	e = 9;
	InsertDLinkListAfter(L, 2, e);
	printf("�ڵ�2��λ��ǰ����9���˫����");
	PrintDLinkList(L);
	// 6.ɾ�����
	DeleteDLinkList(L, 3, e);
	printf("ɾ������������ֵΪ��%d��ɾ����ĵ�����Ϊ��", e);
	PrintDLinkList(L);
	// 7.��
	printf("����Ϊ��%d\n", LengthDLinkList(L));
	// 8.�п�
	if (EmptyDLinkList(L))
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n");
	// 9.����
	if (DestroyDLinkList(L))
		printf("���ٳɹ�\n");
}