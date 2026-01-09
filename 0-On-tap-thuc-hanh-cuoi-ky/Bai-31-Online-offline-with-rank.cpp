#include <iostream>
using namespace std;

struct Node {
    int data;
    int size;
    Node *left, *right;

    Node(int val) {
        data = val;
        size = 1;
        left = right = NULL;
    }
};

int getSize(Node* root) {
    return root ? root->size : 0;
}

void updateSize(Node* root) {
    if (root) {
        root->size = 1 + getSize(root->left) + getSize(root->right);
    }
}

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val == root->data) return root;

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    updateSize(root);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* remove(Node* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = remove(root->left, val);
    } else if (val > root->data) {
        root->right = remove(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    updateSize(root);
    return root;
}

bool search(Node* root, int val) {
    if (root == NULL) return false;
    if (root->data == val) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

int countSmaller(Node* root, int val) {
    if (root == NULL) return 0;

    if (val < root->data) {
        return countSmaller(root->left, val);
    } else if (val > root->data) {
        return getSize(root->left) + 1 + countSmaller(root->right, val);
    } else {
        return getSize(root->left);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = NULL;
    int type, id;

    while (cin >> type) {
        if (type == 0) break; 
        
        cin >> id;

        if (type == 1) {
            root = insert(root, id);
        } else if (type == 2) {
            if (search(root, id)) {
                cout << countSmaller(root, id) + 1 << "\n";
            } else {
                cout << "0\n";
            }
        } else if (type == 3) {
            root = remove(root, id);
        }
    }

    return 0;
}