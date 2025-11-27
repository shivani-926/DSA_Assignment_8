#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *temp) {
    if (temp != NULL) {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(Node *temp) {
    if (temp != NULL) {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void postorder(Node *temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

int main() {
    Node *root = new Node(41);
    root->left = new Node(16);
    root->left->right = new Node(25);

    root->right = new Node(53);
    root->right->left = new Node(46);
    root->right->left->left = new Node(42);
    root->right->right = new Node(55);

    cout << "Pre-order Traversal: \n ";
    preorder(root);

    cout << "In-order Traversal: \n ";
    inorder(root);

    cout << "Post-order Traversal: \n ";
    postorder(root);

    cout << endl;
    return 0;
}
