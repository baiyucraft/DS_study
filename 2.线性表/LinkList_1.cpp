#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// �������ϵ���⣬��ΪC��û�����ã����ϵ�˼���޷�ʵ��
// ԭ������C++�е����ã�ͨ��ͬһ�����ô���ʵ��L->next->next�ĵݹ���ã����Բ������
// &Lʵ����һ����ַ���ݹ������һ���L->next
void LinkList_DelX1(LinkList& L, ElemtType x) {
	if (L == NULL) {
		printf("ɾ���ɹ�");
		return;
	}
	if (L->data == x) {
		LNode* p = L;
		L = L->next;
		free(p);
		LinkList_DelX1(L, x);
	}
	else {
		LinkList_DelX1(L->next, x);
	}
}
// LeetCode�ϵĵݹ��뷨
// �ݹ����ΪLΪ�գ�����L->next,��dataΪxɾ��ȥ��㷵��L->next,����һ�������򷵻�L
LinkList LinkList_DelX2(LinkList L, ElemtType x){
	if (!L)
		return L;
	L->next = LinkList_DelX2(L->next, x);
	// �������Ϊx��ɾ����㷵����һ�����
	if (L->data == x) {
		LNode* p = L;
		L = L->next;
		free(p);
		return L;
	}
	// ��֮��Ϊx�����ص�ǰ���
	return L;
}

void SolveLinkList1() {
	LinkList L;
	CreateUnLinkList(L);
	PrintUnLinkList(L);
	ElemtType x;
	printf("������Ҫɾ��������");
	scanf("%d", &x);
	LinkList_DelX1(L, x);
	//L = LinkList_DelX2(L, x);
	printf("ɾ������%d�������Ϊ��", x);
	PrintUnLinkList(L);
}