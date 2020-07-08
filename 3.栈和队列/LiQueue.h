// 顺序队列
#ifndef _LIQUEUE_H_
#define _LIQUEUE_H_

// 定义元素类型
typedef int ElemtType;
// 链队结点
typedef struct LiQueueNode {
	// 队元素个数
	ElemtType data;
	// 下一个结点指针
	struct LiQueueNode* next;
}LiQueueNode;
// 链队
typedef struct {
	// 队首尾指针
	LiQueueNode* front, * rear;
}LiQueue;

// 1.初始化队
void InitLiQueue(LiQueue& Q);
// 2.入队
bool EnLiQueue(LiQueue& Q, ElemtType x);
// 3.出队
ElemtType DeLiQueue(LiQueue& Q);
// 4.判队空
bool EmptyLiQueue(LiQueue Q);
// 5.读队顶元素
ElemtType GetHeadLiQueue(LiQueue Q);
// 6.打印当前队
void PrintLiQueue(LiQueue Q);
// 7.销毁队
bool DestroyLiQueue(LiQueue& Q);

// 功能测试
void MainLiQueue();

#endif // !_LIQUEUE_H_


