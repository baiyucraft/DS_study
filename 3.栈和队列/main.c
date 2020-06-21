#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	// 学号
	int id;
	// 数量
	int num;
	// 时间
	int time;
}Stu, *StuList;

StuList GetData(int* length) {
	// 输入文件指针
	FILE* fin = fopen("in.txt", "r");
	fscanf(fin, "%d", length);
	// 动态分配空间
	StuList s = (StuList)calloc(*length, sizeof(Stu));
	for (int i = 0; i < (*length); i++) {
		fscanf(fin, "%d %d %d", &s[i].id, &s[i].num, &s[i].time);
	}
	fclose(fin);
	return s;
}
// 排序
void Select(StuList s,int length) {
	Stu temp;
	int i, j;
	for (i = length - 1; i >= 0; i--) {
		for (j = 0; j < i; j++) {
			printf("%d %d-%d %d-%d\n", j + 1, s[j].num, s[j + 1].num, s[j].time, s[j + 1].time);
			if (s[j].num < s[j + 1].num) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
			else if (s[j].num == s[j + 1].num) {
				if (s[j].time > s[j + 1].time) {
					temp = s[j];
					s[j] = s[j + 1];
					s[j + 1] = temp;
				}
			}
		}
	}
}
// 输出
void PrintData(StuList s, int length) {
	// 输出文件指针
	FILE* fout = fopen("out.txt", "w");
	fprintf(fout, "%d\n", length);
	for (int i = 0; i < length; i++) {
		fprintf(fout, "%d %d %d\n", s[i].id, s[i].num, s[i].time);
	}
	fclose(fout);
}

int main(){
	int length;
	StuList s = GetData(&length);
	Select(s, length);
	PrintData(s, length);
}

