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
LinkList HeadInsertList(LinkList* L);
// 2.尾插法建立单链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助）
LinkList TailInsertList(LinkList* L);

// 输出单链表
void PrintLinkList(LinkList L);


// 功能测试
void MainLinkList();
#endif // !_LINKLIST_H_
