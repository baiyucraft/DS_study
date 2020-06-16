#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
��ϸ�����Լ�������ָ�붨��
������ṹ�������������ֱ������ָ�ýṹ�壬һ����LNode��һ����LinkList
��������ʱ:Lnode s��ָ���Ǹýṹ�壻LNode *s��ָ��ýṹ���ָ�룻
	     LinkList L��ָ��ýṹ���ָ��=LNode *L��LinkList *L��ָ��ýṹ��ָ���ָ��
������L����*L��
	���������ı�ָ��L��ֵ,����ϣ�������������ú󱣴�L��ֵ,�����Ҫ��LinkList *L,����,�������ݵľ���ָ��ĵ�ַ,�������ú�,��Ȼ�Ϳ���ȥ�ı�ָ���ֵ;
	���������ֻ���޸�ָ����ָ�������,���������ָ���ֵ,��ô��LinkList L������;
*/

// 1.ͷ�巨������������ͷ������һ�����֮����룬��������Ԫ��˳��������˳���෴��ʱ�䣺o(n)
LinkList HeadInsertLinkList(LinkList* L) {
	ElemtType x; 
	LNode* s;
	// ��ʼ������������ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		// �������s��dataΪ��ǰ�����x������ָ����ָ��L�ĵ�һ����㣬Lͷ����ָ����ָ��մ����Ľ��s
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	return *L;
}
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r��������ʱ�䣺o(n)
LinkList TailInsertLinkList(LinkList* L) {
	ElemtType x;
	// �������
	LNode* s;
	// ��ʼ������������ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	// βָ��rָ���β���
	LNode* r = *L;
	// ��������
	printf("��������(����9999����)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
LNode* GetLinkListElem(LinkList L, int i) {
	int j = 1;
	// pΪ����ָ�룬ָ���һ����һ�����
	LNode* p = L->next;
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
LNode* LocateLinkListElem(LinkList L, ElemtType e) {
	// pΪ����ָ�룬ָ���һ����һ�����
	LNode* p = L->next;
	// pΪ�ջ��ҵ�eʱֹͣѭ��
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
// 5.�����㣬�ڵ�i������λ�ò���e�����ڵ�i-1��������루��壩
int InsertLinkList(LinkList* L, int i, ElemtType e) {
	if (i < 1 || i > LengthLinkList(*L) + 1) {
		printf("����λ�ò��Ϸ�");
		return 0;
	}
	// ��ȡ����λ�õ�ǰ�����p
	LNode* p = GetLinkListElem(*L, i - 1);
	// ����Ҫ����Ľ��s
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	// Ҫ������s��ָ����ָ��p�ĺ�̽��
	s->next = p->next;
	// ǰ������ָ����ָ��Ҫ������s
	p->next = s;
	return 1;
}
// 5.����������ڵ�i�����ǰ���루ǰ�壩
int InsertLinkListAfter(LinkList* L, int i, ElemtType e) {
	if (i < 1 || i > LengthLinkList(*L)) {
		printf("����λ�ò��Ϸ�");
		return 0;
	}
	// ��ȡ����λ�õĵ�i�����p
	LNode* p = GetLinkListElem(*L, i);
	// ����Ҫ����Ľ��s
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	// Ҫ������s��ָ����ָ��p�ĺ�̽��
	s->next = p->next;
	// p��ָ����ָ��Ҫ������s����ʱ��p��s��ǰһ����㣬�൱��β��
	p->next = s;
	// ����p��s��������ʹ�����ϲ������i֮ǰ
	ElemtType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return 1;
}
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ�ص�ֵ
int DeleteLinkList(LinkList* L, int i, ElemtType* e) {
	if (i<1 || i>LengthLinkList(*L)) {
		printf("Ҫɾ���Ľ�㲻����");
		return 0;
	}
	// ��ȡҪɾ������ǰ�����p
	LNode* p = GetLinkListElem(*L, i - 1);
	// ��ȡҪɾ���Ľ��q
	LNode* q = p->next;
	// ��p�ĺ�̽���ΪҪɾ�����q�ĺ�̽�㣬��q���������жϿ�
	p->next = q->next;
	*e = q->data;
	// �ͷ�Ҫɾ�����q�Ĵ洢�ռ�
	free(q);
	return 1;
}
// 7.��ȡ������ĳ���
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i=0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
// 8.�п�
int EmptyLinkList(LinkList L) {
	if (LengthLinkList(L)) {
		return 1;
	}
	return 0;
}
// 9.���ٵ�����
int DestroyLinkList(LinkList* L) {
	// ��ȡ��һ�����
	LNode* p = (*L)->next;
	// ����Ҫ�ͷſռ�Ľ��Del
	LNode* Del = p;
	while (p != NULL) {
		// p�����һ�����
		p = p->next;
		// �ͷ�Del�Ŀռ�
		free(Del);
		// Del����ָ���µ�p
		Del = p;
	}
	// �ͷ�ͷ���
	free(*L);
	return 1;
}
// 10.��ӡ������
void PrintLinkList(LinkList L) {
	printf("ͷ���->");
	LNode* p = L->next;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// 1Un.��������ͷ���ĵ�����
void CreateUnLinkList(LinkList* L) {
	ElemtType x;
	LNode* s;
	*L = (LinkList)malloc(sizeof(LNode));
	printf("��������(����9999����)��");
	scanf("%d", &x);
	(*L)->data = x;
	printf("��������(����9999����)��");
	scanf("%d", &x);
	LNode* r = *L;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		printf("��������(����9999����)��");
		scanf("%d", &x);
	}
	r->next = NULL;
}

// 2Un.��ӡ����ͷ���ĵ�����
void PrintUnLinkList(LinkList L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// ����ʵ��
void MainLinkList() {
	LinkList L;
	// 1.ͷ�巨
	// HeadInsertLinkList(&L);
	// 2.β�巨
	TailInsertLinkList(&L);
	printf("ԭ������Ϊ��");
	PrintLinkList(L);
	// 3.����Ų���
	LNode* p = GetLinkListElem(L, 2);
	if (p != NULL)
		printf("���ҵڶ���Ԫ��Ϊ��%d\n", p->data);
	// 4.��ֵ����
	ElemtType e = 2;
	p = LocateLinkListElem(L, e);
	if (p != NULL)
		printf("����ֵΪ2Ԫ��Ϊ��%d\n", p->data);
	// 5.����-���
	e = 5;
	InsertLinkList(&L, 2, e);
	printf("�ڵ�2��λ�ò���5��ĵ�����");
	PrintLinkList(L);
	// 5.����-ǰ��
	e = 9;
	InsertLinkListAfter(&L, 2, e);
	printf("�ڵ�2��λ��ǰ����9��ĵ�����");
	PrintLinkList(L);
	// 6.ɾ�����
	DeleteLinkList(&L, 3, &e);
	printf("ɾ������������ֵΪ��%d��ɾ����ĵ�����Ϊ��", e);
	PrintLinkList(L);
	// 7.��
	printf("����Ϊ��%d\n", LengthLinkList(L));
	// 8.�п�
	if (EmptyLinkList(L))
		printf("����Ϊ��\n");
	else
		printf("����Ϊ��\n"); 
	// 9.����
	if(DestroyLinkList(&L))
		printf("���ٳɹ�\n");
}

