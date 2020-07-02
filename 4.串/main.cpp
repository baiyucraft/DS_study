#include <iostream>

using namespace std;
typedef struct Node {/*链表bai类型定义,单链表*/
    int data;
    struct Node* next;
}LinkList;
int dc(LinkList L, int n) {
    //L是带头结点的n个元素的单链表，本算法判断单链表是否中心对称？
    int i;
    char s[n / 2];
    p = L->next;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->data;
        p = p->next;
    }
    i--;
    if (n % 2 == 1)
        p = p->next;
    while (p != null && s[i] == p->data) {
        i--;
        p = p->next;
    }
    if (i == -1)
        return 1;
    else
        return 0;
}
int main()
{
    int i = 0;
    LinkList A = { y,y,a,y,y };
    i = dc(A, 5);
    print('i=', i);
    return 0;
}