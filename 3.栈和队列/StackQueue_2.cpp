#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

// 2.��������~
void TrainArrange(char* train) {
	// HӲ����S����
	char* p = train;
	char* q = train;
	SqStrStack S;
	InitSqStrStack(S);
	// pָ������ַ���
	while (*p != '\0'){
		// ���ΪH������ջ
		if (*p == 'H')
			PushSqStrStack(S, *p);
		// ���ΪS������ǰ��Ŀռ䣨���ߣ�
		else
			*(q++) = *p;
		p++;
	}
	// ��ջ�е�Hȫ��ȡ��
	while (!EmptySqStrStack(S)) 
		*(q++) = PopSqStrStack(S);
}

void SolveStackQueue_2() {
	//char x[]= "HSHSHHSHSHSHSHSSHS";
	char* x = (char*)malloc(sizeof(char) * MaxSize);
	printf("������һ��ֻ��H��S���ַ�����");
	scanf("%s", x);
	printf("ԭ�ַ���Ϊ��%s\n", x);
	TrainArrange(x);
	printf("���ַ���Ϊ��%s\n", x);
}