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

  
    int arr[1000000] = {0};

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

    
     int getLevelUtil(Node *node, int data, int level) 
     { 
        if (node == nullptr) 
            return 0; 

        if (node->data == data) 
            return level; 

        int downlevel = getLevelUtil(node->leftNode, data, level+1); 
        if (downlevel != 0) {
            return downlevel;             
        }

        downlevel = getLevelUtil(node->rightNode, data, level+1); 
        return downlevel; 
    } 
    
    int getHeigth(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        
        return std::max(getHeigth(root->leftNode) + 1, getHeigth(root->rightNode) + 1);
    }

     int treeDepth(Node* root){
        if(root == nullptr) {
            return 0;
        }

        return std::max(treeDepth(root->leftNode), treeDepth(root->rightNode)) + 1;
    }
  
    int index = 0;
	void count(Node *root) {
        if (root == nullptr) {
            std::cout << 1;
            return;
        }
        
        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();            
            
            // std::cout << "Height of: " << current->data << " is "<< treeDepth(current) << "\n";
            int level = getLevelUtil(root, current->data, 0);
            // std::cout << "Level is: " << level << " ";
            if (current->leftNode!= nullptr) {
                int height = treeDepth(current->leftNode);
                queue.push(current->leftNode);
                arr[level]++;
            }
            
            if (current->rightNode != nullptr) {
                int height = treeDepth(current->leftNode);
                // std::cout << "Height is  : " << treeDepth(current->rightNode) << "\n";
                queue.push(current->rightNode);
                arr[level]++;
            }
        }
        
        // std::cout << "Output:";
        std::vector<int> result;
        result.push_back(1);
        for (int i = 0; i < 100; i++) {
            if (arr[i] != 0) {
                result.push_back(arr[i]);
            }
        }
        
        for (int i = 0; i < result.size() - 1; i++) {
            std::cout << result[i] << ";";
        }
        std::cout << result[result.size() - 1];
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
  
	myTree.count(root);
    return 0;
}
