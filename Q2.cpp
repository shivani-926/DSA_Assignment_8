#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int k) {
        key = k;
        left = right = parent = NULL;
    }
};

class BST {
public:
    Node *root;

    BST() { root = NULL; }

    Node* insert(Node *x, int k) {
        if (x == NULL) {
            Node *n = new Node(k);
            if (root == NULL) root = n;
            return n;
        }
        if (k < x->key) {
            Node *l = insert(x->left, k);
            x->left = l;
            l->parent = x;
        } else {
            Node *r = insert(x->right, k);
            x->right = r;
            r->parent = x;
        }
        return x;
    }

    Node* RECURRSIVE_TREE_SEARCH(Node *x, int k) {
        if (x == NULL || k == x->key)
            return x;
        if (k < x->key)
            return TREE_SEARCH(x->left, k);
        else
            return TREE_SEARCH(x->right, k);
    }

    Node* ITERATIVE_TREE_SEARCH(Node *x, int k) {
        while (x != NULL && k != x->key) {
            if (k < x->key)
                x = x->left;
            else
                x = x->right;
        }
        return x;
    }

    Node* TREE_MINIMUM(Node *x) {
        while (x->left != NULL)
            x = x->left;
        return x;
    }

    Node* TREE_MAXIMUM(Node *x) {
        while (x->right != NULL)
            x = x->right;
        return x;
    }

    Node* TREE_SUCCESSOR(Node *x) {
        if (x->right != NULL)
            return TREE_MINIMUM(x->right);
        Node *y = x->parent;
        while (y != NULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }

    Node* TREE_PREDECESSOR(Node *x) {
        if (x->left != NULL)
            return TREE_MAXIMUM(x->left);
        Node *y = x->parent;
        while (y != NULL && x == y->left) {
            x = y;
            y = y->parent;
        }
        return y;
    }
};

int main() {
    BST t;

    int arr[] = {60, 41, 74, 16, 53, 65, 25, 46, 55, 63, 70, 42, 62, 64};
    for (int i = 0; i < 14; i++)
        t.insert(t.root, arr[i]);

    Node *a = t.RECURRSIVE_TREE_SEARCH(t.root, 46);
    Node *b = t.ITERATIVE_TREE_SEARCH(t.root, 46);
    Node *mn = t.TREE_MINIMUM(t.root);
    Node *mx = t.TREE_MAXIMUM(t.root);
    Node *s = t.TREE_SUCCESSOR(a);
    Node *p = t.TREE_PREDECESSOR(a);

    cout << a->key << endl;
    cout << b->key << endl;
    cout << mn->key << endl;
    cout << mx->key << endl;
    cout << (s ? s->key : -1) << endl;
    cout << (p ? p->key : -1) << endl;

    return 0;
}
