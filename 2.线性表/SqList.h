#ifndef _SQLIST_H_
#define _SQLIST_H_

#define MaxSize 50
#define InitSize 100
// ����Ԫ������
typedef int ElemtType;
// ��̬����
typedef struct {
    int data[MaxSize];
    int length;
}SqList;
// ��̬����    //��ʼ����
typedef struct {
    int* data;              // ��̬���������ָ��
    int MaxS, length;    // ��������͸���
} SeqList;                  // ��̬���䡢˳�������Ͷ���

// ��ʼ��˳���
void InitSqList(SqList* L);
// 1���������ʼ���ݣ���a[]Ϊ��ʼ�����飬nΪ���鳤��
int CreateList(SqList* L, ElemtType a[], int n);
// 2������Ԫ�أ�iΪ����λ�ã�eΪ��������
int InsertList(SqList* L, int i, ElemtType e);
// 3��ɾ��Ԫ�أ�ɾ����i��Ԫ�أ�������e
int DeleteList(SqList * L, int i, ElemtType * e);
// 4����ֵ����Ԫ�أ�����Ԫ��ֵΪe��Ԫ�أ�����λ��
int LocateElem(SqList* L, ElemtType e);
// 5����λ����Ԫ�أ�����λ��i��Ԫ��
ElemtType GetElem(SqList* L, int i);
// 6���п�
int Empty(SqList* L);
// 7�����ٱ�
int DestoryList(SqList* L);
// 8����ӡ��
void PrintList(SqList* L);

//���ܲ���
void MainList();

// ��Ŀ���
// 1.
int DelMin(SqList* L, ElemtType* e);
void Solve1();
// 2.
void Inversion(SqList* L);
void Solve2();
// 3.
void DelX1(SqList* L, ElemtType x);
void DelX2(SqList* L, ElemtType x);
void Solve3();
#endif // !_SQLIST_H_