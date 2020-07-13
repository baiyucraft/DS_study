#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// 2.火车呜呜呜~
void TrainArrange(char* train) {
	// H硬座，S软座
	char* p = train;
	char* q = train;
	SqStrStack S;
	InitSqStrStack(S);
	// p指针遍历字符串
	while (*p != '\0'){
		// 如果为H，放入栈
		if (*p == 'H')
			PushSqStrStack(S, *p);
		// 如果为S，放入前面的空间（先走）
		else
			*(q++) = *p;
		p++;
	}
	// 将栈中的H全部取出
	while (!EmptySqStrStack(S)) 
		*(q++) = PopSqStrStack(S);
}

void SolveStackQueue_2() {
	//char x[]= "HSHSHHSHSHSHSHSSHS";
	char* x = (char*)malloc(sizeof(char) * MaxSize);
	printf("请输入一串只有H和S的字符串：");
	scanf("%s", x);
	printf("原字符串为：%s\n", x);
	TrainArrange(x);
	printf("现字符串为：%s\n", x);
}