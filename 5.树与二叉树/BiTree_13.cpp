#include <stdio.h>
#include "BiTree.h"

typedef struct {
	BiTNode* t;
	// tag=0表示左子树被访问，tag=1表示右子树被访问
	int tag;
}stack;

stack s[255], s1[255];
// 13.找p、q最近的公共祖先结点r
BiTNode* Ancestor(BiTree ROOT, BiTNode* p, BiTNode* q) {
	int top = 0;
	int top1 = 0;
	int i, j;
	BiTNode* bt = ROOT;
	// 后续遍历二叉树
	while (bt != NULL || top > 0) {
		// 若结点不为空，进栈（不需要加“&& bt != p && bt != q”----结点没入栈，找不到结点的）
		while (bt != NULL) {
			s[++top].t = bt;
			s[top].tag = 0;
			// 左子树向下
			bt = bt->lchild;
		}
		while (top != 0 && s[top].tag == 1) {
			// 假定p在q的左侧，遇到p时，s中元素备份进s1
			if (s[top].t == p) {
				// 将栈中元素备份进s1，s1中为p的祖先
				for (i = 1; i <= top; i++) {
					s1[i] = s[i];
					top1 = top;
				}
			}
			// 遇到q结点
			if (s[top].t == q) {
				// 将栈中元素与s1中一一匹配
				for (i = top; i > 0; i--) {
					for (j = top1; j > 0; j--) {
						// 若相等，返回最近公共祖先
						if (s1[j].t == s[i].t) {
							return s[i].t;
							printf("周到");
						}
					}
				}
			}
			// 退栈
			top--;
		}
		if (top != 0) {
			s[top].tag = 1;
			bt = s[top].t->rchild;
		}
	}
	return NULL;
}

// 后续遍历找到值为x的
BiTNode* SearchX(BiTree T, ElemtType x) {
	stack S[255];
	int top = 0;
	BiTNode* p = T;
	// 后续遍历二叉树
	while (p != NULL || top > 0) {
		// 若结点不为空并且数据不为x时入栈
		while (p != NULL && p->data != x) {
			S[++top].t = p;
			S[top].tag = 0;
			// 左子树向下
			p = p->lchild;
		}
		// 如果值为x，找到x，返回    (相对于书上加了个条件，不然无法运行（有NULL）)
		if (p != NULL && p->data == x)
			return p;
		// 退栈（右子树访问过的退）
		while (top != 0 && S[top].tag == 1)
			top--;
		// 向右子树遍历
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
	printf("后序为：");
	PostOrder(ROOT);
	BiTNode* p = SearchX(ROOT, 'E');
	BiTNode* q = SearchX(ROOT, 'C');
	BiTNode* ans = Ancestor(ROOT, p, q);
	if (ans)
		printf("\nE和C的共同祖先为%c", ans->data);
	else
		printf("\n没找到");
}