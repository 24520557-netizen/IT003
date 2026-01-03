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

int main() {
	int n;
	cin >> n;
	List DanhSach;
	for (int i = 0; i < n; i++) {
		ToaDo Diem;
		cin >> Diem.x >> Diem.y >> Diem.z;
		AddTail(DanhSach, InitNode(Diem));
	}
	double b, c;
	cin >> b >> c;
	List Answer;
	for (Node* p = DanhSach.Head; p != NULL; p = p->Next) {
        double KhoangCach = sqrt(pow(p->Diem.x, 2) + pow(p->Diem.y, 2) + pow(p->Diem.z, 2));
        if (KhoangCach >= b && KhoangCach <= c) {
            AddTail(Answer, InitNode(p->Diem));
        }
	}
	if (Answer.Head == NULL) {
	    cout << "KHONG";
	} else {
	    for (Node* p = Answer.Head; p != NULL; p = p->Next) {
	        cout << p->Diem.x << " " << p->Diem.y << " " << p->Diem.z << endl;
	    }
	}
}