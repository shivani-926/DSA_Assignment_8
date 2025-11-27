#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

bool isBST(Node* root, int minV, int maxV) {
    if (!root) return true;
    if (root->data <= minV || root->data >= maxV) return false;
    return isBST(root->left, minV, root->data) &&
           isBST(root->right, root->data, maxV);
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    if (isBST(root, -1000000, 1000000))
        cout << "It is a BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}
