// ��ʽ�洢�Ķ�����
#ifndef _BITREE_H_
#define _BITREE_H_
typedef char ElemtType;

// ������
typedef struct BiTNode {
	ElemtType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode, * BiTree;

// ʵ��
// 1.ʹ�ù������������, �����ԡ��ַ�������������, ��'#'�ַ��������
void CreateBiTree(BiTree& BT);
// 2.vist��㣨��ӡ��
void visit(BiTNode* T);
// 3.������������������ݹ飩
void PreOrder(BiTree BT);
// 4.������������������ݹ飩
void InOrder(BiTree BT);
// 4.������������������ǵݹ飩
void InOrder2(BiTree BT);
// 5.�������ĺ���������ݹ飩
void PostOrder(BiTree BT);
// 5.�������ĺ���������ǵݹ飩
void PostOrder2(BiTree BT);

// ����������
typedef struct ThreadNode {
	ElemtType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	// ����������־
	int ltag, rtag;
}ThreadNode, * ThreadTree;

// 1.ʹ�ù����������������
void CreateThreadTree(ThreadTree& BT);
// 2.vistThread��㣨��ӡ��
void visitThread(ThreadNode* T);
// 3.1.�����������������
void CreateInThread(ThreadTree T);
// 3.2.���������������������
void InThread(ThreadTree& p, ThreadTree& pre);
// 3.3.����������µĵ�һ�����
ThreadNode* FirstInNode(ThreadNode* p);
// 3.4.��p�������������µĺ�̽��
ThreadNode* NextInNode(ThreadNode* p);
// 3.5.������������µ����һ�����
ThreadNode* LastInNode(ThreadNode* p);
// 3.6.��p�������������µ�ǰ�����
ThreadNode* PreInNode(ThreadNode* p);
// 3.7.�󲻺�ͷ����������������������������㷨
void InThreadOrder(ThreadTree T);

// 4.1.�����������������
void CreatePreThread(ThreadTree T);
// 4.2.���������������������
void PreThread(ThreadTree& p, ThreadTree& pre);
// 4.3.����������µĵ�һ�����
ThreadNode* FirstPreNode(ThreadNode* p);
// 4.4.��p�������������µĺ�̽��
ThreadNode* NextPreNode(ThreadNode* p);
// 4.5.������������µ����һ�����
ThreadNode* LastPreNode(ThreadNode* p);
// 4.6.��p�������������µ�ǰ�����
ThreadNode* PrePreNode(ThreadNode* p);
// 4.7.�󲻺�ͷ����������������������������㷨
void PreThreadOrder(ThreadTree T);
// 4.8.�󲻺�ͷ����������������������������㷨������
void RevPreThreadOrder(ThreadTree T);

// 5.1.�����������������
void CreatePostThread(ThreadTree T);
// 5.2.���������������������
void PostThread(ThreadTree& p, ThreadTree& pre);
// 5.3.����������µĵ�һ�����
ThreadNode* FirstPostNode(ThreadNode* p);
// 5.4.��p����ں�������µĺ�̽��
ThreadNode* NextPostNode(ThreadNode* p);
// 5.5.���ں�������µ����һ�����
ThreadNode* LastPostNode(ThreadNode* p);
// 5.6.��p����ں�������µ�ǰ�����
ThreadNode* PrePostNode(ThreadNode* p);
// 5.7.�󲻺�ͷ���ĺ��������������ĺ�������㷨
void PostThreadOrder(ThreadTree T);
// 5.8.�󲻺�ͷ����������������������������㷨������
void RevPostThreadOrder(ThreadTree T);


void MainBiTree();
void MainThreadTree();
#endif // _BITREE_H_
