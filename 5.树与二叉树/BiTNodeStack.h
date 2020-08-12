#ifndef _BITNODESTACK_H_
#define _BITNODESTACK_H_

// 定义栈中元素最大个数
#define MaxSize 50

// 二叉树栈
typedef struct {
	// 元素
	BiTNode *BT[MaxSize];
	// 栈顶指针
	int top;
}BiTNodeStack;

// 1.初始化栈
inline void InitBiTNodeStack(BiTNodeStack& S) {
	S.top = -1;
}
// 2.进栈
inline bool PushBiTNodeStack(BiTNodeStack& S, BiTNode* x) {
	if (S.top == MaxSize - 1) {
		printf("栈已满");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.出栈
inline BiTNode* PopBiTNodeStack(BiTNodeStack& S) {
	if (S.top == -1) {
		printf("栈已空");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.判栈空
inline bool EmptyBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.读栈顶元素
inline BiTNode* GetTopBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return NULL;
	}
	return S.BT[S.top];
}

// 线索二叉树栈
typedef struct {
	// 元素
	ThreadNode* BT[MaxSize];
	// 栈顶指针
	int top;
}ThreadNodeStack;

// 1.初始化栈
inline void InitThreadNodeStack(ThreadNodeStack& S) {
	S.top = -1;
}
// 2.进栈
inline bool PushThreadNodeStack(ThreadNodeStack& S, ThreadNode* x) {
	if (S.top == MaxSize - 1) {
		printf("栈已满");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.出栈
inline ThreadNode* PopThreadNodeStack(ThreadNodeStack& S) {
	if (S.top == -1) {
		printf("栈已空");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.判栈空
inline bool EmptyThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.读栈顶元素
inline ThreadNode* GetTopThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return NULL;
	}
	return S.BT[S.top];
}
#endif // _BITNODESTACK_H_
