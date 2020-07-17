// 串
#ifndef _THISSTRING_H_
#define _THISSTRING_H_

#define MAXLEN 255;
// 定长存储的顺序串
typedef struct {
	char ch[255];
	int length;
}SString;
// 堆分配存储的串
typedef struct {
	char* ch;
	int length;
}HString;

// 基本实现
// 1.赋值操作
void AssignSTr(SString& S, char cs[]);
// 2.复制操作
void CopySTr(SString& T, SString S);
// 3.判空操作
bool EmptySTr(SString S);
// 4.比较操作
int CompareSTr(SString S, SString T);
// 5.求串长
int LengthSTr(SString S);
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
void PrintSTr(SString S);

// 实现
void MainThisString();
#endif // _THISSTRING_H_
