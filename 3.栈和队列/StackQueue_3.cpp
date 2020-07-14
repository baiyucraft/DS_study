#include <stdio.h>
#include "SqStack.h"

double p(int n, double x) {
	typedef struct {
		// ����n
		int no;
		// ����Pn(x)��ֵ
		double val;
	}stack;
	stack st[MaxSize];
	// topΪst��ָ��
	int top = -1, i;
	// n=0��n=1�ĳ�ֵ
	double fv1 = 1, fv2 = 2 * x;
	for (i = n; i >= 2; i--) 
		st[++top].no = i;
	// �Զ����׸�ֵ
	while (top >= 0) {
		// ��ջ��Ԫ�ظ�ֵ
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
	printf("������n��x��");
	scanf("%d %lf", &n, &x);
	printf("����Ľ��Ϊ��%lf\n", p(n, x));
}