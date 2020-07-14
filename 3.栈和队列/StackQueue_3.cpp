#include <stdio.h>
#include "SqStack.h"

double p(int n, double x) {
	typedef struct {
		// 保存n
		int no;
		// 保存Pn(x)的值
		double val;
	}stack;
	stack st[MaxSize];
	// top为st的指针
	int top = -1, i;
	// n=0和n=1的初值
	double fv1 = 1, fv2 = 2 * x;
	for (i = n; i >= 2; i--) 
		st[++top].no = i;
	// 自顶到底赋值
	while (top >= 0) {
		// 给栈顶元素赋值
		st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
		fv1 = fv2;
		fv2 = st[top--].val;
	}
	if (n == 0)
		return fv1;
	return fv2;
}

void SolveStackQueue_3() {
	int n;
	double x;
	printf("请输入n和x：");
	scanf("%d %lf", &n, &x);
	printf("计算的结果为：%lf\n", p(n, x));
}