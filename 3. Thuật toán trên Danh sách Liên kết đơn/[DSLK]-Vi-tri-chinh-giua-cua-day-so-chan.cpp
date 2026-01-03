#include <iostream>

using namespace std;

struct Node {
	int Data;
	Node* Next;
};

struct List {
	Node* Head = NULL;
	Node* Tail = NULL;
};

Node* InitNode(int Value) {
	Node* p = new Node;
	p->Data = Value;
	p->Next = NULL;
	return p;
}

void AddHead(List& DanhSach, Node* Nut) {
	if (DanhSach.Head == NULL) {
		DanhSach.Head = Nut;
		DanhSach.Tail = Nut;
	} else {
		Nut->Next = DanhSach.Head;
		DanhSach.Head = Nut;
	}
}

void AddTail(List& DanhSach, Node* Nut) {
	if (DanhSach.Tail == NULL) {
		DanhSach.Tail = Nut;
		DanhSach.Head = Nut;
	} else {
		DanhSach.Tail->Next = Nut;
		DanhSach.Tail = Nut;
	}
}

void Run() {
    List Input;
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int Value;
        cin >> Value;
        if (Value % 2 == 0)
            AddTail(Input, InitNode(Value));
    }
    Node* Slow = Input.Head;
    Node* Fast = Input.Head;
    while (Fast->Next && Fast->Next->Next) {
        Fast = Fast->Next->Next;
        Slow = Slow->Next;
    }
    cout << Slow->Data;
}

int main() {
	Run();
}