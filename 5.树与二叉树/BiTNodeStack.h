#ifndef _BITNODESTACK_H_
#define _BITNODESTACK_H_

// ����ջ��Ԫ��������
#define MaxSize 50

// ������ջ
typedef struct {
	// Ԫ��
	BiTNode *BT[MaxSize];
	// ջ��ָ��
	int top;
}BiTNodeStack;

// 1.��ʼ��ջ
inline void InitBiTNodeStack(BiTNodeStack& S) {
	S.top = -1;
}
// 2.��ջ
inline bool PushBiTNodeStack(BiTNodeStack& S, BiTNode* x) {
	if (S.top == MaxSize - 1) {
		printf("ջ����");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.��ջ
inline BiTNode* PopBiTNodeStack(BiTNodeStack& S) {
	if (S.top == -1) {
		printf("ջ�ѿ�");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.��ջ��
inline bool EmptyBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.��ջ��Ԫ��
inline BiTNode* GetTopBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return NULL;
	}
	return S.BT[S.top];
}

// ����������ջ
typedef struct {
	// Ԫ��
	ThreadNode* BT[MaxSize];
	// ջ��ָ��
	int top;
}ThreadNodeStack;

// 1.��ʼ��ջ
inline void InitThreadNodeStack(ThreadNodeStack& S) {
	S.top = -1;
}
// 2.��ջ
inline bool PushThreadNodeStack(ThreadNodeStack& S, ThreadNode* x) {
	if (S.top == MaxSize - 1) {
		printf("ջ����");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.��ջ
inline ThreadNode* PopThreadNodeStack(ThreadNodeStack& S) {
	if (S.top == -1) {
		printf("ջ�ѿ�");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.��ջ��
inline bool EmptyThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.��ջ��Ԫ��
inline ThreadNode* GetTopThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return NULL;
	}
	return S.BT[S.top];
}
#endif // _BITNODESTACK_H_
