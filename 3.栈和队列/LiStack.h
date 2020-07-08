// 链栈
#ifndef _LiSTACK_H_
#define _LiSTACK_H_
// 定义元素类型
typedef int ElemtType;
// 顺序栈
typedef struct LiStackNode {
	// 栈元素个数
	ElemtType data;
	// 栈顶指针
	struct LiStackNode *next;
}LiStackNode,*LiStackLink;

// 1.初始化栈
//void InitSqStack(SqStack& S);
// 2.进栈
//bool PushSqStack(SqStack& S, ElemtType x);
// 3.出栈
//ElemtType PopSqStack(SqStack& S);
// 4.判栈空
//bool EmptySqStack(SqStack S);
// 5.读栈顶元素
//ElemtType GetTopSqStack(SqStack S);
// 6.打印当前栈
//void PrintSqStack(SqStack S);
// 7.销毁栈
//bool DestroySqStack(SqStack& S);

// 功能测试
void MainLiStack();

#endif // _LiSTACK_H_
#pragma once
