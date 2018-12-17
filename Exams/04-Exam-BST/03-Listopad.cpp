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

    
    bool isLeaf(Node* node) {
        if (node->leftNode == nullptr && node->rightNode == nullptr) {
            return true;
        }
        
        return false;
    }

	void leaves(Node *root) {
	
        int sum = 0;
        if (root == nullptr) {
            std::cout << sum;
            return;
        }
        
        std::queue<Node*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();
            
            if (isLeaf(current)) {
                if (current->data % 2 == 1) {
                    sum += current->data;
                }
            }
            
            if (current->leftNode != nullptr) {
                queue.push(current->leftNode);              
            }
                
            if (current->rightNode != nullptr) {
                queue.push(current->rightNode);
            }
        }
        
        std::cout << sum;
        return;
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
  
	myTree.leaves(root);
    return 0;
}