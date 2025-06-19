#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int longestPath(Node* root) {
    if (!root) return 0;
    return 1 + max(longestPath(root->left), longestPath(root->right));
}

int findMin(Node* root) {

    while (root && root->left) root = root->left;
    return root ? root->data : -1;
}

void mirror(Node* root) {
    if (root) {
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
}

bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    return val < root->data ? search(root->left, val) : search(root->right, val);
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, val;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }
    
    int choice;
    do {
        cout << "\nMenu:\n1.Insert\n2.Longest Path\n3.Minimum Value\n4.Mirror Tree\n5.Search\n6.Display Tree\n7.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: "; cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Longest path length: " << longestPath(root) << endl;
                break;
            case 3:
                cout << "Minimum value: " << findMin(root) << endl;
                break;
            case 4:
                mirror(root);
                cout << "Tree mirrored.\n";
                break;
            case 5:
                cout << "Enter value to search: "; cin >> val;
                cout << (search(root, val) ? "Found\n" : "Not Found\n");
                break;
            case 6:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 7);
    
    return 0;
}
