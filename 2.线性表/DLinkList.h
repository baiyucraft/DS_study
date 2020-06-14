#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
// ����Ԫ������
typedef int ElemtType;
// ˫����
typedef struct DNode {
	// ������
	ElemtType data;
	// ָ����-ǰ���ͺ��ָ��
	struct DNode* prior, * next;
}DNode, * DLinkList;

// 1.ͷ�巨������������ͷ������룬��������Ԫ��˳��������˳���෴
DLinkList HeadInsertDLinkList(DLinkList* L);
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
DLinkList TailInsertDLinkList(DLinkList* L);
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
DNode* GetDLinkListElem(DLinkList L, int i);
// 4.��ֵ���ң�����ֵΪe��Ԫ��
DNode* LocateDLinkListElem(DLinkList L, ElemtType e);
// 5.�����㣬�ڵ�i������λ�ò���e
int InsertDLinkList(DLinkList* L, int i, ElemtType e);
// 5.����������ڵ�i�����ǰ���루ǰ�壩
int InsertDLinkListAfter(DLinkList* L, int i, ElemtType e);
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ��
int DeleteDLinkList(DLinkList* L, int i, ElemtType* e);
// 7.��ȡ������ĳ���
int LengthDLinkList(DLinkList L);
// 8.�п�
int EmptyDLinkList(DLinkList L);
// 9.���ٵ�����
int DestroyDLinkList(DLinkList* L);
// 10.��ӡ������
void PrintDLinkList(DLinkList L);

// ���ܲ���
void MainDLinkList();

#endif // !_DLINKLIST_H_