// ˳���
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
// ��̬����                   //��ʼ����
typedef struct {
    int* data;              // ��̬���������ָ��
    int MaxS, length;       // ��������͵�ǰ����
} SeqList;                  // ��̬���䡢˳�������Ͷ���

// ��ʼ��˳���
void InitSqList(SqList* L);
// 1���������ʼ���ݣ���a[]Ϊ��ʼ�����飬nΪ���鳤��
int CreateSqList(SqList* L, ElemtType a[], int n);
// 2������Ԫ�أ�iΪ����λ�ã�eΪ��������
int InsertSqList(SqList* L, int i, ElemtType e);
// 3��ɾ��Ԫ�أ�ɾ����i��Ԫ�أ�������e
int DeleteSqList(SqList* L, int i, ElemtType* e);
// 4����ֵ����Ԫ�أ�����Ԫ��ֵΪe��Ԫ�أ�����λ��
int LocateSqListElem(SqList* L, ElemtType e);
// 5����λ����Ԫ�أ�����λ��i��Ԫ��
ElemtType GetSqListElem(SqList* L, int i);
// 6���п�
int EmptySqList(SqList* L);
// 7�����ٱ�
int DestorySqList(SqList* L);
// 8����ӡ��
void PrintSqList(SqList* L);

// ���ܲ���
void MainSqList();

// ��Ŀ���
// 1.
int DelMin(SqList * L, ElemtType * e);
void SolveSqlist_1();
// 2.
void Inversion(SqList * L);
void SolveSqlist_2();
// 3.
void DelX1(SqList * L, ElemtType x);
void DelX2(SqList * L, ElemtType x);
void SolveSqlist_3();
// 4.5.(˼��һ��)
    // �Լ�д��
int DelS_T1(SqList * L, ElemtType s, ElemtType t);
    // ��д��
int DelS_T2(SqList * L, ElemtType s, ElemtType t);
void SolveSqlist_4();
// 6.
int DelSame(SqList * L);
void SolveSqlist_6();
// 7.
SqList Merge(SqList * L1, SqList * L2);
void SolveSqlist_7();
// 8.
// ��˳���L�ĵ�leftԪ�ؿ�ʼ����rightԪ������
void Reverse(SqList * L, int left, int right);
// ��ǰm��ͺ�n��ֱ�����
void ReverseMN(SqList * L, int m, int n);
void SolveSqlist_8();
// 9.
void SearchX(SqList * L, ElemtType x);
void SolveSqlist_9();
// 11.
// �ռ��ϲ���Ч���ϲ�Ȼ������λ����ʱ��o��n�����ռ�o��2n��
ElemtType MidNum1(SqList * L1, SqList * L2);
// �ֱ�ȡ��λ���Ƚϣ��ռ��Ч��--����� ʱ��o��log2 n�����ռ�o��1��
ElemtType MidNum2(SqList * L1, SqList * L2);
void SolveSqlist_11();
// 12.
ElemtType Majarity(SqList * L);
void SolveSqlist_12();
// 13.
ElemtType FindMissMin(SqList * L);
void SolveSqlist_13();
#endif // !_SQLIST_H_