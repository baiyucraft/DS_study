#include <stdio.h>
#include "SqStack.h"

// 1.����ƥ��
bool BracketsCheck(char* str) {
	SqStrStack S;
	InitSqStrStack(S);
	int i = 0;
	char e;
	while (str[i] != '\0') {
		switch (str[i]) {
		// ��������ջ
		case '(':PushSqStrStack(S, '('); break;
		case '[':PushSqStrStack(S, '['); break;
		case '{':PushSqStrStack(S, '{'); break;
		// �������ж�
		case ')':
			e = PopSqStrStack(S);
			if (e != '(') return false;
			break;
		case ']':
			e = PopSqStrStack(S);
			if (e != '[') return false;
			break;
		case '}':
			e = PopSqStrStack(S);
			if (e != '{') return false;
			break;
		default: break;
		}
		i++;
	}
	if (EmptySqStrStack(S)) {
		printf("���Ų�ƥ��\n");
		return false;
	}
	else {
		printf("����ƥ��\n");
		return true;
	}
}

void SolveStackQueue_1() {
	char x;
	printf("������һ���ַ�����");
	scanf("%c", &x);
	BracketsCheck(&x);
}