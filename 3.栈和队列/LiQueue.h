// ˳�����
#ifndef _LIQUEUE_H_
#define _LIQUEUE_H_

// ����Ԫ������
typedef int ElemtType;
// ���ӽ��
typedef struct LiQueueNode {
	// ��Ԫ�ظ���
	ElemtType data;
	// ��һ�����ָ��
	struct LiQueueNode* next;
}LiQueueNode;
// ����
typedef struct {
	// ����βָ��
	LiQueueNode* front, * rear;
}LiQueue;

// 1.��ʼ����
void InitLiQueue(LiQueue& Q);
// 2.���
bool EnLiQueue(LiQueue& Q, ElemtType x);
// 3.����
ElemtType DeLiQueue(LiQueue& Q);
// 4.�жӿ�
bool EmptyLiQueue(LiQueue Q);
// 5.���Ӷ�Ԫ��
ElemtType GetHeadLiQueue(LiQueue Q);
// 6.��ӡ��ǰ��
void PrintLiQueue(LiQueue Q);
// 7.���ٶ�
bool DestroyLiQueue(LiQueue& Q);

// ���ܲ���
void MainLiQueue();

#endif // !_LIQUEUE_H_


