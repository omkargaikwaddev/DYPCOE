#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

class Stack {
    Node* arr[30];
    int top = -1;

public:
    void push(Node* p) 
    { 
        arr[++top] = p; 
    }
    Node* pop() 
    { 
        return top == -1 ? nullptr : arr[top--];
     }
    bool empty() 
    { 
        return top == -1; 
    }

};

class Tree {
    char expr[20];

public:
    Node* root = nullptr;

    void setExpr(char e[]) 
    { 
        strcpy(expr, e); 
    }

    void build() {
        Stack s;
        for (int i = strlen(expr) - 1; i >= 0; --i) {
            Node* n = new Node(expr[i]);
            if (isalpha(expr[i])) 
              s.push(n);
            else {
                n->left = s.pop();
                n->right = s.pop();
                s.push(n);
            }
        }
        root = s.pop();
    }

    void preorder(Node* n) {
        if (!n) return;
        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }

    void inorder(Node* n) {
        if (!n) return;
        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }

    void postorderNonRec(Node* n) {
        if (!n) return;
        Stack s1, s2;
        s1.push(n);
        while (!s1.empty()) {
            Node* t = s1.pop();
            s2.push(t);
            if (t->left) s1.push(t->left);
            if (t->right) s1.push(t->right);
        }
        cout << "Postorder Traversal: ";
        while (!s2.empty()) {
            cout << s2.pop()->data << " ";
        }
        cout << endl;
    }

    void deleteTree(Node*& n) {
        if (!n) return;
        deleteTree(n->left);
        deleteTree(n->right);
        cout << "Deleting node: " << n->data << endl;
        delete n;
        n = nullptr;
    }
};

int main() {
    Tree t;
    int choice;
    char input[20];

    do {
        cout << "\nMenu:\n1. Enter Prefix\n2. Build Tree\n3. Pre/Inorder\n4. Postorder\n5. Delete Tree\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter prefix: "; 
                cin >> input; 
                t.setExpr(input); 
                break;

            case 2:
                t.build(); 
                cout << "Tree built.\n"; 
                break;

            case 3:
                if (t.root) {
                    cout << "Preorder: "; 
                    t.preorder(t.root);
                    cout << "\nInorder: "; 
                    t.inorder(t.root); 
                    cout << endl;
                }else 
                    cout << "Tree empty!\n";
                    break;

            case 4: 
                t.postorderNonRec(t.root); 
                break;

            case 5: 
                t.deleteTree(t.root);
                if (!t.root) 
                cout << "Tree deleted.\n"; 
                break;
                
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

