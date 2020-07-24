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
void InitBiTNodeStack(BiTNodeStack& S) {
	S.top = -1;
}
// 2.��ջ
bool PushBiTNodeStack(BiTNodeStack& S, BiTNode* x) {
	if (S.top == MaxSize - 1) {
		printf("ջ����");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.��ջ
BiTNode* PopBiTNodeStack(BiTNodeStack& S) {
	if (S.top == -1) {
		printf("ջ�ѿ�");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.��ջ��
bool EmptyBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.��ջ��Ԫ��
BiTNode* GetTopBiTNodeStack(BiTNodeStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return NULL;
	}
	return S.BT[S.top];
}

// ������ջ
typedef struct {
	// Ԫ��
	ThreadNode* BT[MaxSize];
	// ջ��ָ��
	int top;
}ThreadNodeStack;

// 1.��ʼ��ջ
void InitThreadNodeStack(ThreadNodeStack& S) {
	S.top = -1;
}
// 2.��ջ
bool PushThreadNodeStack(ThreadNodeStack& S, ThreadNode* x) {
	if (S.top == MaxSize - 1) {
		printf("ջ����");
		return false;
	}
	S.BT[++S.top] = x;
	return true;
}
// 3.��ջ
ThreadNode* PopThreadNodeStack(ThreadNodeStack& S) {
	if (S.top == -1) {
		printf("ջ�ѿ�");
		return NULL;
	}
	return S.BT[S.top--];
}
// 4.��ջ��
bool EmptyThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}
// 5.��ջ��Ԫ��
ThreadNode* GetTopThreadNodeStack(ThreadNodeStack S) {
	if (S.top == -1) {
		printf("ջΪ��");
		return NULL;
	}
	return S.BT[S.top];
}
#endif // _BITNODESTACK_H_
