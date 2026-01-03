#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(int x) {
    Node *p = new Node;
    if (p == NULL) exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, int x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

int main() {
    int n; 
    cin >> n;
    List Input;
    CreateList(Input);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (value % 2 == 0)
            AddHead(Input, value);
    }
    for (Node* p = Input.head; p != NULL; p = p->next) {
        cout << p->data << " ";
    }
}