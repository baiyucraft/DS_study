#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "BiTNodeStack.h"
#include "BiTNodeQueue.h"

// 1.使用广义表创建二叉树, 这里以“字符”创建二叉树, 以'#'字符代表结束
void CreateBiTree(BiTree& BT) {
	BT = NULL;
	// p记录当前结点
    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));
	// t记录栈顶元素
	BiTNode* t;
    // 建立栈存储头结点
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // 处理左右子树的标记
    int k;
	ElemtType ch;
	printf("请输入广义表：");
	scanf("%c", &ch);
    while (ch != '#') {
        switch (ch) {
            // 对(做处理，代表当前结点作为父亲结点，并指向左孩子结点
        case '(':
            PushBiTNodeStack(S, p);
            k = 1;
            break;
            // 对)做处理，代表当前根结点子孙创建结束，退栈
        case ')':
            PopBiTNodeStack(S);
            break;
            // 对,做处理，代表处理右孩子结点
        case ',':
            k = 2;
            break;
        default:
            // 新增结点
            p = (BiTNode*)malloc(sizeof(BiTNode));
            p->lchild = NULL;
            p->rchild = NULL;
            p->data = ch;
            // 如果根节点为空
            if (BT == NULL) {
                BT = p;
            }
            // 链入*t的左孩子
            else if (k == 1) {
                t = GetTopBiTNodeStack(S);
                
                t->lchild = p;
            }
            // 链入*t的右孩子
            else
            {
                t = GetTopBiTNodeStack(S);
                t->rchild = p;
            }
        }
        scanf("%c", &ch);
    }
}
// 2.vist结点（打印）
void visit(BiTNode* T) {
    printf("%c->", T->data);
}
// 3.二叉树的先序遍历（递归）
void PreOrder(BiTree BT) {
    if (BT != NULL) {
         visit(BT);
         PreOrder(BT->lchild);
         PreOrder(BT->rchild);
    }
}
// 3.二叉树的先序遍历（非递归）
void PreOrder2(BiTree BT) {
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // 遍历结点p
    BiTNode* p = BT;
    // 如果p不为空或者栈不为空循环进行
    while (p || !EmptyBiTNodeStack(S)) {
        // 如果p不为空
        if (p) {
            // 访问入栈结点
            visit(p);
            // 当前结点入栈
            PushBiTNodeStack(S, p);
            // 一路向左
            p = p->lchild;
        }
        // 如果p为空
        else {
            // 栈顶元素出栈
            p = PopBiTNodeStack(S);
            // 访问右子树
            p = p->rchild;
        }
    }
}
// 4.二叉树的中序遍历（递归）
void InOrder(BiTree BT) {
    if (BT != NULL) {
        InOrder(BT->lchild);
        visit(BT);
        InOrder(BT->rchild);
    }
}
// 4.二叉树的中序遍历（非递归）
void InOrder2(BiTree BT) {
    BiTNodeStack S;
    InitBiTNodeStack(S);
    // 遍历结点p
    BiTNode* p = BT;
    // 如果p不为空或者栈不为空循环进行
    while (p || !EmptyBiTNodeStack(S)) {
        // 如果p不为空
        if (p) {
            // 当前结点入栈
            PushBiTNodeStack(S, p);
            // 一路向左
            p = p->lchild;
        }
        // 如果p为空
        else {
            // 栈顶元素出栈
            p = PopBiTNodeStack(S);
            // 访问出栈结点
            visit(p);
            // 访问右子树
            p = p->rchild;
        }
    }
}
// 5.二叉树的后序遍历（递归）
void PostOrder(BiTree BT) {
    if (BT != NULL) {
        PostOrder(BT->lchild);
        PostOrder(BT->rchild);
        visit(BT);
    }
}
// 5.二叉树的后序遍历（非递归）
void PostOrder2(BiTree BT) {

}
// 6.层次遍历
void LevelOrder(BiTree BT) {
    BiTNodeQueue Q;
    InitBiTNodeQueue(Q);
    // 遍历p结点
    BiTNode* p = BT;
    // 根结点入栈
    EnBiTNodeQueue(Q, BT);
    // 队列非空
    while (!EmptyBiTNodeQueue(Q)) {
        p = DeBiTNodeQueue(Q);
        visit(p);
        // 如果有左子树，进队
        if (p->lchild != NULL)
            EnBiTNodeQueue(Q, p->lchild);
        // 如果有右子树，进队
        if (p->rchild != NULL)
            EnBiTNodeQueue(Q, p->rchild);
    }
}

