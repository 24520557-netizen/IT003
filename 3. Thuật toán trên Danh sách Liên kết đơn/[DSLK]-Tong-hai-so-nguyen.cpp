#include <iostream>
#include <stack>

#include <fstream>
#include <cstdlib>
#include <ctime>

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
void Sum(List, List, List &);

int main()
{
    List a, b, c;
    CreateList(a);
    CreateList(b);
    CreateList(c);
    int m, n, k;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        AddTail(a, k);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        AddTail(b, k);
    }

    Sum(a, b, c);
    PrintList(c);
    return 0;
}

void Sum(List a, List b, List &c) {
    stack<int> first;
    stack<int> second;
    for (Node* p = a.head; p != NULL; p = p->next) {
        first.push(p->num);
    }
    for (Node* p = b.head; p != NULL; p = p->next) {
        second.push(p->num);
    }
    int carry = 0;
    while (!first.empty() && !second.empty()) {
        int ans = first.top() + second.top() + carry;
        if (ans > 9) {
            AddHead(c, ans % 10);
            carry = 1;
        } else {
            AddHead(c, ans);
            carry = 0;
        }
        first.pop();
        second.pop();
    }
    while (!first.empty()) {
        int ans = first.top() + carry;
        if (ans > 9) {
            AddHead(c, ans % 10);
            carry = 1;
        } else {
            AddHead(c, ans);
            carry = 0;
        }
        first.pop();
    }
    while (!second.empty()) {
        int ans = second.top() + carry;
        if (ans > 9) {
            AddHead(c, ans % 10);
            carry = 1;
        } else {
            AddHead(c, ans);
            carry = 0;
        }
        second.pop();
    }
}