#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// nΪ���������ľ���ֵ�ķ�Χ��������һ������ֵΪ�Ǹ�ֵ�������ռ任ʱ�䣩�ռ䣺o(m)��ʱ��o(n)
void DelAbsLinkList(LinkList& L, int n) {
	// ����ָ��p
	LNode* p = L->next;
	// Ҫɾ���Ľ��de
	LNode* del;
	// temp��ʾ��������
	int* temp, m;
	temp = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n + 1; i++)
		*(temp + i) = 0;
	// ��������
	while (p->next != NULL) {
		// m=���ж����ݵ���������ȡ������ȡ����
		m = p->next->data > 0 ? p->next->data : -p->next->data;
		if (*(temp + m) == 0) {
			*(temp + m) = 1;
			p = p->next;
		}
		else {
			del = p->next;
			p->next = del->next;
			free(del);
		}
	}
	free(temp);
}

void SolveLinkList23() {
	LinkList L;
	TailInsertLinkList(L);
	printf("ԭ����Ϊ��");
	PrintLinkList(L);
	DelAbsLinkList(L, 100);
	printf("ɾ���������Ϊ��");
	PrintLinkList(L);
}