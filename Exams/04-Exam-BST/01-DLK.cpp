#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

std::vector<int> result;

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }

void print(Node *root) {
    if (root == nullptr) {
        return;
    }
    
    result.push_back(root->data);
    print(root->leftNode);
    print(root->rightNode);
}

    void printVector() {
        for (int i = result.size() - 1; i >= 1; i--) {
            std::cout << result[i] << ";";
        }
        std::cout << result[0];
    }
    
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.print(root);
    myTree.printVector();
    return 0;
}
