#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

// 1.尾插法建立带频度的双链表
DFLinkList TailInsertDFLinkList(DFLinkList& L) {
	ElemtType x;
	// 新增结点
	DFNode* s;
	// 初始化双链表，创建头结点
	L = (DFLinkList)malloc(sizeof(DFNode));
	L->next = NULL;
	// 尾指针r指向表尾结点
	DFNode* r = L;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DFNode*)malloc(sizeof(DFNode));
		// 数据域data为当前输入的x
		s->data = x;
		// s的前驱指针指向尾结点r
		s->pred = r;
		// 频度默认为0
		s->freq = 0;
		// 尾结点r的后继指针指向新结点s
		r->next = s;
		r = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 2.打印带频度的双链表
void PrintDFLinkList(DFLinkList L) {
	printf("头结点<->");
	DFNode* p = L->next;
	while (p != NULL) {
		printf("%d(%d)<->", p->data, p->freq);
		p = p->next;
	}
	printf("NULL\n");
}

// 3.按值查找带频度的双链表（算法）
DFNode* LocateDFLinkListElem(DFLinkList& L, ElemtType e) {
	// p为查找指针，指向第一个第一个结点
	DFNode* p = L->next;
	// 用于查找遍历后排序应该插入的位置
	DFNode* q;
	// p为空或找到e时停止循环
	while (p != NULL && p->data != e) 
		p = p->next;
	if (!p) {
		printf("不存在值为%d的结点", e);
		return NULL;
	}
	else {
		p->freq++;
		// 如果p不是最后一个结点，将p的后继结点的前驱结点为p的前驱结点
		if (p->next != NULL)
			p->next->pred = p->pred;
		// 将p的前驱结点的后继结点为p的后继结点，即断链
		p->pred->next = p->next;
		// 因为是递减排序的，所以从p的前驱结点向前开始查找插入位置
		q = p->pred;
		// 遍历查找，后面的循环条件保证插入位置在同频度第一个
		while (q != L && q->freq <= p->freq)
			q = q->pred;
		// 插入
		p->next = q->next;
		q->next->pred = p;
		p->pred = q;
		q->next = p;
	}
	return p;
}

void SolveDLinkList20() {
	DFLinkList L;
	TailInsertDFLinkList(L);
	printf("链表为：");
	PrintDFLinkList(L);
	ElemtType e;
	printf("请输入查找的数(输入9999结束)：");
	scanf("%d", &e);
	while (e != 9999) {
		LocateDFLinkListElem(L, e);
		printf("查找后的链表：");
		PrintDFLinkList(L);
		printf("请输入查找的数(输入9999结束)：");
		scanf("%d", &e);
	}
}