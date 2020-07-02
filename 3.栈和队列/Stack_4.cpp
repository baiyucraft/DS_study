#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// β�彨���ַ�������
LinkList TailInsertLinkList(LinkList& L) {
	char x;
	// �������
	LNode* s;
	// ��ʼ������������ͷ���
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	// βָ��rָ���β���
	LNode* r = L;
	// �������ݣ����磺abads!
	printf("������һ���ַ���(��!��β)��");
	scanf("%c", &x);
	while (x != '!') {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%c", &x);
	}
	r->next = NULL;
	return L;
}
// ��ӡ�ַ�������
void PrintLinkList(LinkList L) {
	printf("ͷ���->");
	LNode* p = L->next;
	while (p != NULL) {
		printf("%c->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
// ��ȡ�ַ�����������
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

// �ж�����ȫ��n���ַ��Ƿ����ĶԳ�
bool dcStackLinkList(LinkList L, int n) {
	int i;
	// ����ջ
	char* s = (char*)malloc(sizeof(char) * (n / 2));
	// �����Ĺ���ָ��
	LNode *p = L->next;
	for (i = 0; i < n / 2; i++) {
		s[i] = p->data;
		p = p->next;
	}
	// �ָ�֮ǰ��iֵ
	i--;
	// �ж��Ƿ�Ϊ��������Ϊ�������������Ľ��
	if (n % 2 == 1)
		p = p->next;
	while (p != NULL && s[i] == p->data) {
		i--;
		p = p->next;
	}
	// ջ�մ���Գ�
	if (i == -1)
		return true;
	else
		return false;
}

void SolveStack_4() {
	LinkList L;
	TailInsertLinkList(L);
	printf("�ַ�������Ϊ��");
	PrintLinkList(L);
	int n = LengthLinkList(L);
	if (dcStackLinkList(L, n))
		printf("���ĶԳ�");
	else
		printf("�����ĶԳ�");

}