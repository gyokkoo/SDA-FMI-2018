#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

struct Node {
	double value;
	Node* left;
	Node* right;
	int height;

	Node(double value, Node* left, Node* right) {
		this->value = value;
		this->left = left;
		this->right = right;
		this->height = 0;
	}
};

class AVLTree
{
private:
	Node* root;
public:
	AVLTree() {
		root = nullptr;
	}

	int height(struct Node* N) {
		if (N == nullptr) {
			return 0;
		}

		return N->height;
	}

	void add(double value) {
		this->root = this->insert(this->root, value);
	}

	void remove(double value) {
		if (!this->contains(value)) {
			std::cout << value << " not found to remove\n";
			return;
		}

		this->root = this->deleteNode(this->root, value);
	}

	bool contains(double value) {
		if (root == nullptr) {
			return false;
		}

		return containsRecursive(root, value);
	}

	void print() {
		if (root == nullptr) {
			return;
		}

		printRecursive(root);
		std::cout << "\n";
	}

private:
	bool containsRecursive(Node *current, double value) {
		if (current == nullptr) {
			return false;
		}

		if (current->value == value) {
			return true;
		}

		if (value < current->value) {
			return containsRecursive(current->left, value);
		}
		else {
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current) {
		if (current == nullptr) {
			return;
		}

		printRecursive(current->left);
		std::cout << current->value << " ";
		printRecursive(current->right);
	}

	Node* rightRotate(struct Node* node) {
		Node* x = node->left;
		Node* T2 = x->right;

		x->right = node;
		node->left = T2;

		node->height = std::max(height(node->left), height(node->right)) + 1;
		x->height = std::max(height(x->left), height(x->right)) + 1;

		return x;
	}

	Node* leftRotate(struct Node *node) {
		Node *y = node->right;
		Node *T2 = y->left;

		y->left = node;
		node->right = T2;

		node->height = std::max(height(node->left), height(node->right)) + 1;
		y->height = std::max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalance(struct Node* node) {
		if (node == nullptr) {
			return 0;
		}

		return height(node->left) - height(node->right);
	}

	struct Node* insert(struct Node* node, double value)
	{
		if (node == nullptr) {
			return new Node(value, nullptr, nullptr);
		}

		if (value < node->value) {
			node->left = insert(node->left, value);
		}
		else if (value > node->value) {
			node->right = insert(node->right, value);
		}
		else {
			std::cout << value << " already added\n";
			return node;
		}

		node->height = 1 + std::max(height(node->left),
			height(node->right));

		int balance = getBalance(node);
		
		if (balance > 1 && value < node->left->value) {
			return rightRotate(node);
		}

		if (balance < -1 && value > node->right->value) {
			return leftRotate(node);
		}

		if (balance > 1 && value > node->left->value) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && value < node->right->value)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	Node* getMinNode(Node* node) {
		Node* current = node;
		while (current->left != nullptr) {
			current = current->left;
		}

		return current;
	}

	struct Node* deleteNode(struct Node* root, double value) {
		if (root == nullptr) {
			return root;
		}

		if (value < root->value) {
			root->left = deleteNode(root->left, value);
		} else if (value > root->value) {
			root->right = deleteNode(root->right, value);
		} else {
			if ((root->left == nullptr) || (root->right == nullptr)) {
				struct Node *temp = root->left ? root->left : root->right;

				if (temp == nullptr) {
					temp = root;
					root = nullptr;
				} else {
					*root = *temp;
				}

				delete temp;
			} else {
				struct Node* temp = getMinNode(root->right);

				root->value = temp->value;

				root->right = deleteNode(root->right, temp->value);
			}
		}

		if (root == nullptr) {
			return root;
		}

		root->height = 1 + std::max(height(root->left), height(root->right));
		
		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0) {
			return rightRotate(root);
		}

		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0) {
			return leftRotate(root);
		}

		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}
};

int main() {
	AVLTree tree;
	std::string operation;
	double number;
	size_t N;

	std::cin >> N;
	std::cout << std::fixed;

	for (size_t i = 0; i < N; i++) {
		std::cin >> operation;
		if (operation != "print") {
			std::cin >> number;
		}

		if (operation == "add") {
			tree.add(number);
		} else if (operation == "remove") {
			tree.remove(number);
		} else if (operation == "contains") {
			if (tree.contains(number)) {
				std::cout << "yes\n";
			} else {
				std::cout << "no\n";
			}
		} else if (operation == "print") {
			tree.print();
		}
	}

	return 0;
}