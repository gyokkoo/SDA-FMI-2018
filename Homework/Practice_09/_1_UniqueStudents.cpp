#include <iostream>

class Node {
public:
    long long data;
    Node* leftNode;
    Node* rightNode;

    Node(long long d) {
        data = d;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* insert(Node* root, long long data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->leftNode = insert(root->leftNode, data);
        } else {
            root->rightNode = insert(root->rightNode, data);
        }

        return root;
    }

    bool contains(Node* root, long long data) {
        if (root == nullptr) {
            return false;
        }

        if (root->data == data) {
            return true;
        }

        if (root->data < data) {
            return contains(root->rightNode, data);
        } else {
            return contains(root->leftNode, data);
        }
    }
};

int main() {
    int countOfNumbers = 0;
    std::cin >> countOfNumbers;

    BinarySearchTree myTree;
    Node* root = nullptr;

    int uniqueNumbersCount = 0;
    for (int i = 0; i < countOfNumbers; i++) {
        long long currentNumber = 0;
        std::cin >> currentNumber;

        if (!myTree.contains(root, currentNumber)) {
            root = myTree.insert(root, currentNumber);
            uniqueNumbersCount++;
        }
    }

    std::cout << uniqueNumbersCount;

    return 0;
}
