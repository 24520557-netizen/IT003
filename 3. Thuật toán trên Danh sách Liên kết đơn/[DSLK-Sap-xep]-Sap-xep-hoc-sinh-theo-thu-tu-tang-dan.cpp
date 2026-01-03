#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

int Compare(Hocsinh Hs1, Hocsinh Hs2) {
    if (Hs1.Ten == Hs2.Ten) {
        if (Hs1.Hodem == Hs2.Hodem) {
            if (Hs1.Nam == Hs2.Nam) {
                if (Hs1.Thang == Hs2.Thang) {
                    if (Hs1.Ngay == Hs2.Ngay) {
                        return 0;
                    } else if (Hs1.Ngay > Hs2.Ngay) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else if (Hs1.Thang > Hs2.Thang) {
                    return -1;
                } else {
                    return 1;
                }
            } else if (Hs1.Nam > Hs2.Nam) {
                return -1;
            } else {
                return 1;
            }
        } else if (Hs1.Hodem < Hs2.Hodem) {
            return -1;
        } else {
            return 1;
        }
    } else if (Hs1.Ten < Hs2.Ten) {
        return -1;
    } else {
        return 1;
    }
}

void Split(Node* head, Node* &left, Node* &right) {
    if (!head || !head->next) {
        left = head;
        right = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    left = head;
    right = slow->next;
    slow->next = NULL;
}

Node* Merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (Compare(a->data, b->data) <= 0) {
        a->next = Merge(a->next, b);
        return a;
    } else {
        b->next = Merge(a, b->next);
        return b;
    }
}

Node* MergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* left;
    Node* right;

    Split(head, left, right);

    left = MergeSort(left);
    right = MergeSort(right);

    return Merge(left, right);
}

void Sort(List& l) {
    l.head = MergeSort(l.head);
    l.tail = l.head;
    if (l.tail) {
        while (l.tail->next)
            l.tail = l.tail->next;
    }
}
