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

// ��Ƶ�ȵ�˫����
typedef struct DFNode {
	// ������
	ElemtType data;
	// ָ����-ǰ���ͺ��ָ��
	struct DFNode* pred, * next;
	// Ƶ��
	int freq;
}DFNode, * DFLinkList;

// 1.ͷ�巨����������ͷ������룬��������Ԫ��˳��������˳���෴
DLinkList HeadInsertDLinkList(DLinkList& L);
// 2.β�巨�������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
DLinkList TailInsertDLinkList(DLinkList& L);
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
DNode* GetDLinkListElem(DLinkList L, int i);
// 4.��ֵ���ң�����ֵΪe��Ԫ��
DNode* LocateDLinkListElem(DLinkList L, ElemtType e);
// 5.�����㣬�ڵ�i������λ�ò���e
bool InsertDLinkList(DLinkList& L, int i, ElemtType e);
// 5.����������ڵ�i�����ǰ���루ǰ�壩
bool InsertDLinkListAfter(DLinkList& L, int i, ElemtType e);
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ��
bool DeleteDLinkList(DLinkList& L, int i, ElemtType& e);
// 7.��ȡ����ĳ���
int LengthDLinkList(DLinkList L);
// 8.�п�
int EmptyDLinkList(DLinkList L);
// 9.��������
int DestroyDLinkList(DLinkList& L);
// 10.��ӡ������
void PrintDLinkList(DLinkList L);

// ѭ��˫�����ֹ���
// cir1.β�彨��ѭ��˫����
DLinkList TailInsertCirDLinkList(DLinkList& L);
// cir2.��ӡѭ��˫����
void PrintCirDLinkList(DLinkList L);

// ���ܲ���
void MainDLinkList();

// 17.
// �б�˫�����Ƿ�Գ�
bool SymmertryCirDLinkList(DLinkList L);
void SolveDLinkList17();
// 20.
// 1.β�巨������Ƶ�ȵ�˫����
DFLinkList TailInsertDFLinkList(DFLinkList& L);
// 2.��ӡ��Ƶ�ȵ�˫����
void PrintDFLinkList(DFLinkList L);
// 3.��ֵ���Ҵ�Ƶ�ȵ�˫�����㷨��
DFNode* LocateDFLinkListElem(DFLinkList& L, ElemtType e);
void SolveDLinkList20();

#endif // !_DLINKLIST_H_