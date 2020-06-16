#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/*
详细讲述自己所理解的指针定义
单链表结构体声明中有两种别称来代指该结构体，一种是LNode，一种是LinkList
变量声明时:Lnode s：指的是该结构体；LNode *s：指向该结构体的指针；
	     LinkList L：指向该结构体的指针=LNode *L；LinkList *L：指向该结构体指针的指针
关于用L还是*L：
	如果函数会改变指针L的值,而你希望函数结束调用后保存L的值,那你就要用LinkList *L,这样,向函数传递的就是指针的地址,结束调用后,自然就可以去改变指针的值;
	而如果函数只会修改指针所指向的内容,而不会更改指针的值,那么用LinkList L就行了;
*/

// 1.头插法建立单链表：在头结点与第一个结点之间插入，生成链表元素顺序与输入顺序相反，时间：o(n)
LinkList HeadInsertLinkList(LinkList* L) {
	ElemtType x; 
	LNode* s;
	// 初始化单链表、创建头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		// 创建结点s，data为当前输入的x，结点的指针域指向L的第一个结点，L头结点的指针域指向刚创建的结点s
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	return *L;
}
// 2.尾插法建立单链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助），时间：o(n)
LinkList TailInsertLinkList(LinkList* L) {
	ElemtType x;
	// 新增结点
	LNode* s;
	// 初始化单链表，创建头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	// 尾指针r指向表尾结点
	LNode* r = *L;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r->next = NULL;
	return *L;
}
// 3.按序号查找结点, 查找第i个元素
LNode* GetLinkListElem(LinkList L, int i) {
	int j = 1;
	// p为查找指针，指向第一个第一个结点
	LNode* p = L->next;
	// 若i<0，查找非法
	if (i < 0)
		return NULL;
	// 若i值为0，返回头结点
	if (i == 0)
		return L;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
// 4.按值查找，查找值为e的元素
LNode* LocateLinkListElem(LinkList L, ElemtType e) {
	// p为查找指针，指向第一个第一个结点
	LNode* p = L->next;
	// p为空或找到e时停止循环
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
// 5.插入结点，在第i个结点的位置插入e，即在第i-1个结点后插入（后插）
int InsertLinkList(LinkList* L, int i, ElemtType e) {
	if (i < 1 || i > LengthLinkList(*L) + 1) {
		printf("插入位置不合法");
		return 0;
	}
	// 获取插入位置的前驱结点p
	LNode* p = GetLinkListElem(*L, i - 1);
	// 创造要插入的结点s
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	// 要插入结点s的指针域指向p的后继结点
	s->next = p->next;
	// 前驱结点的指针域指向要插入结点s
	p->next = s;
	return 1;
}
// 5.插入操作，在第i个结点前插入（前插）
int InsertLinkListAfter(LinkList* L, int i, ElemtType e) {
	if (i < 1 || i > LengthLinkList(*L)) {
		printf("插入位置不合法");
		return 0;
	}
	// 获取插入位置的第i个结点p
	LNode* p = GetLinkListElem(*L, i);
	// 创造要插入的结点s
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	// 要插入结点s的指针域指向p的后继结点
	s->next = p->next;
	// p的指针域指向要插入结点s，这时候p是s的前一个结点，相当于尾插
	p->next = s;
	// 交换p、s的数据域，使数据上插入的在i之前
	ElemtType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return 1;
}
// 6.删除结点，删除第i个结点，并返回被删除的元素的值
int DeleteLinkList(LinkList* L, int i, ElemtType* e) {
	if (i<1 || i>LengthLinkList(*L)) {
		printf("要删除的结点不存在");
		return 0;
	}
	// 获取要删除结点的前驱结点p
	LNode* p = GetLinkListElem(*L, i - 1);
	// 获取要删除的结点q
	LNode* q = p->next;
	// 将p的后继结点变为要删除结点q的后继结点，即q结点从链表中断开
	p->next = q->next;
	*e = q->data;
	// 释放要删除结点q的存储空间
	free(q);
	return 1;
}
// 7.获取单链表的长度
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i=0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
// 8.判空
int EmptyLinkList(LinkList L) {
	if (LengthLinkList(L)) {
		return 1;
	}
	return 0;
}
// 9.销毁单链表
int DestroyLinkList(LinkList* L) {
	// 获取第一个结点
	LNode* p = (*L)->next;
	// 给定要释放空间的结点Del
	LNode* Del = p;
	while (p != NULL) {
		// p变成下一个结点
		p = p->next;
		// 释放Del的空间
		free(Del);
		// Del重新指向新的p
		Del = p;
	}
	// 释放头结点
	free(*L);
	return 1;
}
// 10.打印单链表
void PrintLinkList(LinkList L) {
	printf("头结点->");
	LNode* p = L->next;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// 1Un.创建不带头结点的单链表
void CreateUnLinkList(LinkList* L) {
	ElemtType x;
	LNode* s;
	*L = (LinkList)malloc(sizeof(LNode));
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	(*L)->data = x;
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	LNode* r = *L;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r->next = NULL;
}

// 2Un.打印不带头结点的单链表
void PrintUnLinkList(LinkList L) {
	LNode* p = L;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// 功能实现
void MainLinkList() {
	LinkList L;
	// 1.头插法
	// HeadInsertLinkList(&L);
	// 2.尾插法
	TailInsertLinkList(&L);
	printf("原单链表为：");
	PrintLinkList(L);
	// 3.按序号查找
	LNode* p = GetLinkListElem(L, 2);
	if (p != NULL)
		printf("查找第二个元素为：%d\n", p->data);
	// 4.按值查找
	ElemtType e = 2;
	p = LocateLinkListElem(L, e);
	if (p != NULL)
		printf("查找值为2元素为：%d\n", p->data);
	// 5.插入-后插
	e = 5;
	InsertLinkList(&L, 2, e);
	printf("在第2个位置插入5后的单链表：");
	PrintLinkList(L);
	// 5.插入-前插
	e = 9;
	InsertLinkListAfter(&L, 2, e);
	printf("在第2个位置前插入9后的单链表：");
	PrintLinkList(L);
	// 6.删除结点
	DeleteLinkList(&L, 3, &e);
	printf("删除第三个结点的值为：%d，删除后的单链表为：", e);
	PrintLinkList(L);
	// 7.表长
	printf("链表长为：%d\n", LengthLinkList(L));
	// 8.判空
	if (EmptyLinkList(L))
		printf("链表不为空\n");
	else
		printf("链表为空\n"); 
	// 9.销毁
	if(DestroyLinkList(&L))
		printf("销毁成功\n");
}

