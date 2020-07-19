#include <stdio.h>
#include "ThisString.h"

// 0.初始化Temp操作
void InitTemp(char Temp[]) {
	int i = 0;
	scanf("%c", &Temp[i]);
	while (Temp[i] != '\n')
		scanf("%c", &Temp[++i]);
	Temp[i] = '\0';
}
// 1.赋值操作
void AssignSTr(SString& S, char cs[]) {
	int i = 1;
	while (cs[i - 1 ] != '\0')
		S.ch[i++] = cs[i - 1];
	S.ch[i] = '\0';
	S.length = i - 1;
}
// 2.复制操作
void CopySTr(SString& T, SString S) {
	int i = 1;
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
	int i = 1;
	for (i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}
// 5.求串长
int LengthSTr(SString S) {
	return S.length;
}
// 6.求子串
bool SubSTr(SString& Sub, SString S, int pos, int len) {
	int i = 1;
	if (pos + len - 1 > S.length)
		return false;
	while (i <= len)
		Sub.ch[i++] = S.ch[pos++];
	Sub.ch[i] = '\0';
	Sub.length = len;
	return true;
}
// 7.串连接
void ConcatSTr(SString& T, SString S1, SString S2) {
	int i = 1;
	while (S1.ch[i] != '\0')
		T.ch[i++] = S1.ch[i];
	int j = 1;
	while (S2.ch[j] != '\0')
		T.ch[i++] = S2.ch[j++];
	T.ch[i] = '\0';
	T.length = S1.length + S2.length;
}
// 8.定位操作
int IndexSTr(SString S, SString T) {
	int i = 1, j;
	int n = LengthSTr(S);
	int m = LengthSTr(T);
	SString Sub;
	while (i <= n - m + 1) {
		SubSTr(Sub, S, i, m);
		j = 0;
		while (T.ch[j] != '\0' && T.ch[j] == Sub.ch[j])
			j++;
		if (T.ch[j]=='\0')
			return i;
		else
			i++;
	}
	return 0;
}
// 9.清空操作
void ClearSTr(SString& S) {
	S.ch[1] = '\0';
}
// 10.销毁操作
void DestroySTr(SString& S) {

}
// 11.打印操作
void PrintSTr(SString S) {
	int i = 1;
	while (S.ch[i]!='\0')
		printf("%c", S.ch[i++]);
	printf("\n");
}

// 实现
void MainThisString() {
	char stemp[255];
	// 1.赋值操作
	// S1
	SString S1;
	printf("请输入字符串S1：");
	InitTemp(stemp);
	AssignSTr(S1, stemp);
	// S2
	SString S2;
	printf("请输入字符串S2：");
	InitTemp(stemp);
	AssignSTr(S2, stemp);
	printf("字符串S1为：");
	PrintSTr(S1);
	printf("字符串S2为：");
	PrintSTr(S2);
	// 2.复制操作
	SString T;
	CopySTr(T, S1);
	printf("2、字符串T为：");
	PrintSTr(T);
	// 3.判空操作
	if (EmptySTr(S1))
		printf("3、S1为空\n");
	else
		printf("3、S1非空\n");
	// 4.比较操作
	int com = CompareSTr(S1, S2);
	if (com ==1)
		printf("4、S1比S2长\n");
	else if (com ==0)
		printf("4、S1与S2一样长\n");
	else
		printf("4、S1比S2短\n");
	// 5.求串长
	printf("5、S1长为%d\n", LengthSTr(S1));
	// 6.求子串
	SString Sub;
	int pos = 2;
	int len = 2;
	SubSTr(Sub, S1, pos, len);
	printf("6、S1从2个字符起长度为2的子串Sub为：");
	PrintSTr(Sub);
	printf("  子串Sub长为：%d\n", LengthSTr(Sub));
	// 7.串连接
	ConcatSTr(T, S1, S2);
	printf("7、S1和S2联结后的新串T为：");
	PrintSTr(T);
	printf("  新串T长为：%d\n", LengthSTr(T));
	// 8.定位操作
	int index = IndexSTr(S1, S2);
	if (index == 0)
		printf("8、S1中未找到与S2相同的子串\n");
	else
		printf("8、S2出现在S1的第%d个字符开始\n", index);
	// 9.清空操作
	ClearSTr(S1);
	printf("9、清空的S1为：");
	PrintSTr(S1);
}