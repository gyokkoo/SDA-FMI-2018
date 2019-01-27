/*
Напишете следните функции за двоично наредено дърво:

void аdd(int X) - добавя елемент в двоично наредено дърво(ако елемента вече съществува в дървото то дървото не се променя).
Не принтира нищо на стандартният изход.

void print() - извежда на стандартният изход дървото в последователност корен-ляво-дясно разделена с интервали

Input Format

N - брой операции които ще бъдат подадени

Следват N операции всяка от която на нов ред
(операцията се дава с името си и ако има входен параметър например: add число, print)

Constraints
1 < N < 200 000

Output Format
На стандартният изход се очаква да се принтира поредица от числа спрямо изхода от изпълнените операции.
(Всичко се принтира на един ред, като всички числа са разделени с интервали)

Sample Input 0
5
add 2
add 5
add 5
add 1
print

Sample Output 0
2 1 5

 */

#include <iostream>

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

Node* add(Node *root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = add(root->left, data);;
    } else if (data > root->data) {
        root->right = add(root->right, data);;
    }

    return root;
}

void print(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";

    print(root->left);
    print(root->right);
}

int main () {
    int N = 0;
    std::cin >> N;

    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        std::string command;
        std::cin >> command;

        if (command == "add") {
            int value = 0;
            std::cin >> value;
            root = add(root,value);
        }

        if (command == "print") {
            print(root);
        }
    }

    return 0;
}