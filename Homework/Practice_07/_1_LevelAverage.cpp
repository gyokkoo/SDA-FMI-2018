/*
На входа се подават елементи на двуично наредено дърво в реда на тяхното добавяне.
За това дърво трябва да изведете средно аритметичната стойност на елементите от всяко ниво.

Забележка: При добавяне на елементи, ако даден елемент вече съществува в дървото, новото срещане да се добави в дясното поддърво.

Input Format
На първия ред се подава число - брой възли в дървото
На втория ред се подават елементите на дървото в реда на тяхното добавяне.

Constraints
1 ≤ N ≤ 500000
|ai| ≤ 2^16 (0 ≤ i < N)

Output Format

На всеки нов ред изведете средно аритметичната стойност на дадено ниво, започвайки от корена.
Форматирането е точно 2 цифри след десетичната точка.

Sample Input 0

6
5 1 6 0 4 7
Sample Output 0

5.00
3.50
3.67
Explanation 0

        5
       / \
      1   6
     / \   \
    0   4   7
5 / 1 = 5.00

(1 + 6) / 2 = 3.50

(0 + 4 + 7) / 3 = 3.67
 */

#include <iostream>
#include <iomanip>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }
        Node* current;
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data >= root->data) {
            root->right = insert(root->right, data);
        }

        return root;
    }

    void calculateLevelSums(Node* root, long long* levelSum, int* levelCount)
    {
        if (root == nullptr) {
            return;
        }

        // Tree node with level
        std::queue<std::pair<Node*, int>> queue;

        queue.push({root, 1});

        std::pair<struct Node*, int> pair;

        while (!queue.empty()) {
            pair = queue.front();
            queue.pop();

            Node* current = pair.first;
            int level = pair.second;

            levelSum[level] += current->data;
            levelCount[level]++;

            if (current->left != nullptr) {
                queue.push({current->left, level + 1});
            }

            if (current->right != nullptr) {
                queue.push({current->right, level + 1});
            }
        }
    }
};

int main() {
    BinaryTree tree;
    Node* root = nullptr;

    int count = 0;
    int data = 0;

    long long levelSum[500000] = {0};
    int levelCount[500000] = {0};

    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::cin >> data;
        root = tree.insert(root, data);
    }

    tree.calculateLevelSums(root, levelSum, levelCount);

    std::cout << std::fixed
              << std::setprecision(2);
    for (int i = 0; i < 500000; i++) {
        if (levelSum[i] != 0) {
             std::cout <<  levelSum[i] / (double)levelCount[i] << "\n";
        }
    }

    return 0;
}

