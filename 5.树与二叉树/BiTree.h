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

// 4.1.先序遍历构造主过程
void CreatePreThread(ThreadTree T);
// 4.2.先序遍历构造线索二叉树
void PreThread(ThreadTree& p, ThreadTree& pre);
// 4.3.求先序遍历下的第一个结点
ThreadNode* FirstPreNode(ThreadNode* p);
// 4.4.求p结点在先序遍历下的后继结点
ThreadNode* NextPreNode(ThreadNode* p);
// 4.5.求在先序遍历下的最后一个结点
ThreadNode* LastPreNode(ThreadNode* p);
// 4.6.求p结点在先序遍历下的前驱结点
ThreadNode* PrePreNode(ThreadNode* p);
// 4.7.求不含头结点的先序线索二叉树的先序遍历算法
void PreThreadOrder(ThreadTree T);
// 4.8.求不含头结点的中序线索二叉树的中序遍历算法（逆向）
void RevPreThreadOrder(ThreadTree T);

// 5.1.后序遍历构造主过程
void CreatePostThread(ThreadTree T);
// 5.2.先序遍历构造线索二叉树
void PostThread(ThreadTree& p, ThreadTree& pre);
// 5.3.求先序遍历下的第一个结点
ThreadNode* FirstPostNode(ThreadNode* p);
// 5.4.求p结点在后序遍历下的后继结点
ThreadNode* NextPostNode(ThreadNode* p);
// 5.5.求在后序遍历下的最后一个结点
ThreadNode* LastPostNode(ThreadNode* p);
// 5.6.求p结点在后序遍历下的前驱结点
ThreadNode* PrePostNode(ThreadNode* p);
// 5.7.求不含头结点的后序线索二叉树的后序遍历算法
void PostThreadOrder(ThreadTree T);
// 5.8.求不含头结点的中序线索二叉树的中序遍历算法（逆向）
void RevPostThreadOrder(ThreadTree T);


void MainBiTree();
void MainThreadTree();

// 题解
// 4.从下到上/从右到左的层次遍历
void InvertLevelOrder(BiTree BT);
void SolveBiTree_4();
// 5.非递归求二叉树高度
int BiTreeDepth(BiTree T);
// 5..递归求二叉树高度
int BiTreeDepth2(BiTree T);
void SolveBiTree_5();
// 6.通过先序和中序建立二叉树
BiTree PreInCreate(ElemtType A[], ElemtType B[], int l1, int h1, int l2, int h2);
void SolveBiTree_6();
// 7.检查是否为完全二叉树
bool IsComplete(BiTree T);
void SolveBiTree_7();
// 8.双分支结点个数
int DsonNodes(BiTree T);
void SolveBiTree_8();
// 9.双分支结点个数
void Swap(BiTree T);
void SolveBiTree_9();
// 10.先序遍历第k个的值
ElemtType PreNode(BiTree T, int k);
void SolveBiTree_10();
// 11.删除值以元素值x根的子树
void DeleteXTree(BiTree T);
void SeachXBiTree(BiTree T, ElemtType x);
void SolveBiTree_11();
// 12.求元素值为x的结点的祖先结点
void SeachXParent(BiTree T, ElemtType x);
void SolveBiTree_12();
#endif // _BITREE_H_
