
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
bool isBrother(Tree, int, int);

void run(int q, Tree T){

    int x, y;
    while(q--) {
        cin >> x >> y;
        if (isBrother(T, x, y)) {
            cout << x << " va " << y << " la anh em" << endl;
        } else {
            cout << x << " va " << y << " khong phai la anh em" << endl;
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

bool checkSibling(TNode* root, int x, int y) {
    if (root == NULL) return false;
    if (x < root->key && y < root->key)
        return checkSibling(root->pLeft, x, y);
    if (x > root->key && y > root->key)
        return checkSibling(root->pRight, x, y);
    if (root->pLeft != NULL && root->pRight != NULL) {
        int leftVal = root->pLeft->key;
        int rightVal = root->pRight->key;

        if ((leftVal == x && rightVal == y) || (leftVal == y && rightVal == x)) {
            return true;
        }
    }

    return false;
}

bool isBrother(Tree T, int x, int y) {
    return checkSibling(T.root, x, y);
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
