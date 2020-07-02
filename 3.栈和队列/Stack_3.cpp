#include <stdio.h>
#include "SqStack.h"

// �жϽ�ջ��ջ�Ƿ�Ϸ�
bool JudgeStack(char A[]) {
	// �������������i
	int i = 0;
	// j��k�ֱ�洢I��O�ĸ���
	int j = 0;
	int k = 0;
	// ������������
	while (A[i] != '\0') {
		switch (A[i]) {
		case 'I':j++; break;
		case 'O':k++; 
			// �����ջ����������ջ�����зǷ�
			if (k > j) {
				printf("���зǷ�\n");
				return false;
			}
		}
		i++;
	}
	if(j!=k){
		printf("���зǷ�\n");
		return false;
	}
	else{
		printf("���кϷ�\n");
		return true;
	}
}

void SolveStack_3() {
	char A[] = "IOIIOIOO";
	char B[] = "IOOIOIIO";
	char C[] = "IIIOIOIO";
	char D[] = "IIIOOIOO";
	printf("ѡ��A��");
	JudgeStack(A);
	printf("ѡ��B��");
	JudgeStack(B);
	printf("ѡ��C��");
	JudgeStack(C);
	printf("ѡ��D��");
	JudgeStack(D);
}