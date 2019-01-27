/*
Използвайте вече написаните функции add и print и добавете следните нови функции:

void remove(int X)- ако в дървото имаме елемент X го изтрива
(запазвайки структурата наредено двоично дърво,
hint: ако възела няма наследник просто се премахва, ако има само един наследник то той отива на негово място, а ако има два наследника тогава се търси най-малкият по-голям от него).
Не принтира нищо на стандартният изход.

void print_odd_layers() - принтира елементите на дървото от нечетните му нива започвайки
от корена и продължавайки с 3 ниво, 5 ниво и т.н. (елементите от четните нива се прескачат)

Input Format
N - брой на операциите Следват имената на операциите като аргументите са разделени с интервал

Constraints
1 < N < 200,000

Output Format
Изход спрямо изпълнените операции

Sample Input 0
5
add 2
add 2
add 1
remove 2
print

Sample Output 0
1

Sample Input 1
8
add 1
add 2
add 4
add 6
add 7
add 5
print_odd_layers
print

Sample Output 1

1 4 5 7 1 2 4 6 5 7
 */

#include <iostream>
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

int getLevel(Node* node, int data, int level) {
    if (node == nullptr) {
        return 0;
    }

    if (node->data == data) {
        return level;
    }

    int nextLevel = getLevel(node->left, data, level + 1);
    if (nextLevel != 0) {
        return nextLevel;
    }

    nextLevel = getLevel(node->right, data, level + 1);
    return nextLevel;
}

Node* getMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* remove(Node* root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->left = remove(root->left, data);
    } else if (data > root->data) {
        root->right = remove(root->right, data);
    } else {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }

        Node* minimum = getMin(root->right);
        root->data = minimum->data;

        root->right = remove(root->right, minimum->data);
    }

    return root;
}

void print_odd_layers(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::queue <Node*> queue;
    queue.push(root);
    while(!queue.empty()) {
        Node* current = queue.front();
        int level = getLevel(root, current->data, 1);
        if (level % 2 != 0) {
            std::cout << current->data << " ";
        }
        queue.pop();
        if (current->left != nullptr) {
            queue.push(current->left);
        }
        if (current->right != nullptr) {
            queue.push(current->right);
        }
    }
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
        } else if (command == "remove") {
            int value = 0;
            std::cin >> value;
            root = remove(root, value);
        } else if (command == "print_odd_layers") {
            print_odd_layers(root);
        } else if (command == "print") {
            print(root);
        }
    }

    return 0;
}