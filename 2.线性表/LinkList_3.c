#include <stdio.h>
#include "LinkList.h"

// �����ӡ��ͨ���ݹ�
void RPrintLinkList(LinkList L){
	// �ݹ���ڣ������һ�����Ϊ�գ���ֹͣ
	if (L->next != NULL) 
		RPrintLinkList(L->next);
	// �����ǰ��㲻Ϊ�գ���ӡ����
	if (L != NULL)
		printf("<-%d", L->data);
}

void SolveLinkList3() {
	LinkList L;
	TailInsertLinkList(&L);
	printf("��������Ϊ��");
	PrintLinkList(L);
	printf("������Ϊ��");
	// ��next��ֹ��ӡͷ���
	RPrintLinkList(L->next);
}