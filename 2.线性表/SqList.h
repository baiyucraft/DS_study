// 顺序表
#ifndef _SQLIST_H_
#define _SQLIST_H_

#define MaxSize 50
#define InitSize 100
// 定义元素类型
typedef int ElemtType;
// 静态分配
typedef struct {
    int data[MaxSize];
    int length;
}SqList;
// 动态分配                   //初始长度
typedef struct {
    int* data;              // 动态分配数组的指针
    int MaxS, length;       // 最大容量和当前长度
} SeqList;                  // 动态分配、顺序表的类型定义

// 初始化顺序表
void InitSqList(SqList* L);
// 1、创造表（初始数据）；a[]为初始化数组，n为数组长度
int CreateSqList(SqList* L, ElemtType a[], int n);
// 2、插入元素；i为插入位置，e为插入数据
int InsertSqList(SqList* L, int i, ElemtType e);
// 3、删除元素；删除第i个元素，并返回e
int DeleteSqList(SqList* L, int i, ElemtType* e);
// 4、按值查找元素；查找元素值为e的元素，返回位置
int LocateSqListElem(SqList* L, ElemtType e);
// 5、按位查找元素；查找位置i的元素
ElemtType GetSqListElem(SqList* L, int i);
// 6、判空
int EmptySqList(SqList* L);
// 7、销毁表
int DestorySqList(SqList* L);
// 8、打印表
void PrintSqList(SqList* L);

// 功能测试
void MainSqList();

// 题目解答
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
// 4.5.(思想一样)
    // 自己写法
int DelS_T1(SqList * L, ElemtType s, ElemtType t);
    // 答案写法
int DelS_T2(SqList * L, ElemtType s, ElemtType t);
void SolveSqlist_4();
// 6.
int DelSame(SqList * L);
void SolveSqlist_6();
// 7.
SqList Merge(SqList * L1, SqList * L2);
void SolveSqlist_7();
// 8.
// 将顺序表L的第left元素开始到第right元素逆置
void Reverse(SqList * L, int left, int right);
// 将前m项和后n项分别逆置
void ReverseMN(SqList * L, int m, int n);
void SolveSqlist_8();
// 9.
void SearchX(SqList * L, ElemtType x);
void SolveSqlist_9();
// 11.
// 空间上不高效（合并然后找中位数）时间o（n），空间o（2n）
ElemtType MidNum1(SqList * L1, SqList * L2);
// 分别取中位数比较（空间高效）--答案题解 时间o（log2 n），空间o（1）
ElemtType MidNum2(SqList * L1, SqList * L2);
void SolveSqlist_11();
// 12.
ElemtType Majarity(SqList * L);
void SolveSqlist_12();
// 13.
ElemtType FindMissMin(SqList * L);
void SolveSqlist_13();
#endif // !_SQLIST_H_