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

// 1.头插法建立单链表：从头结点后插入，生成链表元素顺序与输入顺序相反
LinkList HeadInsertList(LinkList* L) {
	LNode* s;
	int x;
	// 初始化单链表、创建头结点
	*L = (LinkList)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("请输入数(9999结束输入)：");
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = (*L)->next;
		(*L)->next = s;
		printf("请输入数(9999结束输入)：");
		scanf("%d", &x);
	}
	return *L;
}
// 2.尾插法建立单链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助）
LinkList TailInsertList(LinkList* L) {

}

// 输出单链表
void PrintLinkList(LinkList L) {
	LNode* p = L->next;
	while (p != NULL){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void MainLinkList() {
	LinkList L;
	HeadInsertList(&L);
	printf("原链表为：");
	PrintLinkList(L);
}