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
void InitBiTNodeStack(BiTNodeStack& S) {
	S.top = -1;
}
// 2.进栈
bool PushBiTNodeStack(BiTNodeStack& S, BiTNode* x) {
	if (S.top == MaxSize - 1) {
		printf("栈已满");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.出栈
BiTNode* PopBiTNodeStack(BiTNodeStack& S) {
	if (S.top == -1) {
		printf("栈已空");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.判栈空
bool EmptyBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.读栈顶元素
BiTNode* GetTopBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return NULL;
	}
	return S.BT[S.top];
}

// 二叉树栈
typedef struct {
	// 元素
	ThreadNode* BT[MaxSize];
	// 栈顶指针
	int top;
}ThreadNodeStack;

// 1.初始化栈
void InitThreadNodeStack(ThreadNodeStack& S) {
	S.top = -1;
}
// 2.进栈
bool PushThreadNodeStack(ThreadNodeStack& S, ThreadNode* x) {
	if (S.top == MaxSize - 1) {
		printf("栈已满");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.出栈
ThreadNode* PopThreadNodeStack(ThreadNodeStack& S) {
	if (S.top == -1) {
		printf("栈已空");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.判栈空
bool EmptyThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.读栈顶元素
ThreadNode* GetTopThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1) {
		printf("栈为空");
		return NULL;
	}
	return S.BT[S.top];
}
#endif // _BITNODESTACK_H_
