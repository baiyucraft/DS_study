#include <stdio.h>
#include <stdlib.h>
#include "DLinkList.h"

/*
详细讲述自己所理解的指针定义
单链表结构体声明中有两种别称来代指该结构体，一种是LNode，一种是LinkList
变量声明时:Lnode s：指的是该结构体；LNode *s：指向该结构体的指针；
		 LinkList L：指向该结构体的指针=LNode *L；LinkList *L：指向该结构体指针的指针
关于用L还是*L：
	如果函数会改变指针L的值,而你希望函数结束调用后保存L的值,那你就要用LinkList *L,这样,向函数传递的就是指针的地址,结束调用后,自然就可以去改变指针的值;
	而如果函数只会修改指针所指向的内容,而不会更改指针的值,那么用LinkList L就行了;
*/

// 1.头插法建立链表：在头结点与第一个结点之间插入，生成链表元素顺序与输入顺序相反，时间：o(n)
DLinkList HeadInsertDLinkList(DLinkList& L) {
	ElemtType x;
	DNode* s;
	// 初始化双链表、创建头结点
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		// 创建结点s
		s = (DNode*)malloc(sizeof(DNode));
		// 数据域data为当前输入的x
		s->data = x;
		// s结点的前驱指针指向L
		s->prior = L;
		// s结点的后驱指针指向之前L的第一个结点，
		s->next = (L)->next;
		// 如果之前L有结点，L的第一个结点的前驱指针指向s结点
		if (L->next != NULL)
			L->next->prior = s;
		// L头结点的后继指针指向刚创建的结点s
		L->next = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	return L;
}
// 2.尾插法建立链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助），时间：o(n)
DLinkList TailInsertDLinkList(DLinkList& L) {
	ElemtType x;
	// 新增结点
	DNode* s;
	// 初始化双链表，创建头结点
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// 尾指针r指向表尾结点
	DNode* r = L;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		// 数据域data为当前输入的x
		s->data = x;
		// s的前驱指针指向尾结点r
		s->prior = r;
		// 尾结点r的后继指针指向新结点s
		r->next = s;
		r = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
// 3.按序号查找结点, 查找第i个元素
DNode* GetDLinkListElem(DLinkList L, int i) {
	int j = 1;
	// p为查找指针，指向第一个第一个结点
	DNode* p = L->next;
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
DNode* LocateDLinkListElem(DLinkList L, ElemtType e) {
	// p为查找指针，指向第一个第一个结点
	DNode* p = L->next;
	// p为空或找到e时停止循环
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
// 5.插入结点，在第i个结点的位置插入e，即在第i-1个结点后插入（后插）
bool InsertDLinkList(DLinkList& L, int i, ElemtType e) {
	if (i < 1 || i > LengthDLinkList(L) + 1) {
		printf("插入位置不合法");
		return false;
	}
	// 获取插入位置的前驱结点p
	DNode* p = GetDLinkListElem(L, i - 1);
	 //创造要插入的结点s
	DNode* s = (DNode*)malloc(sizeof(DNode));
	s->data = e;
	// 要插入结点s的后继指针指向p的后继结点
	s->next = p->next;
	// 要插入结点s的前驱指针指向p
	s->prior = p;
	// p的后驱结点的前驱指针指向要插入结点s
	p->next->prior = s;
	// p的后继指针指向要插入结点s
	p->next = s;
	return true;
}
// 5.插入操作，在第i个结点前插入（前插）
bool InsertDLinkListAfter(DLinkList& L, int i, ElemtType e) {
	if (i < 1 || i > LengthDLinkList(L)) {
		printf("插入位置不合法");
		return false;
	}
	// 获取插入位置的第i个结点p
	DNode* p = GetDLinkListElem(L, i);
	// 创造要插入的结点s
	DNode* s = (DNode*)malloc(sizeof(DNode));
	s->data = e;
	// 要插入结点s的后继指针指向p的后继结点
	s->next = p->next;
	// 要插入结点s的前驱指针指向p
	s->prior = p;
	// p的后驱结点的前驱指针指向要插入结点s
	p->next->prior = s;
	// p的后继指针指向要插入结点s
	p->next = s;
	// 交换p、s的数据域，使数据上插入的在i之前
	ElemtType temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
}
// 6.删除结点，删除第i个结点，并返回被删除的元素的值
bool DeleteDLinkList(DLinkList& L, int i, ElemtType& e) {
	if (i<1 || i>LengthDLinkList(L)) {
		printf("要删除的结点不存在");
		return false;
	}
	// 获取要删除结点的前驱结点p
	DNode* p = GetDLinkListElem(L, i - 1);
	// 获取要删除的结点q
	DNode* q = p->next;
	// 将p的后继结点变为要删除结点q的后继结点，即q结点从链表中断开
	p->next = q->next;
	// 要删除结点q的后继结点的前驱指针指向p
	q->next->prior = p;
	e = q->data;
	// 释放要删除结点q的存储空间
	free(q);
	return true;
}
// 7.获取链表的长度
int LengthDLinkList(DLinkList L) {
	DNode* p = L->next;
	int i = 0;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
// 8.判空
int EmptyDLinkList(DLinkList L) {
	if (LengthDLinkList(L)) {
		return 1;
	}
	return 0;
}
// 9.销毁链表
int DestroyDLinkList(DLinkList& L) {
	// 获取第一个结点
	DNode* p = L->next;
	// 给定要释放空间的结点Del
	DNode* Del = p;
	while (p != NULL) {
		// p变成下一个结点
		p = p->next;
		// 释放Del的空间
		free(Del);
		// Del重新指向新的p
		Del = p;
	}
	// 释放头结点
	free(L);
	return 1;
}
// 10.打印链表
void PrintDLinkList(DLinkList L) {
	printf("头结点<->");
	DNode* p = L->next;
	while (p != NULL) {
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

// cir1.尾插建立循环双链表
DLinkList TailInsertCirDLinkList(DLinkList& L) {
	ElemtType x;
	// 新增结点
	DNode* s;
	// 初始化双链表，创建头结点
	L = (DLinkList)malloc(sizeof(DNode));
	L->next = NULL;
	// 尾指针r指向表尾结点
	DNode* r = L;
	// 输入数据
	printf("请输入数(输入9999结束)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));
		// 数据域data为当前输入的x
		s->data = x;
		// s的前驱指针指向尾结点r
		s->prior = r;
		// 尾结点r的后继指针指向新结点s
		r->next = s;
		r = s;
		printf("请输入数(输入9999结束)：");
		scanf("%d", &x);
	}
	r->next = L;
	L->prior = r;
	return L;
}

// cir2.打印循环双链表
void PrintCirDLinkList(DLinkList L) {
	printf("头结点<->");
	DNode* p = L->next;
	while (p != L) {
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("头结点\n");
}

// 功能实现
void MainDLinkList() {
	DLinkList L;
	// 1.头插法
	 //HeadInsertDLinkList(L);
	// 2.尾插法
	TailInsertDLinkList(L);
	printf("原单链表为：");
	PrintDLinkList(L);
	// 测试结点的前驱后继指针是否正常
	//printf("%d<-%d->%d", L->next->next->prior->data, L->next->next->data, L->next->next->next->data);
	// 3.按序号查找
	DNode* p = GetDLinkListElem(L, 2);
	if (p != NULL)
		printf("查找第二个元素为：%d\n", p->data);
	// 4.按值查找
	ElemtType e = 2;
	p = LocateDLinkListElem(L, e);
	if (p != NULL)
		printf("查找值为2元素为：%d\n", p->data);
	// 5.插入-后插
	e = 5;
	InsertDLinkList(L, 2, e);
	printf("在第2个位置插入5后的双链表：");
	PrintDLinkList(L);
	// 5.插入-前插
	e = 9;
	InsertDLinkListAfter(L, 2, e);
	printf("在第2个位置前插入9后的双链表：");
	PrintDLinkList(L);
	// 6.删除结点
	DeleteDLinkList(L, 3, e);
	printf("删除第三个结点的值为：%d，删除后的单链表为：", e);
	PrintDLinkList(L);
	// 7.表长
	printf("链表长为：%d\n", LengthDLinkList(L));
	// 8.判空
	if (EmptyDLinkList(L))
		printf("链表不为空\n");
	else
		printf("链表为空\n");
	// 9.销毁
	if (DestroyDLinkList(L))
		printf("销毁成功\n");
}