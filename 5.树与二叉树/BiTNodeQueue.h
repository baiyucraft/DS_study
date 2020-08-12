#ifndef _BITNODEQUEUE_H_
#define _BITNODEQUEUE_H_

/// �������Ԫ��������
#define MaxSize 50

typedef struct {
	// ��Ԫ�ظ���
	BiTNode* BT[MaxSize];
	// ��ǰ��ָ��
	int front, rear;
}BiTNodeQueue;

// 1.��ʼ����
inline void InitBiTNodeQueue(BiTNodeQueue& Q) {
	Q.front = Q.rear = 0;
}
// 2.���
inline bool EnBiTNodeQueue(BiTNodeQueue& Q, BiTNode* x) {
	if (Q.rear == MaxSize) {
		printf("���м����");
		return false;
	}
	Q.BT[Q.rear++] = x;
	return true;
}
// 3.����
inline BiTNode* DeBiTNodeQueue(BiTNodeQueue& Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��");
		return NULL;
	}
	return Q.BT[Q.front++];
}
// 4.�жӿ�
inline bool EmptyBiTNodeQueue(BiTNodeQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
// 5.���Ӷ�Ԫ��
inline BiTNode* GetTopBiTNodeQueue(BiTNodeQueue Q) {
	if (Q.front == Q.rear) {
		printf("������û��Ԫ��");
		return NULL;
	}
	return Q.BT[Q.front];
}
#endif // _BITNODEQUEUE_H_