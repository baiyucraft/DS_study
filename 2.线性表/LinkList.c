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

// 1.ͷ�巨������������ͷ������룬��������Ԫ��˳��������˳���෴
LinkList HeadInsertList(LinkList* L) {
	LNode* s;
	int x;
	// ��ʼ������������ͷ���
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("��������(9999��������)��");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("��������(9999��������)��");
		scanf("%d", &x);
	}
	return *L;
}
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
LinkList TailInsertList(LinkList* L) {

}

// ���������
void PrintLinkList(LinkList L) {
	LNode* p = L->next;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void MainLinkList() {
	LinkList L;
	HeadInsertList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
}