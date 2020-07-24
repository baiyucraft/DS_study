// 链式存储的二叉树
#ifndef _BITREE_H_
#define _BITREE_H_
typedef char ElemtType;

// 二叉树
typedef struct BiTNode {
	ElemtType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

// 实现
// 1.使用广义表创建二叉树, 这里以“字符”创建二叉树, 以'#'字符代表结束
void CreateBiTree(BiTree& BT);
// 2.vist结点（打印）
void visit(BiTNode* T);
// 3.二叉树的先序遍历（递归）
void PreOrder(BiTree BT);
// 4.二叉树的中序遍历（递归）
void InOrder(BiTree BT);
// 4.二叉树的中序遍历（非递归）
void InOrder2(BiTree BT);
// 5.二叉树的后序遍历（递归）
void PostOrder(BiTree BT);
// 5.二叉树的后序遍历（非递归）
void PostOrder2(BiTree BT);

// 线索二叉树
typedef struct ThreadNode {
	ElemtType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	// 左右线索标志
	int ltag, rtag;
}ThreadNode, * ThreadTree;

// 1.使用广义表创建线索二叉树
void CreateThreadTree(ThreadTree& BT);
// 2.vistThread结点（打印）
void visitThread(ThreadNode* T);
// 3.1.中序遍历构造主过程
void CreateInThread(ThreadTree T);
// 3.2.中序遍历构造线索二叉树
void InThread(ThreadTree& p, ThreadTree& pre);
// 3.3.求中序遍历下的第一个结点
ThreadNode* FirstInNode(ThreadNode* p);
// 3.4.求p结点在中序遍历下的后继结点
ThreadNode* NextInNode(ThreadNode* p);
// 3.5.求在中序遍历下的最后一个结点
ThreadNode* LastInNode(ThreadNode* p);
// 3.6.求p结点在中序遍历下的前驱结点
ThreadNode* PreInNode(ThreadNode* p);
// 3.7.求不含头结点的中序线索二叉树的中序遍历算法
void InThreadOrder(ThreadTree T);


void MainBiTree();
void MainThreadTree();
#endif // _BITREE_H_
