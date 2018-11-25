#include <iostream>
#include <queue>

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) {
            data = d;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
public:
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    void preOrder(Node *root) {
        if (root == nullptr) {
            return;
        }

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root) {
        if (root == nullptr) {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);

        std::cout << root->data << " ";
    }

    void levelOrder(Node *root) {
        if (root == nullptr) {
            return;
        }

        std::queue<Node *> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node *current = queue.front();
            std::cout << current->data << " ";
            queue.pop();

            if (current->left != nullptr) {
                queue.push(current->left);
            }
            if (current->right != nullptr) {
                queue.push(current->right);
            }
        }
    }
};

int main() {

    BinarySearchTree myTree;
    Node* root = nullptr;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);
    return 0;
}