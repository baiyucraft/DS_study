#ifndef _DLINKLIST_H_
#define _DLINKLIST_H_
// 定义元素类型
typedef int ElemtType;
// 双链表
typedef struct DNode {
	// 数据域
	ElemtType data;
	// 指针域-前驱和后继指针
	struct DNode* prior, * next;
}DNode, * DLinkList;

// 带频度的双链表
typedef struct DFNode {
	// 数据域
	ElemtType data;
	// 指针域-前驱和后继指针
	struct DFNode* pred, * next;
	// 频度
	int freq;
}DFNode, * DFLinkList;

// 1.头插法建立链表：从头结点后插入，生成链表元素顺序与输入顺序相反
DLinkList HeadInsertDLinkList(DLinkList& L);
// 2.尾插法建立链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助）
DLinkList TailInsertDLinkList(DLinkList& L);
// 3.按序号查找结点, 查找第i个元素
DNode* GetDLinkListElem(DLinkList L, int i);
// 4.按值查找，查找值为e的元素
DNode* LocateDLinkListElem(DLinkList L, ElemtType e);
// 5.插入结点，在第i个结点的位置插入e
bool InsertDLinkList(DLinkList& L, int i, ElemtType e);
// 5.插入操作，在第i个结点前插入（前插）
bool InsertDLinkListAfter(DLinkList& L, int i, ElemtType e);
// 6.删除结点，删除第i个结点，并返回被删除的元素
bool DeleteDLinkList(DLinkList& L, int i, ElemtType& e);
// 7.获取链表的长度
int LengthDLinkList(DLinkList L);
// 8.判空
int EmptyDLinkList(DLinkList L);
// 9.销毁链表
int DestroyDLinkList(DLinkList& L);
// 10.打印单链表
void PrintDLinkList(DLinkList L);

// 循环双链表部分功能
// cir1.尾插建立循环双链表
DLinkList TailInsertCirDLinkList(DLinkList& L);
// cir2.打印循环双链表
void PrintCirDLinkList(DLinkList L);

// 功能测试
void MainDLinkList();

// 17.
// 判别双链表是否对称
bool SymmertryCirDLinkList(DLinkList L);
void SolveDLinkList17();
// 20.
// 1.尾插法建立带频度的双链表
DFLinkList TailInsertDFLinkList(DFLinkList& L);
// 2.打印带频度的双链表
void PrintDFLinkList(DFLinkList L);
// 3.按值查找带频度的双链表（算法）
DFNode* LocateDFLinkListElem(DFLinkList& L, ElemtType e);
void SolveDLinkList20();

#endif // !_DLINKLIST_H_