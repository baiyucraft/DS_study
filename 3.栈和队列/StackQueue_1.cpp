#include <stdio.h>
#include "SqStack.h"

// 1.¿®∫≈∆•≈‰
bool BracketsCheck(char* str) {
	SqStrStack S;
	InitSqStrStack(S);
	int i = 0;
	char e;
	while (str[i] != '\0') {
		switch (str[i]) {
		// ◊Û¿®∫≈»Î’ª
		case '(':PushSqStrStack(S, '('); break;
		case '[':PushSqStrStack(S, '['); break;
		case '{':PushSqStrStack(S, '{'); break;
		// ”“¿®∫≈≈–∂œ
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
		printf("¿®∫≈≤ª∆•≈‰\n");
		return false;
	}
	else {
		printf("¿®∫≈∆•≈‰\n");
		return true;
	}
}

void SolveStackQueue_1() {
	char x;
	printf("«Î ‰»Î“ª¥Æ◊÷∑˚¥Æ£∫");
	scanf("%c", &x);
	BracketsCheck(&x);
}