// 线索二叉树
// 1.使用广义表创建线索二叉树
void CreateThreadTree(ThreadTree& BT) {
    BT = NULL;
    // p记录当前结点
    ThreadNode* p = (ThreadNode*)malloc(sizeof(ThreadNode));
    // t记录栈顶元素
    ThreadNode* t;
    // 建立栈存储头结点
    ThreadNodeStack S;
    InitThreadNodeStack(S);
    // 处理左右子树的标记
    int k = 0;
    ElemtType ch;
    printf("请输入广义表建立线索二叉树：");
    scanf("%c", &ch);
    while (ch != '#') {
        switch (ch) {
            // 对(做处理，代表当前结点作为父亲结点，并指向左孩子结点
        case '(':
            PushThreadNodeStack(S, p);
            k = 1;
            break;
            // 对)做处理，代表当前根结点子孙创建结束，退栈
        case ')':
            PopThreadNodeStack(S);
            break;
            // 对,做处理，代表处理右孩子结点
        case ',':
            k = 2;
            break;
        default:
            // 新增结点
            p = (ThreadNode*)malloc(sizeof(ThreadNode));
            p->lchild = NULL;
            p->rchild = NULL;
            p->ltag = 0;
            p->rtag = 0;
            p->data = ch;
            // 如果根节点为空
            if (BT == NULL) {
                BT = p;
            }
            // 链入*t的左孩子
            else if (k == 1) {
                t = GetTopThreadNodeStack(S);
                t->lchild = p;
            }
            // 链入*t的右孩子
            else
            {
                t = GetTopThreadNodeStack(S);
                t->rchild = p;
            }
        }
        scanf("%c", &ch);
    }
}
// 2.vistThread结点（打印）
void visitThread(ThreadNode* T) {
    printf("%c->", T->data);
}

