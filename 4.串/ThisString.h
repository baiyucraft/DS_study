// ��
#ifndef _THISSTRING_H_
#define _THISSTRING_H_

#define MAXLEN 255;
// �����洢��˳��
typedef struct {
	char ch[255];
	int length;
}SString;
// �ѷ���洢�Ĵ�
typedef struct {
	char* ch;
	int length;
}HString;

// ����ʵ��
// 1.��ֵ����
void AssignSTr(SString& S, char cs[]);
// 2.���Ʋ���
void CopySTr(SString& T, SString S);
// 3.�пղ���
bool EmptySTr(SString S);
// 4.�Ƚϲ���
int CompareSTr(SString S, SString T);
// 5.�󴮳�
int LengthSTr(SString S);
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
void PrintSTr(SString S);

// ʵ��
void MainThisString();
#endif // _THISSTRING_H_
