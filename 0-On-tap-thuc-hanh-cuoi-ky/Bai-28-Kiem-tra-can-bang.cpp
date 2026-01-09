#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

void add(Node* &root, int x){
    /*
        Hàm thêm một số vào cây
        Hàm này đã được viết đầy đủ và đảm bảo đúng
        Sinh viên không cần phải viết hàm này
    */
    if (root == NULL){
        root = new Node;
        root->val = x;
        root->left = root->right= NULL;
    } else {
        if (x < root->val) add(root->left, x);
        else if (x > root->val) add(root->right, x);
    }
}


int solve(Node* root, int &count) {
    if (root == NULL) return 0;
    int hLeft = solve(root->left, count);
    int hRight = solve(root->right, count);
    int diff = hLeft - hRight;
    if (diff < 0) diff = -diff;
    if (diff >= 2) {
        count++;
    }
    if (hLeft > hRight) return 1 + hLeft;
    else return 1 + hRight;
}

int unbalance(Node* root) {
    int count = 0;
    solve(root, count);
    return count;
}



int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node *root = NULL;

    int x;
    while (cin >> x){
        add(root, x);
    }
    
    cout << "So node bi mat can bang la " << unbalance(root);
    return 0;
}
