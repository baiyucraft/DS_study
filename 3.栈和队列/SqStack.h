// ˳��ջ
#ifndef _SQSTACK_H_
#define _SQSTACK_H_
// ����ջ��Ԫ��������
#define MaxSize 50
// ����Ԫ������
typedef int ElemtType;
// ˳��ջ
typedef struct {
	// ջԪ�ظ���
	ElemtType data[MaxSize];
	// ջ��ָ��
	int top;
}SqStack;

// 1.��ʼ��ջ
void InitSqStack(SqStack& S);
// 2.��ջ
bool PushSqStack(SqStack& S, ElemtType x);
// 3.��ջ
ElemtType PopSqStack(SqStack& S);
// 4.��ջ��
bool EmptySqStack(SqStack S);
// 5.��ջ��Ԫ��
ElemtType GetTopSqStack(SqStack S);
// 6.��ӡ��ǰջ
void PrintSqStack(SqStack S);
// 7.����ջ
bool DestroySqStack(SqStack& S);

// ���ܲ���
void MainSqStack();

// ��Ŀ���
#endif // _SQSTACK_H_
