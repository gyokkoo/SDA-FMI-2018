#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    // https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {

        std::vector<std::vector<int>> result;
        std::stack<std::vector<int>> stack;
        if (root == nullptr) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            std::vector<int> level;
            size_t queueSize = queue.size();
            for (size_t i = 0; i < queueSize; i++) {
                if (queue.front()->left != nullptr) {
                    queue.push(queue.front()->left);
                }
                if (queue.front()->right != nullptr) {
                    queue.push(queue.front()->right);
                }
                level.push_back(queue.front()->val);
                queue.pop();
            }

            stack.push(level);
        }

        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }

    // https://leetcode.com/problems/same-tree/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        return (isSameTree(p->left, q->left)) && (q->val == p->val) &&
               (isSameTree(p->right, q->right));
    }

    // https://leetcode.com/problems/balanced-binary-tree/
    int treeDepth(TreeNode* root){
        if(root == nullptr) {
            return 0;
        }

        return std::max(treeDepth(root->left), treeDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int difference = std::abs(treeDepth(root->left) - treeDepth(root->right));
        if (difference > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

    // https://leetcode.com/problems/minimum-depth-of-binary-tree/
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMinDepth = minDepth(root->left);
        int rightMinDepth = minDepth(root->right);
        if (leftMinDepth != 0 && rightMinDepth != 0) {
            return std::min(leftMinDepth, rightMinDepth) + 1;
        }

        if (leftMinDepth == 0) {
            return rightMinDepth + 1;
        }

        return leftMinDepth + 1;
    }

    // https://leetcode.com/problems/delete-node-in-a-bst/
    TreeNode* minValueNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* current = root->right;
                delete root;
                return current;
            } else if (root->right == nullptr) {
                TreeNode* current = root->left;
                delete root;
                return current;
            }

            TreeNode* current = minValueNode(root->right);
            root->val = current->val;

            root->right = deleteNode(root->right, current->val);
        }

        return root;
    }

    // https://leetcode.com/problems/path-sum/
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        if (root->val == sum && root->left == nullptr && root->right == nullptr) {
            return true;
        } else if (root->val != sum && root->left == nullptr && root->right == nullptr) {
            return false;
        }

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }

    // https://leetcode.com/problems/invert-binary-tree/
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        this->invertTree(root->left);
        this->invertTree(root->right);
        std::swap(root->left, root->right);
        return root;
    }

    // https://leetcode.com/problems/symmetric-tree/
    bool isSymmetric(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (leftRoot == nullptr && rightRoot == nullptr) {
            return true;
        }
        if (leftRoot == nullptr || rightRoot == nullptr) {
            return false;
        }

        return (leftRoot->val == rightRoot->val) &&
               isSymmetric(leftRoot->left, rightRoot->right) &&
               isSymmetric(leftRoot->right, rightRoot->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }


    // https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
    TreeNode* sortedArrayToBST(std::vector<int>& num) {
        if(num.empty()) {
            return nullptr;
        }
        if(num.size() == 1) {
            return (new TreeNode(num.at(0)));
        }

        TreeNode* root = new TreeNode(num.at(num.size() / 2));
        std::vector<int> leftVector(num.begin(), num.begin() + num.size() / 2);
        std::vector<int> rightVector(num.begin() + num.size() / 2 + 1, num.end());
        root->left = sortedArrayToBST(leftVector);
        root->right = sortedArrayToBST(rightVector);

        return root;
    }

    // https://leetcode.com/problems/sum-of-left-leaves/
    bool isLeaf(TreeNode *node)
    {
        if (node == nullptr)
            return false;
        if (node->left == nullptr && node->right == nullptr)
            return true;
        return false;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) {
            return sum;
        }

        if (isLeaf(root->left)) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }

        sum += sumOfLeftLeaves(root->right);

        return sum;
    }

    // https://leetcode.com/problems/diameter-of-binary-tree/
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = treeDepth(root->left);
        int rightHeight = treeDepth(root->right);

        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        return std::max(
                leftHeight + rightHeight,
                std::max(leftDiameter, rightDiameter));
    }

    // https://leetcode.com/problems/merge-two-binary-trees/
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr) {
            return t1;
        }

        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }

    // https://leetcode.com/problems/binary-tree-inorder-traversal/
    std::vector<int> inOrderTraversal(TreeNode* root) {
        std::vector<int> result;
        if(root == nullptr){
            return result;
        }
        if (root->left != nullptr) {
            std::vector<int> tempVector = inOrderTraversal(root->left);
            result.insert(result.end(),tempVector.begin(),tempVector.end());
        }
        result.push_back(root->val);
        if (root->right != nullptr) {
            std::vector<int> tempVector = inOrderTraversal(root->right);
            result.insert(result.end(),tempVector.begin(),tempVector.end());
        }
        return result;
    }
};


int main() {
    TreeNode* p = new TreeNode(0);
    TreeNode* q = new TreeNode(0);
    Solution s;
    std::cout << s.isSameTree(p, q);

    return 0;
}
