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

// �����ַ�������
typedef struct LNode {
	// ������
	char data;
	// ָ����
	struct LNode* next;
}LNode, * LinkList;

#define MaxS 100
// ����ջ
typedef struct {
	// ����
	ElemtType stack[MaxS];
	// ����ջ��ָ��
	int top[2];
}STK;

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

// ˳���ַ�ջ
typedef struct {
	// ջԪ�ظ���
	char data[MaxSize];
	// ջ��ָ��
	int top;
}SqStrStack;
// 1.��ʼ��˳���ַ�ջ
void InitSqStrStack(SqStrStack& S);
// 2.��˳���ַ�ջ
bool PushSqStrStack(SqStrStack& S, char x);
// 3.��˳���ַ�ջ
char PopSqStrStack(SqStrStack& S);
// 4.��˳���ַ�ջ��
bool EmptySqStrStack(SqStrStack S);

// ���ܲ���
void MainSqStack();

// ��Ŀ���
// 3.
// �жϽ�ջ��ջ�Ƿ�Ϸ�
bool JudgeStack(char A[]);
void SolveStack_3();
// 4.
// β�彨���ַ�������
LinkList TailInsertLinkList(LinkList& L);
// ��ӡ�ַ�������
void PrintLinkList(LinkList L);
// ��ȡ�ַ�����������
int LengthLinkList(LinkList L);
// �ж�����ȫ��n���ַ��Ƿ����ĶԳ�
bool dcStackLinkList(LinkList L, int n);
void SolveStack_4();
// 5.
// ��ջ��i����ջ��
bool PushSTK(STK& s, int i, ElemtType x);
// ��ջ��i����ջ��
ElemtType PopSTK(STK& s, int i);
// ��ӡ
void PrintSqStack(STK S);
void SolveStack_5();

// 3.1
bool BracketsCheck(char* str);
void SolveStackQueue_1();
// 3.2
void TrainArrange(char* train);
void SolveStackQueue_2();
// 3.3
double p(int n, double x);
void SolveStackQueue_3();
#endif // _SQSTACK_H_
