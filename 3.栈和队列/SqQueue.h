// ˳�����
#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

// �������Ԫ��������
#define MaxSize 50
// ����Ԫ������
typedef int ElemtType;
// ˳���
typedef struct {
	// ��Ԫ�ظ���
	ElemtType data[MaxSize];
	// ��ǰ��ָ��
	int front, rear;
}SqQueue;

// 1.��ʼ����
void InitSqQueue(SqQueue& Q);
// 2.���
bool EnSqQueue(SqQueue& Q, ElemtType x);
// 3.����
ElemtType DeSqQueue(SqQueue& Q);
// 4.�жӿ�
bool EmptySqQueue(SqQueue Q);
// 5.���Ӷ�Ԫ��
ElemtType GetHeadSqQueue(SqQueue Q);
// 6.��ӡ��ǰ��
void PrintSqQueue(SqQueue Q);
// 7.���ٶ�
//bool DestroySqQueue(SqQueue& Q);

// 1.��ʼ��ѭ����
void InitCriSqQueue(SqQueue& Q);
// 2.��ѭ����
bool EnCriSqQueue(SqQueue& Q, ElemtType x);
// 3.��ѭ����
ElemtType DeCriSqQueue(SqQueue& Q);
// 4.��ѭ���ӿ�
bool EmptyCriSqQueue(SqQueue Q);
// 5.��ѭ���Ӷ�Ԫ��
ElemtType GetHeadCriSqQueue(SqQueue Q);
// 6.��ӡ��ǰѭ����
void PrintCriSqQueue(SqQueue Q);

// ˳��Tag��
typedef struct {
	// ��Ԫ�ظ���
	ElemtType data[MaxSize];
	// ��ǰ��ָ��
	int front, rear, tag;
}SqQueueT;

// ���ܲ���
void MainSqQueue();
void MainCriSqQueue();

// ��Ŀ
// 1.
// ��"tag"�����
bool EnSqQueueTag(SqQueueT& Q, ElemtType x);
// ��"tag"�ĳ���
ElemtType DeSqQueueTag(SqQueueT& Q);
// ��"tag"�ĳ�ʼ��
void InitSqQueueTag(SqQueueT& Q);
// ��"tag"�Ĵ�ӡ
void PrintSqQueueTag(SqQueueT Q);
void SolveQueue_1();
// 2.
// ��ջ�������е�Ԫ������
void InverserSqQueue(SqQueue& Q);
void SolveQueue_2();
// 3.
// ������ջʵ�ֶ��в���
void SolveQueue_3();

// 3.4
// ��������ʵ��
// ���϶���q���ͳ�����car����������truck
void manager(SqQueue& q, SqQueue& car, SqQueue& truck);
#endif // !_SQQUEUE_H_

