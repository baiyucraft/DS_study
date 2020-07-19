#include <stdio.h>
#include "ThisString.h"

// 0.��ʼ��Temp����
void InitTemp(char Temp[]) {
	int i = 0;
	scanf("%c", &Temp[i]);
	while (Temp[i] != '\n')
		scanf("%c", &Temp[++i]);
	Temp[i] = '\0';
}
// 1.��ֵ����
void AssignSTr(SString& S, char cs[]) {
	int i = 1;
	while (cs[i - 1 ] != '\0')
		S.ch[i++] = cs[i - 1];
	S.ch[i] = '\0';
	S.length = i - 1;
}
// 2.���Ʋ���
void CopySTr(SString& T, SString S) {
	int i = 1;
	while (S.ch[i] != '\0')
		T.ch[i++] = S.ch[i];
	T.ch[i] = '\0';
	T.length = S.length;
}
// 3.�пղ���
bool EmptySTr(SString S) {
	if (S.length == 0)
		return true;
	return false;
}
// 4.�Ƚϲ���
int CompareSTr(SString S, SString T) {
	int i = 1;
	for (i = 1; i <= S.length && i <= T.length; i++) {
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	}
	return S.length - T.length;
}
// 5.�󴮳�
int LengthSTr(SString S) {
	return S.length;
}
// 6.���Ӵ�
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
// 7.������
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
// 8.��λ����
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
// 9.��ղ���
void ClearSTr(SString& S) {
	S.ch[1] = '\0';
}
// 10.���ٲ���
void DestroySTr(SString& S) {

}
// 11.��ӡ����
void PrintSTr(SString S) {
	int i = 1;
	while (S.ch[i]!='\0')
		printf("%c", S.ch[i++]);
	printf("\n");
}

// ʵ��
void MainThisString() {
	char stemp[255];
	// 1.��ֵ����
	// S1
	SString S1;
	printf("�������ַ���S1��");
	InitTemp(stemp);
	AssignSTr(S1, stemp);
	// S2
	SString S2;
	printf("�������ַ���S2��");
	InitTemp(stemp);
	AssignSTr(S2, stemp);
	printf("�ַ���S1Ϊ��");
	PrintSTr(S1);
	printf("�ַ���S2Ϊ��");
	PrintSTr(S2);
	// 2.���Ʋ���
	SString T;
	CopySTr(T, S1);
	printf("2���ַ���TΪ��");
	PrintSTr(T);
	// 3.�пղ���
	if (EmptySTr(S1))
		printf("3��S1Ϊ��\n");
	else
		printf("3��S1�ǿ�\n");
	// 4.�Ƚϲ���
	int com = CompareSTr(S1, S2);
	if (com ==1)
		printf("4��S1��S2��\n");
	else if (com ==0)
		printf("4��S1��S2һ����\n");
	else
		printf("4��S1��S2��\n");
	// 5.�󴮳�
	printf("5��S1��Ϊ%d\n", LengthSTr(S1));
	// 6.���Ӵ�
	SString Sub;
	int pos = 2;
	int len = 2;
	SubSTr(Sub, S1, pos, len);
	printf("6��S1��2���ַ��𳤶�Ϊ2���Ӵ�SubΪ��");
	PrintSTr(Sub);
	printf("  �Ӵ�Sub��Ϊ��%d\n", LengthSTr(Sub));
	// 7.������
	ConcatSTr(T, S1, S2);
	printf("7��S1��S2�������´�TΪ��");
	PrintSTr(T);
	printf("  �´�T��Ϊ��%d\n", LengthSTr(T));
	// 8.��λ����
	int index = IndexSTr(S1, S2);
	if (index == 0)
		printf("8��S1��δ�ҵ���S2��ͬ���Ӵ�\n");
	else
		printf("8��S2������S1�ĵ�%d���ַ���ʼ\n", index);
	// 9.��ղ���
	ClearSTr(S1);
	printf("9����յ�S1Ϊ��");
	PrintSTr(S1);
}