// ������
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
// ����Ԫ������
typedef int ElemtType;
// ������
typedef struct LNode {
	// ������
	ElemtType data;
	// ָ����
	struct LNode* next;
}LNode, * LinkList;

// 1.ͷ�巨������������ͷ������룬��������Ԫ��˳��������˳���෴
LinkList HeadInsertList(LinkList* L);
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
LinkList TailInsertList(LinkList* L);

// ���������
void PrintLinkList(LinkList L);


// ���ܲ���
void MainLinkList();
#endif // !_LINKLIST_H_
