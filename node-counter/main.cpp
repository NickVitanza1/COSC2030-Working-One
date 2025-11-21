//
// Nicholas Vitanza
// 11/21/25
// Node Counter Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

// ===============================
//       TEMPLATE BINARY TREE
// ===============================
template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper for recursive insert
    Node* insert(Node* node, const T& value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Helper for counting nodes
    int countNodes(Node* node) const {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Helper for inorder display
    void inorder(Node* node) const {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert value into the tree
    void insert(const T& value) {
        root = insert(root, value);
    }

    // Count number of nodes in the tree
    int countNodes() const {
        return countNodes(root);
    }

    // Display tree inorder
    void displayInorder() const {
        inorder(root);
        cout << endl;
    }
};

// ===============================
//        DRIVER PROGRAM
// ===============================
int main() {
    BinaryTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal of Tree: ";
    tree.displayInorder();

    cout << "Number of nodes in tree: " 
         << tree.countNodes() << endl;

    // Demonstrate with another data type
    BinaryTree<string> tree2;
    tree2.insert("pear");
    tree2.insert("apple");
    tree2.insert("orange");

    cout << "\nString Tree (Inorder): ";
    tree2.displayInorder();

    cout << "Number of nodes in string tree: "
         << tree2.countNodes() << endl;

    return 0;
}