// 3.1.中序遍历构造主过程
void CreateInThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    // 非空二叉树，线索化
    if (T != NULL) {
        InThread(T, pre);
        // 处理最后一个结点
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}
// 3.2.中序遍历构造线索二叉树
void InThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        // 递归，线索化左子树
        InThread(p->lchild, pre);
        // 左子树为空，建立前驱线索
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            // 建立前驱结点的后继结点
            pre->rchild = p;
            pre->rtag = 1;
        }
        // 标记当前结点为刚刚访问过的结点
        pre = p;
        // 线索化右子树
        InThread(p->rchild, pre);
    }
}
// 3.3.求中序遍历下的第一个结点（找到最左下角的结点）
ThreadNode* FirstInNode(ThreadNode* p) {
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 3.4.求p结点在中序遍历下的后继结点
ThreadNode* NextInNode(ThreadNode* p) {
    if (p->rtag == 0)
        return FirstInNode(p->rchild);
    else
        return p->rchild;
}
// 3.5.求在中序遍历下的最后一个结点
ThreadNode* LastInNode(ThreadNode* p) {
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}
// 3.6.求p结点在中序遍历下的前驱结点
ThreadNode* PreInNode(ThreadNode* p) {
    if (p->ltag == 0)
        return LastInNode(p->lchild);
    else
        return p->lchild;
}
// 3.7.求不含头结点的中序线索二叉树的中序遍历算法
void InThreadOrder(ThreadTree T) {
    for (ThreadNode* p = FirstInNode(T); p != NULL; p = NextInNode(p))
        visitThread(p);
}
// 3.8.求不含头结点的中序线索二叉树的中序遍历算法（逆向）
void RevInThreadOrder(ThreadTree T) {
    for (ThreadNode* p = LastInNode(T); p != NULL; p = PreInNode(p))
        visitThread(p);
}

// 先序
// 4.1.先序遍历构造主过程
void CreatePreThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    // 非空二叉树，线索化
    if (T != NULL) {
        PreThread(T, pre);
        // 处理最后一个结点
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
// 4.2.先序遍历构造线索二叉树
void PreThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        // 左子树为空，建立前驱线索
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            // 建立前驱结点的后继结点
            pre->rchild = p;
            pre->rtag = 1;
        }
        // 标记当前结点为刚刚访问过的结点
        pre = p;
        // 线索化左子树
        if (p->ltag == 0)
            PreThread(p->lchild, pre);
        // 线索化右子树
        PreThread(p->rchild, pre);
    }
}
// 4.3.求先序遍历下的第一个结点
ThreadNode* FirstPreNode(ThreadNode* p) {
    return p;
}
// 4.4.求p结点在先序遍历下的后继结点
ThreadNode* NextPreNode(ThreadNode* p) {
    // 若没有孩子则指向后继
    if (p->rtag == 1)
        return p->rchild;
    // 否则左孩子不为空指向左孩子
    if (p->ltag == 0)
        return p->lchild;
    // 反之就是右孩子
    else 
        return p->rchild;
        
}
// 4.5.求在先序遍历下的最后一个结点（找到最右下角的结点）
ThreadNode* LastPreNode(ThreadNode* p) {
    if (p->rtag == 0)
        p = p->lchild;
    else if (p->ltag == 0)
        p = p->lchild;
    return p;
}
// 4.6.求p结点在先序遍历下的前驱结点
ThreadNode* PrePreNode(ThreadNode* p) {
    
}
// 4.7.求不含头结点的先序线索二叉树的先序遍历算法
void PreThreadOrder(ThreadTree T{

    }
// 4.8.求不含头结点的中序线索二叉树的中序遍历算法（逆向）
void RevPreThreadOrder(ThreadTree T) {

}

// 后序
// 5.1.后序遍历构造主过程
void CreatePostThread(ThreadTree T) {
    ThreadNode* pre = NULL;
    // 非空二叉树，线索化
    if (T != NULL) {
        PostThread(T, pre);
        // 处理最后一个结点
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}
// 5.2.先序遍历构造线索二叉树
void PostThread(ThreadTree& p, ThreadTree& pre) {
    if (p != NULL) {
        // 线索化左子树
        PostThread(p->lchild, pre);
        // 线索化右子树
        PostThread(p->rchild, pre);
        // 左子树为空，建立前驱线索
        if (p->lchild == NULL) {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            // 建立前驱结点的后继结点
            pre->rchild = p;
            pre->rtag = 1;
        }
        // 标记当前结点为刚刚访问过的结点
        pre = p;
    }
}
// 5.3.求先序遍历下的第一个结点
ThreadNode* FirstPostNode(ThreadNode* p) {

}
// 5.4.求p结点在后序遍历下的后继结点
ThreadNode* NextPostNode(ThreadNode* p) {

}
// 5.5.求在后序遍历下的最后一个结点
ThreadNode* LastPostNode(ThreadNode* p) {

}
// 5.6.求p结点在后序遍历下的前驱结点
ThreadNode* PrePostNode(ThreadNode* p) {

}
// 5.7.求不含头结点的后序线索二叉树的后序遍历算法
void PostThreadOrder(ThreadTree T) {

}
// 5.8.求不含头结点的中序线索二叉树的中序遍历算法（逆向）
void RevPostThreadOrder(ThreadTree T) {

}

// 二叉树的创建与遍历
void MainBiTree() {
	BiTree BT;
    // 如  A(B(D,E(G,)),C(,F))#
	CreateBiTree(BT);
    // 先序
    printf("3.先序遍历结果（递归）为：");
    PreOrder(BT);
    printf("\n3.先序遍历结果（非递归）为：");
    PreOrder2(BT);
    // 中序
    printf("\n4.中序遍历结果（递归）为：");
    InOrder(BT);
    printf("\n4.中序遍历结果（非递归）为：");
    InOrder2(BT);
    // 后序
    printf("\n5.后序遍历结果（递归）为：");
    PostOrder(BT);
    printf("\n5.后序遍历结果（非递归）为：");
    PostOrder2(BT);
    // 层次遍历
    printf("\n6.层次遍历结果为：");
    LevelOrder(BT);
}

void MainThreadTree() {
    // 线索二叉树
    ThreadTree TIn, TPre, TPost;
    ThreadNode* p;
    // 创建线索二叉树（赋值）
    // A(B(,D),C(E,))#
    CreateThreadTree(TIn);
    // 1中序创建
    CreateInThread(TIn);
    // 1.1
    p = FirstInNode(TIn);
    printf("1.1中序遍历下的第一个结点为：%c", p->data);
    // 1.2
    p = NextInNode(p);
    printf("\n1.2p结点在中序遍历下的后继结点为：%c", p->data);
    // 1.3
    p = LastInNode(TIn);
    printf("\n1.3中序遍历下的最后一个结点为：%c", p->data);
    // 1.4
    p = PreInNode(p);
    printf("\n1.4p结点在中序遍历下的前驱结点为：%c", p->data);
    // 1.5
    printf("\n1.5不含头结点的中序线索二叉树的中序遍历算法：");
    InThreadOrder(TIn);
    // 1.6
    printf("\n1.6不含头结点的中序线索二叉树的中序遍历算法(逆向)：");
    RevInThreadOrder(TIn);
}