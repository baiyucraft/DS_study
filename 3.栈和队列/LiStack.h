// ��ջ
#ifndef _LiSTACK_H_
#define _LiSTACK_H_
// ����Ԫ������
typedef int ElemtType;
// ˳��ջ
typedef struct LiStackNode {
	// ջԪ�ظ���
	ElemtType data;
	// ջ��ָ��
	struct LiStackNode *next;
}LiStackNode,*LiStackLink;

// 1.��ʼ��ջ
//void InitSqStack(SqStack& S);
// 2.��ջ
//bool PushSqStack(SqStack& S, ElemtType x);
// 3.��ջ
//ElemtType PopSqStack(SqStack& S);
// 4.��ջ��
//bool EmptySqStack(SqStack S);
// 5.��ջ��Ԫ��
//ElemtType GetTopSqStack(SqStack S);
// 6.��ӡ��ǰջ
//void PrintSqStack(SqStack S);
// 7.����ջ
//bool DestroySqStack(SqStack& S);

// ���ܲ���
void MainLiStack();

#endif // _LiSTACK_H_
#pragma once
