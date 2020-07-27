#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

// 1.ʹ�ù������������, �����ԡ��ַ�������������, ��'#'�ַ��������
void CreateBiTree(BiTree& BT) {
	BT = NULL;
	// p��¼��ǰ���
    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	// t��¼ջ��Ԫ��
	BiTNode* t;
    // ����ջ�洢ͷ���
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // �������������ı��
    int k;
	ElemtType ch;
	printf("����������");
	scanf("%c", &ch);
    while (ch != '#') {
        switch (ch) {
            // ��(����������ǰ�����Ϊ���׽�㣬��ָ�����ӽ��
        case '(':
            PushBiTNodeStack(S, p);
            k = 1;
            break;
            // ��)����������ǰ��������ﴴ����������ջ
        case ')':
            PopBiTNodeStack(S);
            break;
            // ��,�������������Һ��ӽ��
        case ',':
            k = 2;
            break;
        default:
            // �������
            p = (BiTNode*)malloc(sizeof(BiTNode));
            p->lchild = NULL;
            p->rchild = NULL;
            p->data = ch;
            // ������ڵ�Ϊ��
            if (BT == NULL) {
                BT = p;
            }
            // ����*t������
            else if (k == 1) {
                t = GetTopBiTNodeStack(S);
                
                t->lchild = p;
            }
            // ����*t���Һ���
            else
            {
                t = GetTopBiTNodeStack(S);
                t->rchild = p;
            }
        }
        scanf("%c", &ch);
    }
}
// 2.vist��㣨��ӡ��
void visit(BiTNode* T) {
    printf("%c->", T->data);
}
// 3.������������������ݹ飩
void PreOrder(BiTree BT) {
    if (BT != NULL) {
         visit(BT);
         PreOrder(BT->lchild);
         PreOrder(BT->rchild);
    }
}
// 3.������������������ǵݹ飩
void PreOrder2(BiTree BT) {
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // �������p
    BiTNode* p = BT;
    // ���p��Ϊ�ջ���ջ��Ϊ��ѭ������
    while (p || !EmptyBiTNodeStack(S)) {
        // ���p��Ϊ��
        if (p) {
            // ������ջ���
            visit(p);
            // ��ǰ�����ջ
            PushBiTNodeStack(S, p);
            // һ·����
            p = p->lchild;
        }
        // ���pΪ��
        else {
            // ջ��Ԫ�س�ջ
            p = PopBiTNodeStack(S);
            // ����������
            p = p->rchild;
        }
    }
}
// 4.������������������ݹ飩
void InOrder(BiTree BT) {
    if (BT != NULL) {
        InOrder(BT->lchild);
        visit(BT);
        InOrder(BT->rchild);
    }
}
// 4.������������������ǵݹ飩
void InOrder2(BiTree BT) {
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // �������p
    BiTNode* p = BT;
    // ���p��Ϊ�ջ���ջ��Ϊ��ѭ������
    while (p || !EmptyBiTNodeStack(S)) {
        // ���p��Ϊ��
        if (p) {
            // ��ǰ�����ջ
            PushBiTNodeStack(S, p);
            // һ·����
            p = p->lchild;
        }
        // ���pΪ��
        else {
            // ջ��Ԫ�س�ջ
            p = PopBiTNodeStack(S);
            // ���ʳ�ջ���
            visit(p);
            // ����������
            p = p->rchild;
        }
    }
}
// 5.�������ĺ���������ݹ飩
void PostOrder(BiTree BT) {
    if (BT != NULL) {
        PostOrder(BT->lchild);
        PostOrder(BT->rchild);
        visit(BT);
    }
}
// 5.�������ĺ���������ǵݹ飩
void PostOrder2(BiTree BT) {

}
// 6.��α���
void LevelOrder(BiTree BT) {
    BiTNodeQueue Q;
    InitBiTNodeQueue(Q);
    // ����p���
    BiTNode* p = BT;
    // �������ջ
    EnBiTNodeQueue(Q, BT);
    // ���зǿ�
    while (!EmptyBiTNodeQueue(Q)) {
        p = DeBiTNodeQueue(Q);
        visit(p);
        // �����������������
        if (p->lchild != NULL)
            EnBiTNodeQueue(Q, p->lchild);
        // �����������������
        if (p->rchild != NULL)
            EnBiTNodeQueue(Q, p->rchild);
    }
}

