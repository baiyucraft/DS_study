#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

void InvertLevelOrder(BiTree BT) {
    BiTNodeStack S;
    BiTNodeQueue Q;
    InitBiTNodeStack(S);
    InitBiTNodeQueue(Q);
    // ����p���
    BiTNode* p = BT;
    // �������ջ
    EnBiTNodeQueue(Q, BT);
    // ���зǿ�
    while (!EmptyBiTNodeQueue(Q)) {
        p = DeBiTNodeQueue(Q);
        PushBiTNodeStack(S, p);
        // �����������������
        if (p->lchild != NULL)
            EnBiTNodeQueue(Q, p->lchild);
        // �����������������
        if (p->rchild != NULL)
            EnBiTNodeQueue(Q, p->rchild);
    }
    while (!EmptyBiTNodeStack(S)) {
        p = PopBiTNodeStack(S);
        visit(p);
    }
}

void SolveBiTree_4() {
	BiTree BT;
    CreateBiTree(BT);
    InvertLevelOrder(BT);
}