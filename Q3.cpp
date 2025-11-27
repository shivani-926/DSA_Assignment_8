#include <iostream>
#include <algorithm>
using namespace std;

class BST {
public:
    int data;
    BST *left, *right;

    BST(int value) {
        data = value;
        left = right = nullptr;
    }
};

BST* insertnode(BST* root, int value) {
    if (!root) return new BST(value);

    if (value < root->data)
        root->left = insertnode(root->left, value);
    else if (value > root->data)
        root->right = insertnode(root->right, value);
    else
        cout << "Duplicate value ignored: " << value << endl;

    return root;
}

BST* findmin(BST* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

BST* deletenode(BST* root, int value) {
    if (!root) {
        cout << "Value not found.\n";
        return root;
    }

    if (value < root->data)
        root->left = deletenode(root->left, value);
    else if (value > root->data)
        root->right = deletenode(root->right, value);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if (!root->left) {
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        BST* temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int maxdepth(BST* root) {
    if (!root) return 0;
    return 1 + max(maxdepth(root->left), maxdepth(root->right));
}

int mindepth(BST* root) {
    if (!root) return 0;
    if (!root->left) return 1 + mindepth(root->right);
    if (!root->right) return 1 + mindepth(root->left);
    return 1 + min(mindepth(root->left), mindepth(root->right));
}

int main() {
    BST* root = nullptr;
    int choice, value;

    while (true) {
        cout << "1. Insert\n 2. Delete\n 3. Maximum Depth\n 4. Minimum Depth\n 5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertnode(root, value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deletenode(root, value);
            break;

        case 3:
            cout << "Maximum Depth: " << maxdepth(root) << endl;
            break;

        case 4:
            cout << "Minimum Depth: " << mindepth(root) << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
