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


    bool isLeftNode(Node* root) {
        if (root->leftNode != nullptr) {
            return true;
        }
        
        return false;
    }
    
    bool isRightNode(Node*root) {
        if (root->rightNode != nullptr) {
            return true;
        }
        
        return false;
    }
    
    
    int leftCount = 0;
    int rightCount = 0;
    
    
	void leftRight(Node *root) {
        if (root == nullptr) {
            std::cout << "[" << 0 << "," << 0 << "]";
            return;
        }
        
        std::queue<Node*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();
            
            if (isLeftNode(current)) {
                leftCount++;
            }
            if (isRightNode(current)) {
                rightCount++;
            }

            if (current->leftNode != nullptr) {
                queue.push(current->leftNode);
            }
            if (current->rightNode != nullptr) {
                queue.push(current->rightNode);
            }
        }
        
        std::cout << "[" << leftCount << "," << rightCount << "]";
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
  
	myTree.leftRight(root);
    return 0;
}