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
LinkList HeadInsertLinkList(LinkList& L);
// 2.β�巨���������������������β�����룬��������Ԫ��˳��������˳����ͬ����Ҫһ��βָ��r������
LinkList TailInsertLinkList(LinkList& L);
// 3.����Ų��ҽ��, ���ҵ�i��Ԫ��
LNode* GetLinkListElem(LinkList L, int i);
// 4.��ֵ���ң�����ֵΪe��Ԫ��
LNode* LocateLinkListElem(LinkList L, ElemtType e);
// 5.�����㣬�ڵ�i������λ�ò���e
bool InsertLinkList(LinkList& L, int i, ElemtType e);
// 5.����������ڵ�i�����ǰ���루ǰ�壩
bool InsertLinkListAfter(LinkList& L, int i, ElemtType e);
// 6.ɾ����㣬ɾ����i����㣬�����ر�ɾ����Ԫ��
bool DeleteLinkList(LinkList& L, int i, ElemtType& e);
// 7.��ȡ������ĳ���
int LengthLinkList(LinkList L);
// 8.�п�
bool EmptyLinkList(LinkList L);
// 9.���ٵ�����
bool DestroyLinkList(LinkList& L);
// 10.��ӡ������
void PrintLinkList(LinkList L);

//��չ
// 1Un.��������ͷ���ĵ�����
void CreateUnLinkList(LinkList& L);
// 2Un.��ӡ����ͷ���ĵ�����
void PrintUnLinkList(LinkList L);

// ���ܲ���
void MainLinkList();

// ��Ŀ���
// 1.
// �������ϵĵݹ���⣬��ΪC��û�����ã����ϵ�˼���޷�ʵ��
void LinkList_DelX1(LinkList& L, ElemtType x);
// LeetCode�ϵĵݹ��뷨
LinkList LinkList_DelX2(LinkList L, ElemtType x);
void SolveLinkList1();
// 2.
// ��ͷ��βɨ�赥����preָ��ǰ���p��ǰ�����
void LinkList_DelX3(LinkList& L, ElemtType x);
// ��pָ��ɨ�����н�㣬��ֵ����x���ͷţ�������x�����ӵ�L֮��
void LinkList_DelX4(LinkList& L, ElemtType x);
void SolveLinkList2();
// 3.
// �����ӡ��ͨ���ݹ�
void RPrintLinkList(LinkList L);
void SolveLinkList3();
//4.
// ɾ����Сֵ
void DelMinLinkList(LinkList& L);
void SolveLinkList4();
//5.
// ժ��ͷ��㣬�Ե�һ��Ԫ��Ϊ��㣬����ͷ�巨���²��뽨������
void ReverseLinkList1(LinkList& L);
// ����������ÿ������ָ����ת������ԭ��һ������ָ����ΪNULL��ͷ���ָ��ԭ�����һ�����
void ReverseLinkList2(LinkList& L);
void SolveLinkList5();
//6.
// ��ֱ�Ӳ������򣬱�����㲢����
void SortLinkList(LinkList& L);
void SolveLinkList6();
//7.
// ��ͷ��βɨ�赥����preָ��ǰ���p��ǰ�����
void LinkListDelMinMax(LinkList& L, ElemtType min, ElemtType max);
void SolveLinkList7();
//8.
// �ȼ�ȥ���ĳ���dist���ٷֱ�����ҵ��������
LinkList SearchLinkList1st(LinkList L1, LinkList L2);
// ���������й�����������
void CreateComLinkList(LinkList& L1, LinkList& L2);
void SolveLinkList8();
//9.
// ���������ɾ��
void LinkListDelMinP(LinkList& L);
void SolveLinkList9();
//10.
// ������A��Ϊ��������A��ż������A
LinkList DisCreateLinkList1(LinkList& A);
void SolveLinkList10();
//11.
// ������A��Ϊ��������A�����ú��ż������B
LinkList DisCreateLinkList2(LinkList& A);
void SolveLinkList11();
//12.
// ɾ������������������ͬ��Ԫ��
void LinkListDelSame(LinkList& L);
void SolveLinkList12();

#endif // !_LINKLIST_H_
