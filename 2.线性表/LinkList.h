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
LinkList HeadInsertLinkList(LinkList& L);
// 2.尾插法建立单链表：从已完成链表尾部插入，生成链表元素顺序与输入顺序相同（需要一个尾指针r辅助）
LinkList TailInsertLinkList(LinkList& L);
// 3.按序号查找结点, 查找第i个元素
LNode* GetLinkListElem(LinkList L, int i);
// 4.按值查找，查找值为e的元素
LNode* LocateLinkListElem(LinkList L, ElemtType e);
// 5.插入结点，在第i个结点的位置插入e
bool InsertLinkList(LinkList& L, int i, ElemtType e);
// 5.插入操作，在第i个结点前插入（前插）
bool InsertLinkListAfter(LinkList& L, int i, ElemtType e);
// 6.删除结点，删除第i个结点，并返回被删除的元素
bool DeleteLinkList(LinkList& L, int i, ElemtType& e);
// 7.获取单链表的长度
int LengthLinkList(LinkList L);
// 8.判空
bool EmptyLinkList(LinkList L);
// 9.销毁单链表
bool DestroyLinkList(LinkList& L);
// 10.打印单链表
void PrintLinkList(LinkList L);

//拓展
// 1Un.创建不带头结点的单链表
void CreateUnLinkList(LinkList& L);
// 2Un.打印不带头结点的单链表
void PrintUnLinkList(LinkList L);
// 1Cri.创建循环单链表
LinkList TailInsertCriLinkList(LinkList& L);
// 2Cri.打印循环单链表
void PrintCriLinkList(LinkList L);

// 功能测试
void MainLinkList();

// 题目解答
// 1.
// 王道书上的递归题解，因为C中没有引用，书上的思想无法实现
void LinkList_DelX1(LinkList& L, ElemtType x);
// LeetCode上的递归想法
LinkList LinkList_DelX2(LinkList L, ElemtType x);
void SolveLinkList1();
// 2.
// 从头至尾扫描单链表，pre指向当前结点p的前驱结点
void LinkList_DelX3(LinkList& L, ElemtType x);
// 用p指针扫描所有结点，将值等于x的释放，不等于x的链接到L之后
void LinkList_DelX4(LinkList& L, ElemtType x);
void SolveLinkList2();
// 3.
// 反向打印，通过递归
void RPrintLinkList(LinkList L);
void SolveLinkList3();
// 4.
// 删除最小值
void DelMinLinkList(LinkList& L);
void SolveLinkList4();
// 5.
// 摘下头结点，以第一个元素为起点，采用头插法重新插入建立链表
void ReverseLinkList1(LinkList& L);
// 遍历链表，将每个结点的指针域反转，其中原第一个结点的指针域为NULL，头结点指向原表最后一个结点
void ReverseLinkList2(LinkList& L);
void SolveLinkList5();
// 6.
// 用直接插入排序，遍历结点并插入
void SortLinkList(LinkList& L);
void SolveLinkList6();
// 7.
// 从头至尾扫描单链表，pre指向当前结点p的前驱结点
void LinkListDelMinMax(LinkList& L, ElemtType min, ElemtType max);
void SolveLinkList7();
// 8-22.
// 先减去相差的长度dist，再分别遍历找到公共结点
LinkList SearchLinkList1st(LinkList L1, LinkList L2);
// 创建两个有公共结点的链表
void CreateComLinkList(LinkList& L1, LinkList& L2);
void SolveLinkList8();
// 9.
// 升序输出并删除
void LinkListDelMinP(LinkList& L);
void SolveLinkList9();
// 10.
// 将链表A分为奇数链表A和偶数链表A
LinkList DisCreateLinkList1(LinkList& A);
void SolveLinkList10();
// 11.
// 将链表A分为奇数链表A和逆置后的偶数链表B
LinkList DisCreateLinkList2(LinkList& A);
void SolveLinkList11();
// 12.
// 删除递增有序单链表中相同的元素
void LinkListDelSame(LinkList& L);
void SolveLinkList12();
// 13.
// 合并两个递增有序的单链表L1、L2，合并成递减（采用头插法）
void MergeLinkList(LinkList& L1, LinkList& L2);
void SolveLinkList13();
// 14.
// 将递增的L1、L2链表的公共结点放入L3
LinkList GetLinkListCom(LinkList L1, LinkList L2);
void SolveLinkList14();
// 15.
// 将L1、L2链表的相同项放L1中，其余结点释放
void UnionLinkList(LinkList& L1, LinkList& L2);
void SolveLinkList15();
// 16.
// 字符串模式匹配的链表形式，这是最基本的算法，匹配L1中含L2
bool PatternLinkList1(LinkList L1, LinkList L2);
void SolveLinkList16();
// 18.
// 将两个循环单链表h2连接到h1后面
void LinkCriLinkList(LinkList& h1, LinkList& h2);
void SolveLinkList18();
// 19.
// 遍历循环单链表，每次删除最小值结点并输出
void DelAllMinCriLinkList(LinkList& L);
void SolveLinkList19();
// 21.
// 查找倒数第k个数，
int SearchLinkListK(LinkList L, int k);
void SolveLinkList21();
// 23.
// n为数组中数的绝对值的范围，保留第一个绝对值为那个值的数（空间换时间）
void DelAbsLinkList(LinkList& L, int n);
void SolveLinkList23();
// 24.
// 1.创建带环的单链表
void CreateRingLinkList(LinkList& L);
// 2.打印带环的单链表
void PrintRingLinkList(LinkList L);
void SolveLinkList24();

#endif // !_LINKLIST_H_
