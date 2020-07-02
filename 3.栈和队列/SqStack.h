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
#endif // _SQSTACK_H_
