#include <stdio.h>
#include "BiTree.h"

typedef struct {
	BiTNode* t;
	// tag=0��ʾ�����������ʣ�tag=1��ʾ������������
	int tag;
}stack;

stack s[255], s1[255];
// 13.��p��q����Ĺ������Ƚ��r
BiTNode* Ancestor(BiTree ROOT, BiTNode* p, BiTNode* q) {
	int top = 0;
	int top1 = 0;
	int i, j;
	BiTNode* bt = ROOT;
	// ��������������
	while (bt != NULL || top > 0) {
		// ����㲻Ϊ�գ���ջ������Ҫ�ӡ�&& bt != p && bt != q��----���û��ջ���Ҳ������ģ�
		while (bt != NULL) {
			s[++top].t = bt;
			s[top].tag = 0;
			// ����������
			bt = bt->lchild;
		}
		while (top != 0 && s[top].tag == 1) {
			// �ٶ�p��q����࣬����pʱ��s��Ԫ�ر��ݽ�s1
			if (s[top].t == p) {
				// ��ջ��Ԫ�ر��ݽ�s1��s1��Ϊp������
				for (i = 1; i <= top; i++) {
					s1[i] = s[i];
					top1 = top;
				}
			}
			// ����q���
			if (s[top].t == q) {
				// ��ջ��Ԫ����s1��һһƥ��
				for (i = top; i > 0; i--) {
					for (j = top1; j > 0; j--) {
						// ����ȣ����������������
						if (s1[j].t == s[i].t) {
							return s[i].t;
							printf("�ܵ�");
						}
					}
				}
			}
			// ��ջ
			top--;
		}
		if (top != 0) {
			s[top].tag = 1;
			bt = s[top].t->rchild;
		}
	}
	return NULL;
}

// ���������ҵ�ֵΪx��
BiTNode* SearchX(BiTree T, ElemtType x) {
	stack S[255];
	int top = 0;
	BiTNode* p = T;
	// ��������������
	while (p != NULL || top > 0) {
		// ����㲻Ϊ�ղ������ݲ�Ϊxʱ��ջ
		while (p != NULL && p->data != x) {
			S[++top].t = p;
			S[top].tag = 0;
			// ����������
			p = p->lchild;
		}
		// ���ֵΪx���ҵ�x������    (��������ϼ��˸���������Ȼ�޷����У���NULL��)
		if (p != NULL && p->data == x)
			return p;
		// ��ջ�����������ʹ����ˣ�
		while (top != 0 && S[top].tag == 1)
			top--;
		// ������������
		if (top != 0) {
			S[top].tag = 1;
			p = S[top].t->rchild;
		}
	}
	return NULL;
}

void SolveBiTree_13() {
	BiTree ROOT;
	CreateBiTree(ROOT);
	printf("����Ϊ��");
	PostOrder(ROOT);
	BiTNode* p = SearchX(ROOT, 'E');
	BiTNode* q = SearchX(ROOT, 'C');
	BiTNode* ans = Ancestor(ROOT, p, q);
	if (ans)
		printf("\nE��C�Ĺ�ͬ����Ϊ%c", ans->data);
	else
		printf("\nû�ҵ�");
}