// ����������
// 1.ʹ�ù����������������
void CreateThreadTree(ThreadTree& BT) {
    BT = NULL;
    // p��¼��ǰ���
    ThreadNode* p = (ThreadNode*)malloc(sizeof(ThreadNode));
    // t��¼ջ��Ԫ��
    ThreadNode* t;
    // ����ջ�洢ͷ���
    ThreadNodeStack S;
    InitThreadNodeStack(S);
    // �������������ı��
    int k = 0;
    ElemtType ch;
    printf("������������������������");
    scanf("%c", &ch);
    while (ch != '#') {
        switch (ch) {
            // ��(����������ǰ�����Ϊ���׽�㣬��ָ�����ӽ��
        case '(':
            PushThreadNodeStack(S, p);
            k = 1;
            break;
            // ��)����������ǰ��������ﴴ����������ջ
        case ')':
            PopThreadNodeStack(S);
            break;
            // ��,�������������Һ��ӽ��
        case ',':
            k = 2;
            break;
        default:
            // �������
            p = (ThreadNode*)malloc(sizeof(ThreadNode));
            p->lchild = NULL;
            p->rchild = NULL;
            p->ltag = 0;
            p->rtag = 0;
            p->data = ch;
            // ������ڵ�Ϊ��
            if (BT == NULL) {
                BT = p;
            }
            // ����*t������
            else if (k == 1) {
                t = GetTopThreadNodeStack(S);
                t->lchild = p;
            }
            // ����*t���Һ���
            else
            {
                t = GetTopThreadNodeStack(S);
                t->rchild = p;
            }
        }
        scanf("%c", &ch);
    }
}
// 2.vistThread��㣨��ӡ��
void visitThread(ThreadNode* T) {
    printf("%c->", T->data);
}

// 3.1.�����������������
void CreateInThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    // �ǿն�������������
    if (T != NULL) {
        InThread(T, pre);
        // �������һ�����
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
// 3.2.���������������������
void InThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        // �ݹ飬������������
        InThread(p->lchild, pre);
        // ������Ϊ�գ�����ǰ������
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            // ����ǰ�����ĺ�̽��
            pre->rchild = p;
            pre->rtag = 1;
        }
        // ��ǵ�ǰ���Ϊ�ոշ��ʹ��Ľ��
        pre = p;
        // ������������
        InThread(p->rchild, pre);
    }
}
// 3.3.����������µĵ�һ�����
ThreadNode* FirstInNode(ThreadNode* p) {
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 3.4.��p�������������µĺ�̽��
ThreadNode* NextInNode(ThreadNode* p) {
    if (p->rtag == 0)
        return FirstInNode(p->rchild);
    else
        return p->rchild;
}
// 3.5.������������µ����һ�����
ThreadNode* LastInNode(ThreadNode* p) {
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 3.6.��p�������������µ�ǰ�����
ThreadNode* PreInNode(ThreadNode* p) {
    if (p->ltag == 0)
        return FirstInNode(p->lchild);
    else
        return p->lchild;
}
// 3.7.�󲻺�ͷ����������������������������㷨
void InThreadOrder(ThreadTree T) {
    for (ThreadNode* p = FirstInNode(T); p != NULL; p = NextInNode(p))
        visitThread(p);
}

// �������Ĵ��������
void MainBiTree() {
	BiTree BT;
    // ��  A(B(D,E(G,)),C(,F))#
	CreateBiTree(BT);
    // ����
    printf("3.�������������ݹ飩Ϊ��");
    PreOrder(BT);
    printf("\n3.�������������ǵݹ飩Ϊ��");
    PreOrder2(BT);
    // ����
    printf("\n4.�������������ݹ飩Ϊ��");
    InOrder(BT);
    printf("\n4.�������������ǵݹ飩Ϊ��");
    InOrder2(BT);
    // ����
    printf("\n5.�������������ݹ飩Ϊ��");
    PostOrder(BT);
    printf("\n5.�������������ǵݹ飩Ϊ��");
    PostOrder2(BT);
    // ��α���
    printf("\n6.��α������Ϊ��");
    LevelOrder(BT);
}

void MainThreadTree() {
    // ����������
    ThreadTree T;
    ThreadNode* p;
    // ������������������ֵ��
    // A(B(,D),C(E,))#
    CreateThreadTree(T);
    // 1���򴴽�
    CreateInThread(T);
    // 1.1
    p = FirstInNode(T);
    printf("1.1��������µĵ�һ�����Ϊ��%c", p->data);
    // 1.2
    p = NextInNode(p);
    printf("\n1.2p�������������µĺ�̽��Ϊ��%c", p->data);
    // 1.3
    p = LastInNode(T);
    printf("\n1.3��������µ����һ�����Ϊ��%c", p->data);
    // 1.4
    p = PreInNode(p);
    printf("\n1.4p�������������µ�ǰ�����Ϊ��%c", p->data);
    // 1.5
    printf("\n1.5����ͷ����������������������������㷨��");
    InThreadOrder(T);
}