// 顺序栈
#ifndef _SQSTACK_H_
#define _SQSTACK_H_

// 定义栈中元素最大个数
#define MaxSize 50
// 定义元素类型
typedef int ElemtType;
// 顺序栈
typedef struct {
	// 栈元素个数
	ElemtType data[MaxSize];
	// 栈顶指针
	int top;
}SqStack;

// 定义字符串链表
typedef struct LNode {
	// 数据域
	char data;
	// 指针域
	struct LNode* next;
}LNode, * LinkList;

#define MaxS 100
// 共享栈
typedef struct {
	// 数据
	ElemtType stack[MaxS];
	// 两个栈顶指针
	int top[2];
}STK;

// 1.初始化栈
void InitSqStack(SqStack& S);
// 2.进栈
bool PushSqStack(SqStack& S, ElemtType x);
// 3.出栈
ElemtType PopSqStack(SqStack& S);
// 4.判栈空
bool EmptySqStack(SqStack S);
// 5.读栈顶元素
ElemtType GetTopSqStack(SqStack S);
// 6.打印当前栈
void PrintSqStack(SqStack S);
// 7.销毁栈
bool DestroySqStack(SqStack& S);

// 功能测试
void MainSqStack();

// 题目解答
// 3.
// 判断进栈出栈是否合法
bool JudgeStack(char A[]);
void SolveStack_3();
// 4.
// 尾插建立字符串链表
LinkList TailInsertLinkList(LinkList& L);
// 打印字符串链表
void PrintLinkList(LinkList L);
// 获取字符串单链表长度
int LengthLinkList(LinkList L);
// 判断链表全部n个字符是否中心对称
bool dcStackLinkList(LinkList L, int n);
void SolveStack_4();
// 5.
// 入栈，i代表栈号
bool PushSTK(STK& s, int i, ElemtType x);
// 出栈，i代表栈号
ElemtType PopSTK(STK& s, int i);
// 打印
void PrintSqStack(STK S);
void SolveStack_5();
#endif // _SQSTACK_H_
