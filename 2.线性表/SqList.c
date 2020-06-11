#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

// 初始化顺序表
void InitSqList(SqList* L) {
    L->length = 0;
}
void InitSeqList(SeqList* L) {
    L->data = (ElemtType*)malloc(sizeof(ElemtType) * InitSize);
    L->length = 0;
}

// 1、创造表（初始数据）；a[]为初始化数组，n为数组长度
int CreateList(SqList* L, ElemtType a[], int n) {
    if (n > MaxSize) {
        printf("No More Size");
        return 0;
    };
    for (int i = 0; i < n; i++) {
        L->data[i] = a[i];
    };
    L->length = n;
    return 1;
}
// 2、插入元素；i为插入位置，e为插入数据
int InsertList(SqList* L, int i, ElemtType e) {
    // 判断插入位置i是否在已有范围
    if (i < 1 || i > L->length + 1)
        return 0;
    // 判断原顺序表是否已经为最大长度
    if (L->length >= MaxSize)
        return 0;
    // 将第i个元素后以及以后的元素后移；j下标
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    // 插入元素
    L->data[i - 1] = e;
    L->length++;
    return 1;
}
// 3、删除元素；删除第i个元素，并返回e
int DeleteList(SqList* L, int i, ElemtType* e) {
    // 判断删除位置i是否在已有范围
    if (i < 1 || i > L->length)
        return 0;
    // 将删除元素赋值给e
    *e = L->data[i - 1];
    // 将i之后的元素向前移；j下标
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return 1;
}
// 4、按值查找元素；查找元素值为e的元素，返回位置
int LocateElem(SqList* L, ElemtType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e)
            return i + 1;
    }
    return 0;
}
// 5、按位查找元素；查找位置i的元素
ElemtType GetElem(SqList* L, int i) {
    if (i < 1 || i > L->length)
        return 0;
    return L->data[i - 1];
}
// 6、判空
int Empty(SqList* L) {
    if (L->length == 0)
        return 1;
    return 0;
}
// 7、销毁表
int DestoryList(SqList* L) {
    free(L->data);
    free(L);
    L = NULL;
    printf("this");
    return 1;
}
// 8、打印表
void PrintList(SqList* L) {
    printf("[");
    printf("%d", L->data[0]);
    for (int i = 1; i < L->length; i++) {
        printf(", %d", L->data[i]);
    };
    printf("]\n");
}

void MainList(){
    ElemtType a[5] = { 1, 2, 3, 4, 5 };
    SqList L;
    // 初始化表
    InitSqList(&L);
    // 1.创造表
    CreateList(&L, a, 5);
    printf("1、创造顺序表：");
    PrintList(&L);
    // 2.插入元素
    InsertList(&L, 2, 3);
    printf("2、插入元素：");
    PrintList(&L);
    // 3.删除元素
    ElemtType x;
    DeleteList(&L, 3, &x);
    printf("3、删除元素：[%d]被删除；", x);
    PrintList(&L);
    // 4.按值查找元素
    printf("4、按值查找元素：->%d\n", LocateElem(&L, 3));
    // 5.按位查找元素
    printf("5、按位查找元素：->%d\n", GetElem(&L, 3));
    // 6.判空
    printf("6、判空：->%d\n", Empty(&L));
    // 7.销毁(先malloc) 
    // printf("7、销毁：->%d", DestoryList(&L));
}
