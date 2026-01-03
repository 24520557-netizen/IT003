#include <iostream>
#include <cmath>

using namespace std;

struct ToaDo {
	double x, y, z;
};

struct Node {
	ToaDo Diem;
	Node* Next;
};

struct List {
	Node* Head = NULL;
	Node* Tail = NULL;
};

Node* InitNode(ToaDo Value) {
	Node* p = new Node;
	p->Diem = Value;
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

void run() {
    List Input;
    List Output;
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        ToaDo Diem;
        cin >> Diem.x >> Diem.y >> Diem.z;
        AddTail(Input, InitNode(Diem));
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ToaDo Diem;
        cin >> Diem.x >> Diem.y >> Diem.z;
        AddTail(Output, InitNode(Diem));
    }
    for (Node* p = Output.Head; p != NULL; p = p->Next) {
        int Index = 0;
        for (Node* q = Input.Head; q != NULL; q = q->Next) {
            if (p->Diem.x == q->Diem.x && p->Diem.y == q->Diem.y && p->Diem.z == q->Diem.z) {
                cout << Index << endl;
                break;
            }
            Index++;
        }
        if (Index >= n) {
            cout << "KHONG\n";
        }
    }
}

int main() {

	int * a = new int[256];
	int * b = new int[256];
	delete [] a;
	run();
	delete [] b;
}