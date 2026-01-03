#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	string Text;
	string Explanation;
};

void loadData(Word dictionary[], int &n) {
	string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin>>ws, s);
        dictionary[i].Text = s;
        getline(cin>>ws, s);
        dictionary[i].Explanation = s;
    }
}

void saveData(Word dictionary[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dictionary[i].Text << endl << dictionary[i].Explanation << endl;
    }
}

void Sort(Word [], int );

int main() {
    Word *dictionary = new Word[15000];
	int n;
	loadData(dictionary, n);
	Sort(dictionary, n);

	saveData(dictionary, n);
	delete [] dictionary;
	return 0;
}

void Heapify(Word Ds[], int size, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < size && Ds[l].Text > Ds[largest].Text) {
        largest = l;
    } 
    if (r < size && Ds[r].Text > Ds[largest].Text) {
        largest = r;
    }
    if (largest != i) {
        Word temp = Ds[i];
        Ds[i] = Ds[largest];
        Ds[largest] = temp;
        Heapify(Ds, size, largest);
    }
}

void Sort(Word Ds[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        Heapify(Ds, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        Word temp = Ds[i];
        Ds[i] = Ds[0];
        Ds[0] = temp;
        Heapify(Ds, i, 0);
    }
}