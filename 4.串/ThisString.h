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
// 0.��ʼ��Temp����
void InitTemp(char Temp[]);
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
bool SubSTr(SString& Sub, SString S, int pos, int len);
// 7.������
void ConcatSTr(SString& T, SString S1, SString S2);
// 8.��λ����
int IndexSTr(SString S, SString T);
// 9.��ղ���
void ClearSTr(SString& S);
// 10.���ٲ���
void DestroySTr(SString& S);
// 11.��ӡ����
void PrintSTr(SString S);

// ʵ��
void MainThisString();
// ģʽƥ��ʵ��
// 1.����ƥ��
int IndexSTrVio(SString S, SString T);
void SolveindexVio();
// 2.KMP
int IndexSTrKMP(SString S, SString T);
void SolveindexKMP();

#endif // _THISSTRING_H_
