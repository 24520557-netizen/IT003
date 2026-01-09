
#include <iostream>
using namespace std;

struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isFather(Tree, int, int);

void run(int q, Tree T){
int u, v;
    while (q--) {
        cin >> u >> v;
        if (isFather(T, u, v)) {
            cout << u << " la cha cua " << v << endl;
        } 
        else if (isFather(T, v, u)) {
            cout << v << " la cha cua " << u << endl;
        } 
        else {
            cout << u << " va " << v << " khong co quan he cha con" << endl;
        }
    }
}
void insertNode(TNode* &root, int x) {
    if (root == NULL) {
        root = CreateTNode(x);
        return;
    }
    if (x < root->key)
        insertNode(root->pLeft, x);
    else if (x > root->key)
        insertNode(root->pRight, x);
}

void Insert(Tree &T, int x) {
    insertNode(T.root, x);
}

TNode* search(TNode* root, int x) {
    if (root == NULL || root->key == x) return root;
    if (x < root->key) return search(root->pLeft, x);
    return search(root->pRight, x);
}

bool isFather(Tree T, int u, int v) {
    TNode* parent = search(T.root, u);
    if (parent == NULL) return false;
    if (parent->pLeft != NULL && parent->pLeft->key == v) return true;
    if (parent->pRight != NULL && parent->pRight->key == v) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);
    
    return 0;
}
