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

// ���
// 4.���µ���/���ҵ���Ĳ�α���
void InvertLevelOrder(BiTree BT);
void SolveBiTree_4();
// 5.�ǵݹ���������߶�
int BiTreeDepth(BiTree T);
// 5..�ݹ���������߶�
int BiTreeDepth2(BiTree T);
void SolveBiTree_5();
// 6.ͨ�������������������
BiTree PreInCreate(ElemtType A[], ElemtType B[], int l1, int h1, int l2, int h2);
void SolveBiTree_6();
// 7.����Ƿ�Ϊ��ȫ������
bool IsComplete(BiTree T);
void SolveBiTree_7();
// 8.˫��֧������
int DsonNodes(BiTree T);
void SolveBiTree_8();
// 9.˫��֧������
void Swap(BiTree T);
void SolveBiTree_9();
// 10.���������k����ֵ
ElemtType PreNode(BiTree T, int k);
void SolveBiTree_10();
// 11.ɾ��ֵ��Ԫ��ֵx��������
void DeleteXTree(BiTree T);
void SeachXBiTree(BiTree T, ElemtType x);
void SolveBiTree_11();
// 12.��Ԫ��ֵΪx�Ľ������Ƚ��
void SeachXParent(BiTree T, ElemtType x);
void SolveBiTree_12();
#endif // _BITREE_H_
