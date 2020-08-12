#include <stdio.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

void InvertLevelOrder(BiTree BT) {
    BiTNodeStack S;
    BiTNodeQueue Q;
    InitBiTNodeStack(S);
    InitBiTNodeQueue(Q);
    // 遍历p结点
    BiTNode* p = BT;
    // 根结点入栈
    EnBiTNodeQueue(Q, BT);
    // 队列非空
    while (!EmptyBiTNodeQueue(Q)) {
        p = DeBiTNodeQueue(Q);
        PushBiTNodeStack(S, p);
        // 如果有左子树，进队
        if (p->lchild != NULL)
            EnBiTNodeQueue(Q, p->lchild);
        // 如果有右子树，进队
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