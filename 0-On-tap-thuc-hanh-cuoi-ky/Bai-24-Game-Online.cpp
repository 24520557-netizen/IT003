#include <iostream>

using namespace std;

struct Node {
    int id;
    Node *left;
    Node *right;

    Node(int val) {
        id = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    
    if (val < root->id) {
        root->left = insertNode(root->left, val);
    } else if (val > root->id) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

bool searchNode(Node* root, int val) {
    if (root == NULL) return false;
    if (root->id == val) return true;
    
    if (val < root->id) return searchNode(root->left, val);
    return searchNode(root->right, val);
}

Node* findMinNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;

    if (val < root->id) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->id) {
        root->right = deleteNode(root->right, val);
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

        Node* temp = findMinNode(root->right);
        root->id = temp->id;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
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
            root = insertNode(root, id);
        } else if (type == 2) {
            if (searchNode(root, id)) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (type == 3) {
            root = deleteNode(root, id);
        }
    }

    return 0;
}