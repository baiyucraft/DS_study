#include <stdio.h>
#include "DLinkList.h"

// �б�ѭ��˫�����Ƿ�Գ�
bool SymmertryCirDLinkList(DLinkList L) {
	// ͷ����ָ��p
	DNode* p = L->next;
	// β����ָ��q
	DNode* q = L->prior;
	// ����ʱp=q��ż��ʱq->next=p��(����p->next=q����Ϊ������û�бȽ�����������ֱ��ֹͣ��)
	while (p != q && q->next != p) {
		if (p->data == q->data) {
			p = p->next;
			q = q->prior;
		}
		else
			return false;
	}
	return true;
}

void SolveDLinkList17() {
	DLinkList L;
	TailInsertCirDLinkList(L);
	printf("ѭ��˫����Ϊ��");
	PrintCirDLinkList(L);
	if (SymmertryCirDLinkList(L))
		printf("�Գ�");
	else
		printf("���Գ�");
}