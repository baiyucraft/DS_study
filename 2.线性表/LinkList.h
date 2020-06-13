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
LinkList HeadInsertLinkList(LinkList* L);
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
LinkList TailInsertLinkList(LinkList* L);
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
LNode* GetLinkListElem(LinkList L, int i);
// 4.��ֵ���ң�����ֵΪe��Ԫ��
LNode* LocateLinkListElem(LinkList L, ElemtType e);
// 5.�����㣬�ڵ�i������λ�ò���e
int InsertLinkList(LinkList* L, int i, ElemtType e);
// 5.����������ڵ�i�����ǰ���루ǰ�壩
int InsertLinkListAfter(LinkList* L, int i, ElemtType e);
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ��
int DeleteLinkList(LinkList* L, int i, ElemtType* e);
// 7.��ȡ������ĳ���
int LengthLinkList(LinkList L);
// 8.�п�
int EmptyLinkList(LinkList L);
// 9.���ٵ�����
int DestroyLinkList(LinkList* L);
// 10.��ӡ������
void PrintLinkList(LinkList L);

// ���ܲ���
void MainLinkList();
#endif // !_LINKLIST_H_
