// 单链表
#ifndef _LINKLIST_H_
#define _LINKLIST_H_
// 定义元素类型
typedef int ElemtType;
// 单链表
typedef struct LNode {
	// 数据域
	ElemtType data;
	// 指针域
	struct LNode* next;
}LNode, * LinkList;

// 1.头插法建立单链表：从头结点后插入，生成链表元素顺序与输入顺序相反
LinkList HeadInsertLinkList(LinkList* L);
// 2.尾插法建立单链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助）
LinkList TailInsertLinkList(LinkList* L);
// 3.按序号查找结点, 查找第i个元素
LNode* GetLinkListElem(LinkList L, int i);
// 4.按值查找，查找值为e的元素
LNode* LocateLinkListElem(LinkList L, ElemtType e);
// 5.插入结点，在第i个结点的位置插入e
int InsertLinkList(LinkList* L, int i, ElemtType e);
// 5.插入操作，在第i个结点前插入（前插）
int InsertLinkListAfter(LinkList* L, int i, ElemtType e);
// 6.删除结点，删除第i个结点，并返回被删除的元素
int DeleteLinkList(LinkList* L, int i, ElemtType* e);
// 7.获取单链表的长度
int LengthLinkList(LinkList L);
// 8.判空
int EmptyLinkList(LinkList L);
// 9.销毁单链表
int DestroyLinkList(LinkList* L);
// 10.打印单链表
void PrintLinkList(LinkList L);

// 功能测试
void MainLinkList();
#endif // !_LINKLIST_H_
