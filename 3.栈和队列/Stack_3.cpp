#include <stdio.h>
#include "SqStack.h"

// 判断进栈出栈是否合法
bool JudgeStack(char A[]) {
	// 遍历操作数组的i
	int i = 0;
	// j、k分别存储I、O的个数
	int j = 0;
	int k = 0;
	// 遍历操作数组
	while (A[i] != '\0') {
		switch (A[i]) {
		case 'I':j++; break;
		case 'O':k++; 
			// 如果出栈次数超出入栈、序列非法
			if (k > j) {
				printf("序列非法\n");
				return false;
			}
		}
		i++;
	}
	if(j!=k){
		printf("序列非法\n");
		return false;
	}
	else{
		printf("序列合法\n");
		return true;
	}
}

void SolveStack_3() {
	char A[] = "IOIIOIOO";
	char B[] = "IOOIOIIO";
	char C[] = "IIIOIOIO";
	char D[] = "IIIOOIOO";
	printf("选项A：");
	JudgeStack(A);
	printf("选项B：");
	JudgeStack(B);
	printf("选项C：");
	JudgeStack(C);
	printf("选项D：");
	JudgeStack(D);
}