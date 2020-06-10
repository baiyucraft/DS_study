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
// 动态分配    //初始长度
typedef struct {
    int* data;              // 动态分配数组的指针
    int MaxS, length;    // 最大容量和个数
} SeqList;                  // 动态分配、顺序表的类型定义

// 初始化顺序表
void InitSqList(SqList* L);
// 1、创造表（初始数据）；a[]为初始化数组，n为数组长度
int CreateList(SqList* L, ElemtType a[], int n);
// 2、插入元素；i为插入位置，e为插入数据
int InsertList(SqList* L, int i, ElemtType e);
// 3、删除元素；删除第i个元素，并返回e
int DeleteList(SqList * L, int i, ElemtType * e);
// 4、按值查找元素；查找元素值为e的元素，返回位置
int LocateElem(SqList* L, ElemtType e);
// 5、按位查找元素；查找位置i的元素
ElemtType GetElem(SqList* L, int i);
// 6、判空
int Empty(SqList* L);
// 7、销毁表
int DestoryList(SqList* L);
// 8、打印表
void PrintList(SqList* L);

//功能测试
void MainList();

// 题目解答
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