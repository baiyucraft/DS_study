#include <stdio.h>
#include "ThisString.h"

// 0.��ʼ������
void InitSTr(SString& S) {
	int i = 0;
	printf("�������ַ���S��");
	scanf("%c", &S.ch[i]);
	while (S.ch[i] != '\n')
		scanf("%c", &S.ch[++i]);
	S.ch[i] = '\0';
	S.length = i;
}
// 1.��ֵ����
void AssignSTr(SString& S, char cs[]) {
	int i = 0;
	while (S.ch[i] != '\0')
		cs[i++] = S.ch[i];
	cs[i] = '\0';
}
// 2.���Ʋ���
void CopySTr(SString& T, SString S) {
	int i = 0;
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
	if (S.length > T.length)
		return 1;
	else if (S.length == T.length)
		return 0;
	else
		return -1;
}
// 5.�󴮳�
int LengthSTr(SString S) {
	return S.length;
}
// 6.���Ӵ�
SString SubSTr(SString S, int pos, int len);
// 7.������
SString ConcatSTr(SString S1, SString S2);
// 8.��λ����
void IndexSTr(SString S, SString T);
// 9.��ղ���
void ClearSTr(SString& S);
// 10.���ٲ���
void DestroySTr(SString& S);
// 11.��ӡ����
void PrintSTr(SString S) {
	printf("%s\n", S.ch);
}

// ʵ��
void MainThisString() {
	SString S1;
	InitSTr(S1);
	printf("�ַ���S1Ϊ��");
	PrintSTr(S1);
	// 1.��ֵ����
	char stemp[255];
	AssignSTr(S1, stemp);
	printf("�ַ���stempΪ��");
	printf("%s\n", stemp);
	// 2.���Ʋ���
	SString T;
	CopySTr(T, S1);
	printf("�ַ���TΪ��");
	PrintSTr(T);
	// 3.�пղ���
	if (EmptySTr(S1))
		printf("S1Ϊ��\n");
	else
		printf("S1�ǿ�\n");
	// 4.�Ƚϲ���
	int com = CompareSTr(S1, T);
	if (com ==1)
		printf("S1��T��\n");
	else if (com ==0)
		printf("S1��Tһ����\n");
	else
		printf("S1��T��\n");
	// 5.�󴮳�
	printf("S1��Ϊ%d\n", LengthSTr(S1));
}