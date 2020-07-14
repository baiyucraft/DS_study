// 顺序队列
#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

// 定义队中元素最大个数
#define MaxSize 50
// 定义元素类型
typedef int ElemtType;
// 顺序队
typedef struct {
	// 队元素个数
	ElemtType data[MaxSize];
	// 队前后指针
	int front, rear;
}SqQueue;

// 1.初始化队
void InitSqQueue(SqQueue& Q);
// 2.入队
bool EnSqQueue(SqQueue& Q, ElemtType x);
// 3.出队
ElemtType DeSqQueue(SqQueue& Q);
// 4.判队空
bool EmptySqQueue(SqQueue Q);
// 5.读队顶元素
ElemtType GetHeadSqQueue(SqQueue Q);
// 6.打印当前队
void PrintSqQueue(SqQueue Q);
// 7.销毁队
//bool DestroySqQueue(SqQueue& Q);

// 1.初始化循环队
void InitCriSqQueue(SqQueue& Q);
// 2.入循环队
bool EnCriSqQueue(SqQueue& Q, ElemtType x);
// 3.出循环队
ElemtType DeCriSqQueue(SqQueue& Q);
// 4.判循环队空
bool EmptyCriSqQueue(SqQueue Q);
// 5.读循环队顶元素
ElemtType GetHeadCriSqQueue(SqQueue Q);
// 6.打印当前循环队
void PrintCriSqQueue(SqQueue Q);

// 顺序Tag队
typedef struct {
	// 队元素个数
	ElemtType data[MaxSize];
	// 队前后指针
	int front, rear, tag;
}SqQueueT;

// 功能测试
void MainSqQueue();
void MainCriSqQueue();

// 题目
// 1.
// 设"tag"的入队
bool EnSqQueueTag(SqQueueT& Q, ElemtType x);
// 设"tag"的出队
ElemtType DeSqQueueTag(SqQueueT& Q);
// 设"tag"的初始化
void InitSqQueueTag(SqQueueT& Q);
// 设"tag"的打印
void PrintSqQueueTag(SqQueueT Q);
void SolveQueue_1();
// 2.
// 用栈将队列中的元素逆置
void InverserSqQueue(SqQueue& Q);
void SolveQueue_2();
// 3.
// 用两个栈实现队列操作
void SolveQueue_3();

// 3.4
// 不做具体实现
// 船上队列q，客车队列car，货车队列truck
void manager(SqQueue& q, SqQueue& car, SqQueue& truck);
#endif // !_SQQUEUE_H_

