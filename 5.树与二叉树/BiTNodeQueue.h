#ifndef _BITNODEQUEUE_H_
#define _BITNODEQUEUE_H_

/// 定义队中元素最大个数
#define MaxSize 50

typedef struct {
	// 队元素个数
	BiTNode* BT[MaxSize];
	// 队前后指针
	int front, rear;
}BiTNodeQueue;

// 1.初始化队
inline void InitBiTNodeQueue(BiTNodeQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.入队
inline bool EnBiTNodeQueue(BiTNodeQueue& Q, BiTNode* x) {
	if (Q.rear == MaxSize) {
		printf("队列假溢出");
		return false;
	}
	Q.BT[Q.rear++] = x;
	return true;
}
// 3.出队
inline BiTNode* DeBiTNodeQueue(BiTNodeQueue& Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素");
		return NULL;
	}
	return Q.BT[Q.front++];
}
// 4.判队空
inline bool EmptyBiTNodeQueue(BiTNodeQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.读队顶元素
inline BiTNode* GetTopBiTNodeQueue(BiTNodeQueue Q) {
	if (Q.front == Q.rear) {
		printf("队列中没有元素");
		return NULL;
	}
	return Q.BT[Q.front];
}
#endif // _BITNODEQUEUE_H_