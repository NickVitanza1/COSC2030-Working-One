//
// Nicholas Vitanza
// 11/21/25
// Queue Converter Programming Project
// COSC 2030
//

#include <iostream>
#include <queue>
using namespace std;

// ======================================
//           TEMPLATE BINARY TREE
// ======================================
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

    // Recursive insert for BST
    Node* insert(Node* node, const T& value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Recursive inorder traversal to queue values
    void inorder(Node* node, queue<T>& q) const {
        if (node == nullptr)
            return;

        inorder(node->left, q);
        q.push(node->data);
        inorder(node->right, q);
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const T& value) {
        root = insert(root, value);
    }

    // Fill queue with values in ascending order
    void toQueueInorder(queue<T>& q) const {
        inorder(root, q);
    }
};

// ======================================
//             DRIVER PROGRAM
// ======================================
int main() {
    BinaryTree<int> tree;
    queue<int> q;

    // Insert numbers into the tree
    int numbers[] = {50, 20, 70, 10, 30, 60, 80};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < size; i++)
        tree.insert(numbers[i]);

    // Put values in queue using inorder traversal
    tree.toQueueInorder(q);

    // Dequeue and display values (should be ascending)
    cout << "Numbers in ascending order: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}