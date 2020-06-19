#include <stdio.h>
#include "LinkList.h"

// ժ��ͷ��㣬�Ե�һ��Ԫ��Ϊ��㣬����ͷ�巨���²��뽨������
void ReverseLinkList1(LinkList* L) {
	// ���幤�����p��������������
	LNode* p = (*L)->next;
	// r�����洢p�ĺ�̽��
	LNode* r;
	// �Ͽ�ͷ���
	(*L)->next = NULL;
	// ��������
	while (p != NULL) {
		// ����p�ĺ�̽��r
		r = p->next;
		// p�ĺ�̽��Ϊ�½�����ĵ�һ�����
		p->next = (*L)->next;
		// ͷ������һ�����Ϊp
		(*L)->next = p;
		// ������������
		p = r;
	}
}
// ����������ÿ������ָ����ת������ԭ��һ������ָ����ΪNULL��ͷ���ָ��ԭ�����һ�����
void ReverseLinkList2(LinkList* L) {
	// �������p
	LNode* p = (*L)->next;
	// p��ǰ�����pre
	LNode* pre;
	// p�ĺ�̽��r
	LNode* r = p->next;
	// �����һ�����
	p->next = NULL;
	// p�ĺ�̽�㲻Ϊ��Ϊ����
	while (r != NULL) {
		// ��p�ĺ�̽��r��ָ����ָ��p
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	(*L)->next = p;
}
void SolveLinkList5() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	ReverseLinkList1(&L);
	printf("���ú������Ϊ��");
	PrintLinkList(L);
	ReverseLinkList2(&L);
	printf("���ú������Ϊ��");
	PrintLinkList(L);
}