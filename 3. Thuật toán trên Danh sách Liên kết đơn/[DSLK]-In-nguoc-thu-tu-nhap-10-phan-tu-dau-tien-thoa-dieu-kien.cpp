#include <iostream>

using namespace std;

struct Node {
    int num;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->num = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node *p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node * p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node *p = l.head;
    while (p != NULL) {
        cout << p->num << ' ';
        p = p->next;
    }
}

int main()
{
    List a;
    CreateList(a);
    List b;
    CreateList(b);
    int m, k;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }
    int count = 0;
    for (Node* p = a.head; p != NULL; p = p->next) {
        if (p->num >= 90) {
            AddHead(b, p->num);
            count++;
        }
        if (count >= 10) {
            break;
        }
    }
    for (Node* p = b.head; p != NULL; p = p->next) {
        cout << p->num << " ";
    }
    cout << "END";
    return 0;
}