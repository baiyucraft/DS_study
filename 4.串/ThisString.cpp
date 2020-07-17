#include <stdio.h>
#include "ThisString.h"

// 0.初始化操作
void InitSTr(SString& S) {
	int i = 0;
	printf("请输入字符串S：");
	scanf("%c", &S.ch[i]);
	while (S.ch[i] != '\n')
		scanf("%c", &S.ch[++i]);
	S.ch[i] = '\0';
	S.length = i;
}
// 1.赋值操作
void AssignSTr(SString& S, char cs[]) {
	int i = 0;
	while (S.ch[i] != '\0')
		cs[i++] = S.ch[i];
	cs[i] = '\0';
}
// 2.复制操作
void CopySTr(SString& T, SString S) {
	int i = 0;
	while (S.ch[i] != '\0')
		T.ch[i++] = S.ch[i];
	T.ch[i] = '\0';
	T.length = S.length;
}
// 3.判空操作
bool EmptySTr(SString S) {
	if (S.length == 0)
		return true;
	return false;
}
// 4.比较操作
int CompareSTr(SString S, SString T) {
	if (S.length > T.length)
		return 1;
	else if (S.length == T.length)
		return 0;
	else
		return -1;
}
// 5.求串长
int LengthSTr(SString S) {
	return S.length;
}
// 6.求子串
SString SubSTr(SString S, int pos, int len);
// 7.串连接
SString ConcatSTr(SString S1, SString S2);
// 8.定位操作
void IndexSTr(SString S, SString T);
// 9.清空操作
void ClearSTr(SString& S);
// 10.销毁操作
void DestroySTr(SString& S);
// 11.打印操作
void PrintSTr(SString S) {
	printf("%s\n", S.ch);
}

// 实现
void MainThisString() {
	SString S1;
	InitSTr(S1);
	printf("字符串S1为：");
	PrintSTr(S1);
	// 1.赋值操作
	char stemp[255];
	AssignSTr(S1, stemp);
	printf("字符串stemp为：");
	printf("%s\n", stemp);
	// 2.复制操作
	SString T;
	CopySTr(T, S1);
	printf("字符串T为：");
	PrintSTr(T);
	// 3.判空操作
	if (EmptySTr(S1))
		printf("S1为空\n");
	else
		printf("S1非空\n");
	// 4.比较操作
	int com = CompareSTr(S1, T);
	if (com ==1)
		printf("S1比T长\n");
	else if (com ==0)
		printf("S1与T一样长\n");
	else
		printf("S1比T短\n");
	// 5.求串长
	printf("S1长为%d\n", LengthSTr(S1));
}